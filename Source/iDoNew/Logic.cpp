 #include "Logic.h"

const string Logic::TASK_FILE_NAME = "task.txt";
const string Logic::FILENAME_ADD_ALTERNATES = "addlist.txt" ;
const string Logic::FILENAME_REMOVE_ALTERNATES = "removelist.txt" ;
const string Logic::FILENAME_EDIT_ALTERNATES = "editlist.txt" ;
const string Logic::FILENAME_EXIT_ALTERNATES  = "exitlist.txt" ;
const string Logic::FILENAME_SEARCH_ALTERNATES = "searchlist.txt" ;
const string Logic::FILENAME_ALTERNATE_ALTERNATES = "altlist.txt" ;
const string Logic::FILENAME_UNDO_ALTERNATES = "undolist.txt" ;
const string Logic::FILENAME_REDO_ALTERNATES = "redolist.txt" ;

//@author A0088645N
Logic::Logic()	{
	fileObj.setFileName(TASK_FILE_NAME);
	fileObj.readList();
	taskList = fileObj.getTaskList();
	while(!undoStack.empty()) {
		undoStack.pop() ;
	}

}


int Logic::logicMain()	{
	updateHomeScreen();
	deleteExpiredTasks();
	while(1) { 
		userInputNewTask = new TimedTask;
		userInputNewTask->setStart(Logic::getCurrentTime());
		userInput = UIObj.getUserInput();
		string cmd = cmdObj.cmdProcessor(userInput, userInputTask, userInputNewTask);
		assert(cmd != "\0") ;
		bool returnVal;
		try {
			returnVal = Logic::execute(cmd,userInputTask, userInputNewTask);
		}
		catch (string except) {
			returnVal=false;
			fileObj.writeErrorLog(except);
			UIObj.printThis(except);
		}
		UIObj.feedback(returnVal,cmd);
	}

	return 0;
}

Logic::CommandType Logic::determineCommand(string cmd) {
	Logic::CommandType type;
	if(cmd == "add") {
		type = ADD;
	}
	else if(cmd == "delete") {
		type = REMOVE;
	}
	else if(cmd == "search") {
		type = SEARCH;
	}
	else if(cmd == "edit") {
		type = EDIT;
	}
	else if(cmd == "undo") {
		type = UNDO;
	}
	else if(cmd == "redo") {
		type = REDO;
	}
	else if(cmd == "alternate") {
		type = ALT ;
	}
	else if(cmd == "exit") {
		type = EXIT;
	}
	else {
		throw string("Command type not determined");
	}
	return type;
}

bool Logic::execute(string cmd,Task* userInputTask, Task* userInputNewTask) throw(string) {

	CommandType type;
	bool returnVal = false ;
	try {
		type = Logic::determineCommand(cmd);
	}
	catch(string except) {
		fileObj.writeErrorLog(except);
		UIObj.printThis(except);
		returnVal = false;
	}
	switch(type) {
		case ADD:
			try	{
				returnVal = addTask(userInputTask);
				updateHomeScreen();
			}
			catch(string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis(except);
				returnVal = false;
			}
			break;
		case REMOVE:
			try {
				returnVal = findToDelete(userInputTask) ;
				updateHomeScreen();
			}
			catch(string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis(except) ;
				returnVal = false ;
			}
			break;
		case EDIT:
			try	{
				returnVal=findToEdit(userInputTask, userInputNewTask);
				updateHomeScreen();
			}
			catch(string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis(except) ;
				returnVal = false ;
			}
			break;
		case SEARCH:
			try {
				returnVal = Logic::search(userInputTask);
			}	
			catch(string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis(except) ;
				returnVal = false ;
			}
			break;
		case UNDO:
			try {
				returnVal = undoTask();
				updateHomeScreen();
			}
			catch(string except) {
				fileObj.writeErrorLog(except);
	   			UIObj.printThis(except) ;
				returnVal = false ;
			}
			break;
		case REDO:
			try {
               returnVal = redoTask();
			   updateHomeScreen();
			}
			catch(string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis(except) ;
				returnVal = false ;
			}
			break;
		case ALT:
			try {
			   returnVal = createAlternateKeyword(userInputTask) ;
			}	
			catch(string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis(except) ;
				returnVal = false ;
			}	
			break ;
		case EXIT:
			exit(0);
		default:
			throw string("Command type not found");
	}
	
	return returnVal;
}
//@author A0088416X
//alternate keyword should be one word only
bool Logic::createAlternateKeyword(Task * userInputTask) throw (string) {

	bool returnVal = true ;
	Task * tempTask = new TimedTask ;
	Task * editTask = new TimedTask ;

	string keyword = cmdObj.cmdProcessor(userInputTask->getDesc(), tempTask, editTask) ;
	CommandType type = determineCommand(keyword);
	string newKeyword ;
	char keywordChar[MAX_KEYWORD_SIZE] ;

	try {
		newKeyword = cmdObj.removeLastSpace(tempTask->getDesc()) ;
		strcpy(keywordChar, newKeyword.c_str()) ;
	} 
	catch (string excption) {
		UIObj.printThis(excption) ;
		returnVal = false ;
		return returnVal ;
	}

	switch(type)
	{
	 case ADD:
		 fileObj.setFileName(Logic::FILENAME_ADD_ALTERNATES) ;
		 try {
			 cmdObj.appendToAddList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break;

	 case REMOVE:
		 fileObj.setFileName(Logic::FILENAME_REMOVE_ALTERNATES) ;
		 try {
			 cmdObj.appendToRemoveList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break;

	 case EDIT:
		 fileObj.setFileName(Logic::FILENAME_EDIT_ALTERNATES) ;
		 try {
			 cmdObj.appendToEditList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break;

	 case SEARCH:
		 fileObj.setFileName(Logic::FILENAME_SEARCH_ALTERNATES) ;
		 try {
			 cmdObj.appendToSearchList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break;

	 case UNDO:
		 fileObj.setFileName(Logic::FILENAME_UNDO_ALTERNATES) ;
		 try {
			 cmdObj.appendToUndoList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break;

	 case REDO:
		 fileObj.setFileName(Logic::FILENAME_REDO_ALTERNATES) ;
		 try {
		 cmdObj.appendToRedoList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break;

	 case ALT:
		 fileObj.setFileName(Logic::FILENAME_ALTERNATE_ALTERNATES) ;
		 try {
			 cmdObj.appendToAltList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break ;

	 case EXIT:
		 fileObj.setFileName(Logic::FILENAME_EXIT_ALTERNATES) ;
		 try {
			 cmdObj.appendToExitList(keywordChar) ;
		 }
		 catch (string except) {
			 UIObj.printThis(except) ;
			 returnVal = false ;
			 return returnVal ;
		 }
		 break ;

	default:
		throw string("Unable to add alternate! Check keyword entered.") ;
		returnVal = false ;
		return returnVal ;
	}
  
	fileObj.writeToFile(newKeyword.c_str()) ;
  
	delete tempTask ;
	return returnVal ;
}
//@author A0088645N
bool Logic::addTask(Task* userInputTask) throw(string) {
	bool returnVal = true;
	if (userInputTask == '\0') {
		throw string("Not a valid task");
	}
	taskList.push_back(userInputTask);
	sortObj.setInputList(taskList);
	taskList = sortObj.executeSort();
	updateTaskFile();
	setSearchObj(userInputTask);
	vector<int> searchResults;
	searchResults = searchObj.getIndices();
	assert ( searchResults.size() >= 1) ;
	if(searchResults.size() > 1) {
		setUndoStack(ADD,userInputTask,-1);
	}
	else {
		setUndoStack(ADD,userInputTask,searchResults[0]);
	}
	searchObj.clearSearchResults();
	return returnVal;
}
//@author A0088416X
bool Logic::isUserIndexValid(int index, vector<int> vectorOfIndices) {

	bool returnVal ;
  
	if(index >= 1 && index <= vectorOfIndices.size() + 1) {
		returnVal = true ;
	}
	else { 
		returnVal = false ;
	}

	return returnVal ;
}
 //@author A0088645N
bool Logic::findToDelete(Task * userInputTask) throw(string) {
	int i;
	assert(userInputTask != '\0');
	vector<int> searchResults;
	bool returnVal = true ;
	setSearchObj(userInputTask);
	searchResults = searchObj.getIndices(); //returns the indices of matches corresponding to MAIN taskList
	vector<Task*> tempList ;
	for(i = 0 ; i < searchResults.size() ; i++) {
		tempList.push_back(taskList[searchResults[i]]);
	}
	if(searchResults.size() == 0) {
		returnVal = false ;
		searchObj.clearSearchResults();
		throw string("No matches found");
	}

	if(searchResults.size() > 1){
	    UIObj.displayHomeScreen(tempList);
	    userInput = UIObj.getUserInput();
        if ( userInput == "\0") {
		    updateTaskFile();
		    searchObj.clearSearchResults();
		    throw string ("Not a valid input");
		    returnVal = false;
  	    }
	    vector<int> userIndex;
	    try {
		    userIndex = cmdObj.intProcessor(userInput);
	    }
	    catch (string except) {
			fileObj.writeErrorLog(except);
		    UIObj.printThis(except);
		    returnVal = false;
	    }
	    for(i = 0; i < userIndex.size() ; i++) {
	            if(isUserIndexValid(userIndex[i],userIndex)) {
					//writes to file description of Tasks being deleted
					string writeToFile = "Deleted task :"+taskList[searchResults[userIndex[i]-1]]->getDesc();
					fileObj.writeInputLog(writeToFile);
	                Logic::deleteTask(searchResults[userIndex[i]-1]) ;
	            }
	            else {
					updateTaskFile();
					searchObj.clearSearchResults();
					throw string("Invalid option chosen.") ;
					returnVal = false;
                }
		}
	}    
    else if(searchResults.size() == 1) {
		Logic::deleteTask(searchResults[0]);
	}
	updateTaskFile();
	searchObj.clearSearchResults();
	return returnVal ;
}

void Logic::deleteTask(int index) {

	assert ( index >= 0 && index <= taskList.size());
	setUndoStack(REMOVE,taskList[index],index);
	delete taskList[index];
	taskList.erase(taskList.begin()+index);
}
	
bool Logic::search(Task* userInputTask) throw(string){
	setSearchObj(userInputTask);
	bool returnVal = true;
	vector<Task*> searchResults = searchObj.getResults();
	if (searchResults.size() == 0) {
		returnVal = false;
		searchObj.clearSearchResults();
		throw string("No matches found");
	}
	UIObj.displayHomeScreen(searchResults);
	searchObj.clearSearchResults();
	return returnVal;
}

bool Logic::findToEdit(Task* userInputTask, Task* userInputNewTask) throw (string) {
	bool returnVal=true;
	if(userInputTask == NULL) {
		returnVal = false;
		throw( " No new description");
	}
	setSearchObj(userInputTask);
	vector<int> searchResults = searchObj.getIndices();
	int i = 0;
	vector<Task*> tempList;
	for(i = 0;i < searchResults.size();i++) {
		tempList.push_back(taskList[searchResults[i]]);
	}
	if (tempList.size() == 0) {
		returnVal=false;
		searchObj.clearSearchResults();
		throw string ("No matching tasks found");
	}
	if(searchResults.size() > 1){
	     
	     UIObj.displayHomeScreen( tempList);
	     userInput = UIObj.getUserInput();
	     if ( userInput == "\0") {
	 		searchObj.clearSearchResults();
			updateTaskFile();
			returnVal=false;
			throw string ( "No user input found");
	     }

	     vector<int> userIndex;
	     try {
			 userIndex = cmdObj.intProcessor(userInput) ;
	     }
	     catch(string except) {
			fileObj.writeErrorLog(except);
			UIObj.printThis(except) ;
			returnVal = false;
	     }
	     assert(userIndex.size() != 0) ;
	     for(i = 0; i < userIndex.size();i++) {
		   if(isUserIndexValid(userIndex[i],searchResults)) {
			   //writes to file description of Tasks being deleted
				string writeToFile = "Edited task :"+taskList[searchResults[userIndex[i]-1]]->getDesc();
			   try {
					Logic::editTask(searchResults[userIndex[i]-1]);
			    }
				catch (string except) {
					fileObj.writeErrorLog(except);
					UIObj.printThis(except);
					returnVal=false;
				}
	           }
	        else { 
		       returnVal=false;
		       updateTaskFile();
		       searchObj.clearSearchResults();
	           throw string("Invalid option chosen.") ;
	        }
	      }
	}	 
	else if(searchResults.size() == 1) {
		Logic::editTask(searchResults[0]);
	}

	updateTaskFile();
	searchObj.clearSearchResults();
	return returnVal;
}

void Logic::editTask(int index) {
	assert ( index < taskList.size() );
	userInputTask = taskList[index];
	cmdObj.descProcessor(userInput,userInputTask);
	if(userInputNewTask->getStart() == NULL ) {
		userInputNewTask->setStart(taskList[index]->getStart());
	}
	 if(userInputNewTask->getEnd() == NULL) {
		userInputNewTask->setEnd(taskList[index]->getEnd());
	 }
	
	setUndoStack(EDIT,taskList[index],index);
	delete taskList[index];
	taskList[index] = userInputNewTask;
}
	
bool Logic::undoTask () throw(string) {
	CommandType undoType;
	bool returnVal = true;
	if(undoStack.size() == 0) {
		throw  string("No commands to undo yet!") ;
		returnVal = false;
	}
	undoType = Logic::undoStack.top().type;
	userInputTask = undoStack.top().taskObj;
	int index = undoStack.top().index;
	Task* newtask = new TimedTask;
	setRedoStack(undoType,userInputTask,index);
	Logic::undoStack.pop();
	switch(undoType) {
		case ADD:
			if(index == -1) {
				throw string("Cannot perform undo multiple matching tasks found. Please use delete option");
				returnVal = false;
			}
			else {
				delete taskList[index];
				taskList.erase(taskList.begin()+index);
			}
				
			updateTaskFile();
			searchObj.clearSearchResults();
			returnVal = true;
			break;
		case REMOVE:
			try {
				returnVal = addTask(userInputTask);
				undoStack.pop();
			}
			catch (string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis( except);
				returnVal=false;
			}
				
			break;
		case EDIT:
			delete taskList[index];
			taskList[index] = userInputTask;
			updateTaskFile();
			searchObj.clearSearchResults();
			returnVal = true;
			break;
		default:
			throw string("Valid task not found");
			returnVal = false;
			
	}
	return returnVal;
}

void Logic::setUndoStack(CommandType type,Task* tempTask,int index) {
	Task* newTask = new TimedTask;
	newTask->setDesc(tempTask->getDesc());
	newTask->setEnd(tempTask->getEnd());
	newTask->setStart(tempTask->getStart());
	userStruct.type = type;
	assert (newTask != NULL);
	userStruct.taskObj = newTask;
	userStruct.index = index;
	undoStack.push(userStruct);
}
void Logic::setRedoStack(CommandType type,Task* tempTask,int index) {
	Task* newTask = new TimedTask;
	newTask->setDesc(tempTask->getDesc());
	newTask->setEnd(tempTask->getEnd());
	newTask->setStart(tempTask->getStart());
	userStruct.type = type;
	assert (newTask != NULL);
	userStruct.taskObj = newTask;
	userStruct.index = index;
	redoStack.push(userStruct);
}

bool Logic::redoTask() throw(string) {
	CommandType redoType;
	bool returnVal = true;
	if(redoStack.size() == 0) {
		returnVal = false;
		throw  string("No undo to redo yet!") ;
	}
	redoType = Logic::redoStack.top().type;
	userInputTask = redoStack.top().taskObj;
	int index = redoStack.top().index;
	Logic::redoStack.pop();
	switch(redoType) {
		case ADD: 
			try {
				returnVal = addTask(userInputTask);
				undoStack.pop();
			}
			catch (string except) {
				fileObj.writeErrorLog(except);
				UIObj.printThis(except);
				returnVal=false;
			}
			break;
		case REMOVE:
			deleteTask(index);
			undoStack.pop();
			updateTaskFile();
			searchObj.clearSearchResults();
			returnVal = true;
			break;
		case EDIT:
			delete taskList[index];
			taskList[index] = userInputTask;
			updateTaskFile();
			searchObj.clearSearchResults();
			returnVal = true;
			break;
		default: 
			returnVal = false;
			throw string (" No valid redo operation found");
	}
	return returnVal;
}

void Logic::deleteExpiredTasks() {
	
	time_t now ;
	time(&now);
	
	struct tm * currentTime = localtime(&now) ;
	struct tm * endTimeFromFile ;
	double timeDiff ;

	fileObj.setFileName("task.txt") ;
	int index = 0 ;
	
	//check end time for both deadlined and timed tasks
	for(index = 0 ; index < taskList.size() ; index++) {
		if(taskList[index]->getEnd() != NULL || (taskList[index]->getEnd() == NULL  && taskList[index]->getStart() != NULL)) {

			if(taskList[index]->getEnd()) {
				endTimeFromFile = taskList[index]->getEnd() ;
			}

			else {
				endTimeFromFile = taskList[index]->getStart() ;
			}

			UIObj.makeConvertible(endTimeFromFile) ;
			time_t endTime = mktime(endTimeFromFile) ;
			
			timeDiff = difftime(now,endTime) ;
			if((timeDiff) > 0.0) {
				delete taskList[index] ;
				taskList.erase(taskList.begin() + index) ;
			}

			else {
				UIObj.changeBackTimePointer(endTimeFromFile) ;
			}
		}
	}
	
	updateTaskFile() ;
}

tm* Logic::getCurrentTime()	{
	time_t now;
	struct tm *current;
	time(&now);
	current = localtime(&now);
	return current;
}

void Logic::updateHomeScreen() throw(string) {
	vector<Task*> introList;
	userInputTask = new TimedTask;
	tm *current = getCurrentTime();
	userInputTask->setStart(current);
	searchObj.setInputList(taskList);
	searchObj.executeSearchTime(userInputTask);
	introList = searchObj.getResults();
	if (introList.size() == 0)
	{
		searchObj.clearSearchResults();
	}
	UIObj.displayHomeScreen(introList);
	searchObj.clearSearchResults();
}

void Logic::updateTaskFile() {
	fileObj.setFileName(TASK_FILE_NAME);
	fileObj.setTaskList(taskList);
	fileObj.writeList();
}

void Logic::setSearchObj( Task* userInputTask) {
	searchObj.setInputList(taskList);
	searchObj.executeSearch(userInputTask->getDesc());
}
