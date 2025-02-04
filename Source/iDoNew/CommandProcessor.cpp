#include "CommandProcessor.h"

const string CommandProcessor::FILENAME_ADD_ALTERNATES = "addlist.txt" ;
const string CommandProcessor::FILENAME_REMOVE_ALTERNATES = "removelist.txt" ;
const string CommandProcessor::FILENAME_EDIT_ALTERNATES = "editlist.txt" ;
const string CommandProcessor::FILENAME_EXIT_ALTERNATES  = "exitlist.txt" ;
const string CommandProcessor::FILENAME_SEARCH_ALTERNATES = "searchlist.txt" ;
const string CommandProcessor::FILENAME_ALTERNATE_ALTERNATES = "altlist.txt" ;
const string CommandProcessor::FILENAME_UNDO_ALTERNATES = "undolist.txt" ;
const string CommandProcessor::FILENAME_REDO_ALTERNATES = "redolist.txt" ;

//@author A0088416X
CommandProcessor::CommandProcessor() {
  //load stored alternates from previous runs
  //into the respective char arrays
	initAddList() ;
	initRemoveList() ;
	initEditList() ;
	initSearchList() ;
	initUndoList() ;
	initExitList() ;
	initRedoList() ;
	initAltList() ; 
}

void CommandProcessor::initAddList() {
	int addIndex = 0 ;
	fileObject.setFileName(FILENAME_ADD_ALTERNATES) ;
	strcpy(addList[addIndex],"add") ;
	addIndex++ ;

	strcpy(addList[addIndex],"ad") ;
	addIndex++ ;
	

	strcpy(addList[addIndex],"add") ;
	addIndex++ ;
	


	vector<string> storedAddList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	it = storedAddList.begin() ;

	for(; it != storedAddList.end() ; it++) {
		strcpy(addList[addIndex],(*(it)).c_str()) ;
		addIndex++ ;
	}

	strcpy(addList[addIndex],"-1") ;
}

void CommandProcessor::initRemoveList() {
	int removeIndex = 0 ;
	int i ;
	fileObject.setFileName(FILENAME_REMOVE_ALTERNATES) ;
	strcpy(removeList[removeIndex],"delete") ;
	removeIndex++ ;
	strcpy(removeList[removeIndex],"delet") ;
	removeIndex++ ;
	strcpy(removeList[removeIndex],"deletee") ;
	removeIndex++ ;
	vector<string> storedRemoveList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	it = storedRemoveList.begin() ;
	
	for(; it != storedRemoveList.end() ; it++) {
		strcpy(removeList[removeIndex],(*(it)).c_str()) ;
		removeIndex++ ;
	}

	strcpy(removeList[removeIndex],"-1") ;
}

void CommandProcessor::initAltList() {
	int altIndex = 0 ;
	fileObject.setFileName(FILENAME_ALTERNATE_ALTERNATES) ;
	strcpy(altList[altIndex],"alternate") ;
	altIndex++ ;
	strcpy(altList[altIndex],"alterntae") ;
	altIndex++ ;
	strcpy(altList[altIndex],"altrnate") ;
	altIndex++ ;
	strcpy(altList[altIndex],"alternat") ;
	altIndex++ ;
	strcpy(altList[altIndex],"alternte") ;
	altIndex++ ;

	vector<string> storedAltList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	
	it = storedAltList.begin() ;
	for(; it != storedAltList.end() ; it++) {
		strcpy(altList[altIndex],(*(it)).c_str()) ;
		altIndex++ ;
	}
  
	strcpy(altList[altIndex],"-1") ;
}

void CommandProcessor::initEditList() {
	int editIndex = 0 ;
	fileObject.setFileName(FILENAME_EDIT_ALTERNATES) ;
	strcpy(editList[editIndex],"edit") ;
	editIndex++ ;
	strcpy(editList[editIndex],"editt") ;
	editIndex++ ;
	strcpy(editList[editIndex],"edt") ;
	editIndex++ ;
	vector<string> storedEditList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	it = storedEditList.begin() ;
	
	for(; it != storedEditList.end() ; it++) {
		strcpy(editList[editIndex],(*(it)).c_str()) ;
		editIndex++ ;
	}

	strcpy(editList[editIndex],"-1") ;
}

void CommandProcessor::initSearchList() {

	int searchIndex = 0 ;
	fileObject.setFileName(FILENAME_SEARCH_ALTERNATES) ;
	strcpy(searchList[searchIndex],"search") ;
	searchIndex++ ;
	strcpy(searchList[searchIndex],"saerch") ;
	searchIndex++ ;
	strcpy(searchList[searchIndex],"serch") ;
	searchIndex++ ;
	strcpy(searchList[searchIndex],"sarch") ;
	searchIndex++ ;
	vector<string> storedSearchList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	it = storedSearchList.begin() ;
	
	for(; it != storedSearchList.end() ; it++) {
		strcpy(searchList[searchIndex],(*(it)).c_str()) ;
		searchIndex++ ;
	}
  
  strcpy(searchList[searchIndex],"-1") ;
}

void CommandProcessor::initUndoList() {
	int undoIndex = 0 ;
	fileObject.setFileName(FILENAME_UNDO_ALTERNATES) ;
	strcpy(undoList[undoIndex],"undo") ;
	undoIndex++ ;
	strcpy(undoList[undoIndex],"undoo") ;
	undoIndex++ ;
	strcpy(undoList[undoIndex],"undo0 ");
	undoIndex++ ;
	vector<string> storedUndoList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	it = storedUndoList.begin() ;
	
	for(; it != storedUndoList.end() ; it++) {
		strcpy(undoList[undoIndex],(*(it)).c_str()) ;
		undoIndex++ ;
	}

  strcpy(undoList[undoIndex],"-1") ;
}

void CommandProcessor::initRedoList() {
	
	int redoIndex = 0 ;
	fileObject.setFileName(FILENAME_REDO_ALTERNATES) ;
	strcpy(redoList[redoIndex],"redo") ;
	redoIndex++ ;
	strcpy(redoList[redoIndex],"redoo") ;
	redoIndex++ ;

	vector<string> storedRedoList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	it = storedRedoList.begin() ;
	
	for(; it != storedRedoList.end() ; it++) {
	  strcpy(redoList[redoIndex],(*(it)).c_str()) ;
	  redoIndex++ ;
	}
	
	strcpy(redoList[redoIndex],"-1") ;
}

void CommandProcessor::initExitList() {
 
	int exitIndex = 0 ;
	fileObject.setFileName(FILENAME_EXIT_ALTERNATES) ;
	strcpy(exitList[exitIndex],"exit") ;
	
	exitIndex++ ;
	vector<string> storedExitList = fileObject.readFromFile() ;
	vector<string>::iterator it ;
	it = storedExitList.begin() ;
	
	for(; it != storedExitList.end() ; it++) {
		strcpy(exitList[exitIndex],(*(it)).c_str()) ;
		exitIndex++ ;
	}

	strcpy(exitList[exitIndex],"-1") ;
}
//@author A0088645N
//For processing the serial numbers of the tasks entered by the user when multiple tasks are to be edited or deleted
vector <int> CommandProcessor::intProcessor (string userInput) throw(string)
{
	if (userInput == "\0") {
		throw("User input not valid");
	}
	vector <int> integers; 
	assert(integers.size() == 0) ;
	int temp = 0;
	for(int i=0;i<userInput.size();i++) {
		if(userInput[i] == ' ') {
			integers.push_back(temp);
			temp = 0;
		}
		else {
			temp = temp*10 + (userInput[i] - ASCII_VALUE_0);
		}
	}
	if(temp != 0){
		integers.push_back(temp);
	}

	if(integers.size() == 0) {
		throw ("User input is not a valid interger");
	}
	return integers;
}
//@author A0088819J
//Processing the initial command entered by the user
string CommandProcessor::cmdProcessor (string userInput, Task*& newTask, Task*& editTask)
{
	int i, j;
	tm* sTime = NULL;
	tm* eTime = NULL;
	editTask = NULL;
	char description[MAX_DESC_SIZE], dateTime[MAX_TIME_SIZE], cmd[MAX_COMMAND_SIZE], singleWord[MAX_WORD_SIZE], modInput[MAX_INPUT_SIZE];
	bool start = false, end = false, checkTime = false;
	strcpy(description, "");
	strcpy(dateTime, "");
	strcpy(cmd, "");
	strcpy(modInput,userInput.c_str());
	CommandProcessor::deleteConsecSpaces(modInput);
	userInput = modInput;
	for(i=0; i < userInput.size() && userInput[i]!= ' ' ; i++)
	{
		cmd[i]=userInput[i];
	}

	cmd[i]='\0';
	
	bool validCmd = CommandProcessor::actualKeyWord(cmd);
	if(validCmd == false) {
			strcpy (description, cmd);
			strcat(description, " ");
			strcpy(cmd, "add");
	}

	if(strcmpi(cmd, "edit") == 0){
		CommandProcessor::editProcessor(userInput, newTask, editTask);
		return cmd;
	}
	
	else if(i==userInput.size()){
			Task *ft = new FloatingTask();
			ft->setDesc(description);
			newTask=ft;
	}
	
	else{
		i++;
		while(i < userInput.size()) {

			for(j = 0; i < userInput.size() && userInput[i] != ' ' ; i++, j++){
				singleWord[j] = userInput[i];
			}
			singleWord[j] = '\0';
			checkTime = isDateTime(singleWord);
			if(checkTime == true && (start == true || end == true)){
				strcat(singleWord, " ");
				strcat(dateTime, singleWord);
				if( i == userInput.size() ){
					CommandProcessor::parseDateTime(dateTime);
						if(start == true){
							sTime = CommandProcessor::stringToTime(dateTime);
							start = false;
						}
						else if(end == true){
							eTime = CommandProcessor::stringToTime(dateTime);
							end = false;
						}
						strcpy(dateTime, "");

				}
			}
			
			else {
				if(isStart(singleWord)){
					start = true;
				}

				else if(isEnd(singleWord)){
					end = true;
				}
			
				else{
					strcat(singleWord, " ");
					strcat(description, singleWord);
				}

				if(strlen(dateTime) > 0){
					CommandProcessor::parseDateTime(dateTime);
						
						if(start == true){
							sTime = CommandProcessor::stringToTime(dateTime);
							start = false;
						}
						
						else if(end == true){
							eTime = CommandProcessor::stringToTime(dateTime);
							end = false;
						}
						
						strcpy(dateTime, "");
				}
				
		}	
		
		i++;

	}

	if(eTime == NULL && sTime == NULL){
		newTask = new FloatingTask(description);
		
	}
	
	else if(sTime == NULL){
		newTask = new DeadlinedTask(description, eTime);
		
	}
	
	else if(eTime == NULL){
		newTask = new TimedTask(description, sTime, NULL);
		
	}
	
	else{
		newTask = new TimedTask(description, sTime, eTime);
	}

	if(newTask ->getStart() != NULL){
		CommandProcessor::correctTaskDate(newTask->getStart());
	}
	if(newTask ->getEnd() != NULL){
		CommandProcessor::correctTaskDate(newTask->getEnd());
	}
	
	
	}
	return cmd ;
}
//Processes the edit command
void CommandProcessor::editProcessor(string userInput, Task*& newTask, Task*&editTask){
	char cmd[MAX_COMMAND_SIZE], description[MAX_INPUT_SIZE], singleWord[MAX_INPUT_SIZE], tempSingleWord[MAX_INPUT_SIZE];
	int i, j;
	newTask = NULL;
	editTask = NULL;
	strcpy(description, "");
	for(i = 0; i < userInput.size() && userInput[i] != ' '; i++);
	i++;
	while(i < userInput.size()){
		for(j = 0; i < userInput.size() && userInput[i] != ' '; i++, j++){
			singleWord[j] = userInput[i];
		}
		
		i++;
		singleWord[j] = '\0';
		
		if(singleWord[0] == '['){
			strcpy(tempSingleWord, singleWord);
			trim(tempSingleWord);
			
			if(strcmpi(tempSingleWord, "new") == 0){
				descProcessor(description, newTask);
				strcpy(description, "");
			}
			
			else{
				strcat(singleWord," ");
				strcat(description, singleWord);
			}
		}
		
		else{
			strcat(singleWord," ");
			strcat(description, singleWord);
		}
	}
		
	if(newTask != NULL){
		descProcessor(description, editTask);
				
	}
	
	else{
		descProcessor(description, newTask);
	}
}
//Processes the description entered by the user for edit and delete
void CommandProcessor::descProcessor (string userInput, Task*& newTask)
{
	int i = 0, j;
	tm* sTime = NULL;
	tm* eTime = NULL;
	char description[MAX_DESC_SIZE], dateTime[MAX_TIME_SIZE], cmd[MAX_COMMAND_SIZE], singleWord[MAX_WORD_SIZE], modInput[MAX_INPUT_SIZE];
	bool start = false, end = false, checkTime;
	strcpy(description, "");
	strcpy(dateTime, "");
	strcpy(cmd, "");
	strcpy(modInput,userInput.c_str());
	CommandProcessor::deleteConsecSpaces(modInput);
	userInput = modInput;

			while(i < userInput.size()){
			
			for(j = 0; i < userInput.size() && userInput[i] != ' ' ;i++, j++){
				singleWord[j] = userInput[i];
			}
			
			singleWord[j] = '\0';
			i++;
			
			
			checkTime = isDateTime(singleWord);
						
			if(checkTime == true && (start == true || end == true)){
				strcat(singleWord, " ");
				strcat(dateTime, singleWord);
				
				if( i == userInput.size()){
					CommandProcessor::parseDateTime(dateTime);
						
						if(start == true){
							sTime = CommandProcessor::stringToTime(dateTime);
							start = false;
						}
						
						else if(end == true){
							eTime = CommandProcessor::stringToTime(dateTime);
							end = false;
						}
						
						strcpy(dateTime, "");

				}
			}
			
			else {
				
				if(isStart(singleWord)){
					start = true;
				}

				else if(isEnd(singleWord)){
					end = true;
				}
			
				else{
					strcat(singleWord, " ");
					strcat(description, singleWord);
				}

				if(strlen(dateTime) > 0){
					CommandProcessor::parseDateTime(dateTime);
						
						if(start == true){
							sTime = CommandProcessor::stringToTime(dateTime);
							start = false;
						}
						
						else if(end == true){
							eTime = CommandProcessor::stringToTime(dateTime);
							end = false;
						}
						
						strcpy(dateTime, "");
				}
				
		}	
		

	}
	
	if(eTime == NULL && sTime == NULL){
		
		if(description[0] == '\0'  && newTask != NULL)
			strcpy(description, newTask->getDesc().c_str());  
		
		if(newTask != NULL){
			sTime = newTask->getStart();
			eTime = newTask->getEnd();
		}
		
		if(eTime == NULL){
			newTask = new FloatingTask(description);
		}
		
		else if(sTime == NULL){
			newTask = new DeadlinedTask(description, eTime);
		}
		
		else{
			newTask = new TimedTask(description, sTime, eTime);
		}

	}
	else if(sTime == NULL){
		
		 if(description[0] == '\0' && newTask != NULL){
			strcpy(description, newTask->getDesc().c_str());
		 }
		 
		 if(newTask != NULL){
			sTime = newTask->getStart();
		}
		
		if(sTime == NULL){
			newTask = new DeadlinedTask(description, eTime);
		}
		
		else{
			newTask = new TimedTask(description, sTime, eTime);
		}
	}
	else if(eTime == NULL){
		
		if(description[0] == '\0' && newTask != NULL)
			strcpy(description, newTask->getDesc().c_str());
		
		if(newTask != NULL){
			eTime = newTask->getEnd();
		}
		
		newTask = new TimedTask(description, sTime, eTime);
		
	}
	
	else{
		
		if(description[0] == '\0' && newTask != NULL)
			strcpy(description, newTask->getDesc().c_str());
		newTask = new TimedTask(description, sTime, eTime);
		
	}

	if(newTask ->getStart() != NULL){
		CommandProcessor::correctTaskDate(newTask->getStart());
	}
	if(newTask ->getEnd() != NULL){
		CommandProcessor::correctTaskDate(newTask->getEnd());
	}
		
}
//Converts a string of the form ddmmyyyyhhmm to a tm structure and returns a pointer to it
tm* CommandProcessor::stringToTime (string startTime)
{
	tm* now = new tm;
	CommandProcessor::setCurrentTime(now);
	tm* sTime = new tm;
	int index = 0;
	int date=(startTime[datemsb]-ASCII_VALUE_0)*10+(startTime[datelsb]-ASCII_VALUE_0);
	int month=(startTime[monthmsb]-ASCII_VALUE_0)*10+(startTime[monthlsb]-ASCII_VALUE_0);
	int year=(startTime[year4]-ASCII_VALUE_0)*1000+(startTime[year3]-ASCII_VALUE_0)*100+(startTime[year2]-ASCII_VALUE_0)*10+(startTime[year1]-ASCII_VALUE_0);

	//daylight savings flag
	sTime->tm_isdst = -1 ;
	//hrs since midnight 0-23
	sTime->tm_hour = 0 ;
	//day of the month 1-31
	sTime->tm_mday = 0;
	//min after the hour 0-61
	sTime->tm_min = 0 ;
	//months since Jan 0-11
	sTime->tm_mon = 0 ;
	//days since Sunday 0-6
	sTime->tm_wday = 0 ;
	//days since Jan 1st 0-365
	sTime->tm_yday = 0 ;
	//years since 1900, 0-2041(not sure of this range...)
	sTime->tm_year = 0 ;
	//seconds after the minute, 0-59
	sTime->tm_sec = 0 ;

	
	if(date != 0) {
		sTime->tm_mday = date;
	}
	
	else {
		sTime->tm_mday = now->tm_mday;
	}
	
	if(month != 0) {
		sTime->tm_mon = month;
	}
	
	else {
		sTime->tm_mon = now->tm_mon;
	}
	
	if(year != 0) {
		sTime->tm_year = year ;
	}
	
	else {
		sTime->tm_year = now->tm_year ;
	}
	
	int hour, min;
	
	if(strlen(startTime.c_str()) > 8) {
		hour = (startTime[8] - ASCII_VALUE_0) * 10 + (startTime[9] - ASCII_VALUE_0);
		min = (startTime[10] - ASCII_VALUE_0) * 10 + (startTime[11] - ASCII_VALUE_0);
	}
	
	else {
		hour = now->tm_hour;
		min = now->tm_min;
	}
	
	sTime->tm_hour = hour;
	sTime->tm_min = min;

	return sTime ;
}
//@author A0088416X
bool CommandProcessor::isFoundAlready(char keywordEntered[MAX_COMMAND_SIZE]) {

	bool isAdd, isRemove, isEdit, isSearch, isExit, isUndo,isRedo, isAlternate ;
	bool returnVal = false ;
	
	isAdd = CommandProcessor::isFound(keywordEntered, "add") ;
	isRemove = CommandProcessor::isFound(keywordEntered, "remove") ;
	isEdit = CommandProcessor::isFound(keywordEntered, "edit");
	isSearch = CommandProcessor::isFound(keywordEntered, "search") ;
	isExit = CommandProcessor::isFound(keywordEntered, "exit");
	isUndo = CommandProcessor::isFound(keywordEntered, "undo");
	isRedo = CommandProcessor::isFound(keywordEntered, "redo");
	isAlternate = CommandProcessor::isFound(keywordEntered, "alternate") ;

	if(isAdd || isRemove || isEdit || isSearch || isExit || isUndo || isRedo || isAlternate) {
		returnVal = true ;
	}

	return returnVal ;

}

void CommandProcessor::appendToAddList(char newKeyword[MAX_COMMAND_SIZE]) {

	int addIndex ; 
	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}

	for (addIndex = 0 ; addIndex < MAX_NO_ALTERNATES ; addIndex++) {
		if(!(strcmp("-1", addList[addIndex]))) {
			strcpy(addList[addIndex], newKeyword) ;
			break ;
		}
	}
	strcpy(addList[addIndex+1], "-1") ;
}

void CommandProcessor::appendToRemoveList(char *newKeyword) {

	int removeIndex ;
	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}
	
	for(removeIndex = 0 ; removeIndex < MAX_NO_ALTERNATES ; removeIndex++) {
		if(!(strcmp("-1", removeList[removeIndex]))) {
			strcpy(removeList[removeIndex], newKeyword) ;
			break ;
		  }
	  }
	strcpy(removeList[removeIndex+1], "-1") ;
}

void CommandProcessor::appendToEditList(char *newKeyword) {
	int editIndex ; 
	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}
	
	for(editIndex = 0 ; editIndex < MAX_NO_ALTERNATES ; editIndex++) {
		if(!(strcmp("-1", editList[editIndex]))) {
			strcpy(editList[editIndex], newKeyword) ;
			break ;
		}
	}
	strcpy(editList[editIndex+1], "-1") ;
}

void CommandProcessor::appendToSearchList(char *newKeyword) {
	  
	int searchIndex ;
	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}
	
	for(searchIndex = 0 ; searchIndex < MAX_NO_ALTERNATES ; searchIndex++) {
		if(!(strcmp("-1", searchList[searchIndex]))) {
			strcpy(searchList[searchIndex], newKeyword) ;
			break ;
		}
	}
	strcpy(searchList[searchIndex+1],"-1") ;
}

void CommandProcessor::appendToUndoList(char *newKeyword) {
	int undoIndex ;
	
	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}
	
	for(undoIndex = 0 ; undoIndex < MAX_NO_ALTERNATES ; undoIndex++) {
		if(!(strcmp("-1", undoList[undoIndex]))) {
			strcpy(undoList[undoIndex], newKeyword) ;
			break ;
		}
	}
	strcpy(undoList[undoIndex+1], "-1") ;
}

void CommandProcessor::appendToRedoList(char *newKeyword) {
	int redoIndex ; 

	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}

	for(redoIndex = 0 ; redoIndex < MAX_NO_ALTERNATES ; redoIndex++) {
		if(!(strcmp("-1", redoList[redoIndex]))) {
			strcpy(redoList[redoIndex], newKeyword) ;
			break ;
		}
	}
	strcpy(redoList[redoIndex + 1], "-1") ;
}

void CommandProcessor::appendToAltList(char *newKeyword) {
	int altIndex ;

	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}

	for(altIndex = 0 ; altIndex < MAX_NO_ALTERNATES ; altIndex++) {
		if(!(strcmp("-1", altList[altIndex]))) {
			strcpy(altList[altIndex], newKeyword) ;
			break ;
		}
	}
	
	strcpy(altList[altIndex + 1], "-1") ;
}

void CommandProcessor::appendToExitList(char *newKeyword) {
	int exitIndex ;

	if(isFoundAlready(newKeyword)) {
		throw string("This keyword is already in use.") ;
	}
	
	for(exitIndex = 0 ; exitIndex < MAX_NO_ALTERNATES ; exitIndex++) {
		if(!(strcmp("-1", exitList[exitIndex]))) {
			strcpy(exitList[exitIndex], newKeyword) ;
			break ;
		}
	}
	strcpy(exitList[exitIndex + 1], "-1") ;
}
//@author A0088819J
//returns the actual keyword in case a synonym/wrong spelling of a keyword is entered
bool CommandProcessor::actualKeyWord(char userCmd[MAX_COMMAND_SIZE]) {

	bool isAdd, isRemove, isEdit, isSearch, isExit, isUndo,isRedo, isAlternate ;
	
	isAdd = CommandProcessor::isFound(userCmd, "add") ;
	isRemove = CommandProcessor::isFound(userCmd, "remove") ;
	isEdit = CommandProcessor::isFound(userCmd, "edit");
	isSearch = CommandProcessor::isFound(userCmd, "search") ;
	isExit = CommandProcessor::isFound(userCmd, "exit");
	isUndo = CommandProcessor::isFound(userCmd, "undo");
	isRedo = CommandProcessor::isFound(userCmd, "redo");
	isAlternate = CommandProcessor::isFound(userCmd, "alternate") ;

	if(isAdd) {
		strcpy(userCmd, "add");
	}
	
	else if(isRemove){
		strcpy(userCmd, "delete");
	}
	
	else if(isEdit){
		strcpy(userCmd, "edit");
	}
	
	else if(isSearch){
		strcpy(userCmd, "search");
	}
	
	else if(isExit){
		strcpy(userCmd, "exit");
	}
	
	else if(isUndo){
		strcpy(userCmd, "undo");
	}
	
	else if(isRedo){
		strcpy(userCmd, "redo");
	}
	else if(isAlternate){
		strcpy(userCmd, "alternate") ;
	}
	
	if(isAdd == false && isRemove == false && isEdit == false && isSearch == false && isExit == false && isUndo == false && isRedo==false && isAlternate == false){
		return false;
	}
	
	else {
		return true;
	}
}
//@author A0088416X
bool CommandProcessor::isFound(char cmd[MAX_COMMAND_SIZE], string cmdType) {
	int index = 0;
	bool returnVal= false ;

	if(cmdType == "add") {
		while(strcmpi("-1", addList[index]) != 0) {
			if(strcmpi(cmd, addList[index]) == 0) {
				returnVal = true ;
			}
			index++;
		}
	}

	else if(cmdType == "remove") {
		while(strcmpi("-1", removeList[index]) != 0) {
			if(strcmpi(cmd, removeList[index]) == 0) {
				returnVal = true;
			}
			index++;
		}
	}
	
	else if(cmdType == "edit") {
		while(strcmpi("-1", editList[index]) != 0) {
			if(strcmpi(cmd, editList[index]) == 0) {
				returnVal = true ;
			}
			index++;
		}
	}

	else if(cmdType == "search") {
		while(strcmpi("-1", searchList[index]) != 0) {
			if(strcmpi(cmd, searchList[index]) == 0) {
				returnVal = true;
			}
			index++;
		}
	}

	else if(cmdType == "exit") {
		while(strcmpi("-1", exitList[index]) != 0) {
			if(strcmpi(cmd, exitList[index]) == 0) {
				returnVal = true ;
			}
			index++;
		}

	}
	else if(cmdType == "undo") {
		while(strcmpi("-1", undoList[index]) != 0) {
			if(strcmpi(cmd, undoList[index]) == 0) {
				returnVal = true ;
			}
			index++;
		}
	}

	else if(cmdType == "redo") {
		while(strcmpi("-1", redoList[index]) != 0) {
			if(strcmpi(cmd, redoList[index]) == 0) {
				returnVal = true;
			}
			index++;
		}
	}

	else if(cmdType == "alternate") {
		while(strcmpi("-1", altList[index]) != 0) {
			if(strcmpi(cmd, altList[index]) == 0) {
				returnVal = true;
			}
			index++;
		}
	}

	else {
		returnVal = false ;
	}

	return returnVal ;
}
//@author A0088819J
//checks if the string cmd is found in cmdList
bool CommandProcessor::isFound(char cmd[MAX_COMMAND_SIZE], const char cmdList[][MAX_COMMAND_SIZE]) {

	int i = 0 ;

	while(strcmpi("-1", cmdList[i]) != 0) {
		
		if(strcmpi(cmd, cmdList[i]) == 0){
			return true;
		}
		
		i++;
	}

	return false ;
}

//checks if a particualr word indicates start time

bool CommandProcessor::isStart(char singleWord[MAX_WORD_SIZE]){
	
    return CommandProcessor::isFound(singleWord, startList);

}
//checks if a particualr word indicates end time
bool CommandProcessor::isEnd(char singleWord[MAX_WORD_SIZE]){
	
	return CommandProcessor::isFound(singleWord, endList);

}
//trims a word that starts with '[' and ends with ']'
void CommandProcessor::trim(char word[MAX_COMMAND_SIZE]){
	char trimmed[MAX_COMMAND_SIZE];
	int i;
	
	for( i = 0;  word[i + 1] != ']'; i++){
		trimmed[i] = word[i + 1];
	}
	
	trimmed[i] = '\0';
	strcpy(word, trimmed);
}
//Checks if a single word is a time related word
bool CommandProcessor::isDateTime(char singleWord[MAX_WORD_SIZE]){
	
	bool time = isFound(singleWord, timeList);
	
	if(time == true){
		return time;
	}
	
	else{
		time = isNumericalTime(singleWord);
	}
	
	return time;
}
//checks if a single word is a numerical time like 30.08.1993 or 7:30 
bool CommandProcessor::isNumericalTime(char singleWord[MAX_COMMAND_SIZE]){
	int first = -1, second = -1, third = -1;
	bool returnVal = false;
	CommandProcessor::splitTime(singleWord, first, second, third);

	returnVal = CommandProcessor::isDate(first, second, third);
	
	if(returnVal == false){
		returnVal = CommandProcessor::isTime(first, second, third);
	}
	
	return returnVal;
}
//Checks if a number is a valid day of the month	
bool CommandProcessor::isDay(int input){
	if(input >=1 && input <= 31){
		return true;
	}
	
	else{
		return false;
	}
}
//Checks if a number is a valid month of the year
bool CommandProcessor::isMonth(int input){
	
	if(input >=1 && input <= 12){
		return true;
	}
	
	else {
		return false;
	}
}
//checks if a number is a valid year
bool CommandProcessor::isYear(int input){
	
	if(input > 0 && input < 100){
		return true;
	}
	
	else if(input > 1000){
		return true;
	}
	
	else{
		return false;
	}
}
//checks if a number is a valid hour in a day
bool CommandProcessor::isHour(int input){
	
	if(input >= 0 && input <= 24){
		return true;
	}
	
	else {
		return false;
	}
}
//checks if a number is a valid minute in an hour
bool CommandProcessor::isMinute(int input){
	
	if(input >= 0 && input <= 60){
		return true;
	}
	else {
		return false;
	}
}
//Parses a string consisting of the entire date and time
bool CommandProcessor::parseDateTime(char dateTime[MAX_TIME_SIZE]){
	char singleWord[MAX_TIME_SIZE], finalTime[MAX_TIME_SIZE], temp[MAX_WORD_SIZE];
	bool time = false, date = false;
	int next = 0;
	strcpy(finalTime, "");
	int i = 0, j, tempTime = 0, first = -1, second = -1, third = -1;

	while(i < strlen(dateTime)){
		first = second = third = -1;
		
		for(j = 0; i < strlen(dateTime) && dateTime[i] != ' '; i++, j++){
			singleWord[j] = dateTime[i];
		}
		
		singleWord[j] = '\0';
		i++;
		bool isNumeric = CommandProcessor::isNumericalTime(singleWord);
		
		if(isNumeric == true){
			CommandProcessor::splitTime(singleWord, first, second, third);
			time = isTime(first, second, third);
			date = isDate(first, second, third);
			char *posth = strstr(dateTime, " th"), *posst = strstr(dateTime, " st"), *posnd = strstr(dateTime, " nd"), *posrd = strstr(dateTime, " rd");
			
			if(posth != NULL){
				CommandProcessor::setDateTimeBool(date, time, dateTime, posth);			
			}
			
			else if(posnd != NULL){
				CommandProcessor::setDateTimeBool(date, time, dateTime, posnd);			
			}
			
			else if(posst != NULL){
				CommandProcessor::setDateTimeBool(date, time, dateTime, posst);
			}
			
			else if(posrd != NULL){
				CommandProcessor::setDateTimeBool(date, time, dateTime, posrd);
			}
			
			if(time == true && date == true){
				
				if(i >= (strlen(dateTime) - 3)){
					CommandProcessor::addZeroes(singleWord);
					CommandProcessor::convertTime(singleWord);
					
					if(strlen(finalTime) == 0){
						strcat(finalTime, "00000000");
					}
					
					finalTime[8] = '\0';
					strcat(finalTime, singleWord);
				}
			
				else{
					CommandProcessor::addZeroes(singleWord);
					CommandProcessor::convertDate(singleWord);
					strcat(finalTime, singleWord);
				}
			}
			
			else if(time == true){
				CommandProcessor::addZeroes(singleWord);
				CommandProcessor::convertTime(singleWord);
				if(strlen(finalTime) == 0){
						strcat(finalTime, "00000000");
				}
				
				finalTime[8] = '\0';
				strcat(finalTime, singleWord);
			}
			
			else if(date == true){
				CommandProcessor::addZeroes(singleWord);
				CommandProcessor::convertDate(singleWord);
				strcat(finalTime, singleWord);
			}
		}
		
		else if(strcmpi(singleWord, "pm") != 0){
			CommandProcessor::parseCharTime(singleWord, finalTime);
		}
		
		else{	
			
			if(strlen(finalTime) != 0){
					
					int hours = (finalTime[hours_msb] - ASCII_VALUE_0)*10 + (finalTime[hours_lsb] - ASCII_VALUE_0);
					int min = (finalTime[min_msb] - ASCII_VALUE_0)*10 + (finalTime[min_lsb] - ASCII_VALUE_0);
					if(hours <= 12){
						finalTime[hours_msb] = '\0';
						hours += 12;
						itoa(hours, temp, 10);
						strcat(finalTime, temp);
				
						if(min <10){
							strcat(finalTime, "0");
						}
						
						itoa(min, temp, 10);
						strcat(finalTime, temp);
					}
			
			}
		}
	}
			
	if(strlen(finalTime) == date_size){
		strcat(finalTime, "0000");
	}
	
	strcpy(dateTime, finalTime);
	
	return true;
}
//sets date or time as true or false according to the input pos
void CommandProcessor::setDateTimeBool(bool &date, bool & time, char dateTime[MAX_TIME_SIZE], char *pos){
	
	char *tmp;
	date = true;
	time = false;
	tmp = pos + 2;
	*(pos - 1) = '\0';
	strcat(dateTime, tmp);
}
//Converts a date of any numerical form to ddmmyyyy
void CommandProcessor::convertDate(char Date[MAX_TIME_SIZE]){
	
	int j = 0, k = 0,  year, month;
	char tempTime[MAX_TIME_SIZE], temp[MAX_TIME_SIZE];
	strcpy(tempTime, "");
	strcpy(temp, "");
	strcpy(tempTime, Date);
	tm* curr = new tm;
	CommandProcessor::setCurrentTime(curr);
	//when date is dd/mm/yy
	if(strlen(tempTime) == 6){
		year = (tempTime[4] - 48)*10 + (tempTime[5] - 48);
		
		if(year >= 90){
			year = 1900 + year;
		}
		
		else{
			year = 2000 + year;
		}
		
		tempTime[4] = '\0';
		itoa(year, temp, 10);
		strcat(tempTime, temp);
	}
	//dd/mm
	else if(strlen(tempTime) == 4){
		year = curr->tm_year;
		itoa(year, temp, 10);
		strcat(tempTime, temp);
	}
	//dd
	else if(strlen(tempTime) == 2)
	{
		month = curr->tm_mon;
		itoa(month, temp, 10);
		strcat(tempTime, temp);
		year = curr->tm_year ;
		itoa(year, temp, 10);
		strcat(tempTime, temp);
	}
	strcpy(Date, tempTime);
}

//converts time of any numerical form to hhmm
void CommandProcessor::convertTime(char Date[MAX_TIME_SIZE]){
	int j = 0, k = 0,  year;
	char tempTime[MAX_TIME_SIZE];
	
	for(j = 0; j < strlen(Date); j++){
		
		if(isalnum(Date[j]) && !(isalpha(Date[j]))){
		tempTime[j] = Date[j];
		}
	}
	tempTime[j] = '\0';
	
	if(strlen(tempTime) == 2){
		strcat(tempTime, "00");
	}
	
	strcpy(Date, tempTime);
}
//adds zeroes to incomplete time strings like d/m/yy
void CommandProcessor::addZeroes(char input[MAX_TIME_SIZE]){
	char newDate[MAX_TIME_SIZE], tempDate[MAX_TIME_SIZE];
	strcpy(newDate, "");
	int i = 0, j = 0;
	int buffer;
	
	while(i < strlen(input)){
		buffer = 0;
		
		for(; ( isalnum(input[i]) && !isalpha(input[i]) ) &&(i < strlen(input)); i++){
			buffer = buffer * 10 + (input[i] - 48) ;
		}
		
		i++;
			
			if(buffer < 10){
				newDate[j] = '0';
				j++;
				newDate[j] = buffer + 48;
				j++;
				newDate[j] = '\0';
			}
			
			else{
				itoa(buffer, tempDate, 10);
				strcat(newDate, tempDate);
				j += 2;
			}
	}
	
	strcpy(input, newDate);
}
//@author A0088416X
string CommandProcessor::removeLastSpace(string word) throw(string) {
	string tempWord ;

	if(word.size() == 0) {
		throw string("Invalid/no alternative keyword entered.") ;
	}

	int lastLetterIndex = word.size()-1 ;
	
	if(word[lastLetterIndex] == ' ') {
	  tempWord = word.substr(0,lastLetterIndex) ;
	  word = tempWord ;
	}
	return word ;  
}
//@author A0088819J
//checks if first, second and third form a date
bool CommandProcessor::isDate(int first, int second, int third ){
	bool returnVal = false;
	
	if(third == -1 && second == -1){
			
			if(isDay(first) == true || isYear(first) ==  true){
				returnVal = true;
			}
			
			else{
				returnVal = false;
			}
	}
	
	else if(third == -1){
		
		if(isDay(first) == true && isMonth(second)){
				returnVal = true;
			}
			
		else{
				returnVal = false;
			}
		}
		
	else{
		
		if(isDay(first) == true && isMonth(second) == true && isYear(third) == true){
			returnVal = true;
		}
			
		else{
				returnVal = false;
		}
	}
		
	return returnVal;
}

//checks if first, second and third form a time
bool CommandProcessor::isTime(int first, int second, int third ){
	bool returnVal = false;
	if(third == -1){
		
		if(second == -1){
			
			if(isHour(first) == true){
				returnVal = true;
			}
		}
		
		else{
			
			if(isHour(first) == true && isMinute(second) == true){
				returnVal = true;
			}
		}
	}
		else{
			returnVal = false;
		}

	return returnVal;
}

//splits a date string to 3 or 2 or 1 entity(ies) depending upon the in put like in dd/mm/yyyy first second ans third will store date, month and year respectively
void CommandProcessor::splitTime(char singleWord[MAX_COMMAND_SIZE], int &first, int &second, int&third){
	int buffer, i;
	buffer = 0;
	i = 0;
	
	while(isalnum(singleWord[i]) && !isalpha(singleWord[i])  && i < strlen(singleWord)){
		buffer = buffer * 10 + (singleWord[i] - 48);
		i++;
	}
	
	if(i <= strlen(singleWord)){
		first = buffer;
	}
	
	i++;
	
	if(i < strlen(singleWord)){
		buffer = 0;
		
		while(isalnum(singleWord[i]) && !isalpha(singleWord[i])  && i < strlen(singleWord)){
			buffer = buffer * 10 + (singleWord[i] - 48);
			i++;
		}
	}
	
	if(i <= strlen(singleWord)){
		second = buffer;
	}
	
	i++;
	
	if(i < strlen(singleWord)){
		buffer = 0;
		
		while(isalnum(singleWord[i]) && !isalpha(singleWord[i])  && i < strlen(singleWord)){
			buffer = buffer * 10 + (singleWord[i] - 48);
			i++;
		}
	}

	if(i <= strlen(singleWord)){
		third = buffer;
	}
}

//parses a character based time like sunday or next month
void CommandProcessor::parseCharTime(char singleWord[MAX_WORD_SIZE], char finalTime[MAX_TIME_SIZE]){
	tm *now = new tm;
	CommandProcessor::setCurrentTime(now);
	tm dateTime = *now;
	static int no_next = 0, day = 0, after = 0, tomorrow = 0;
	int wday = now->tm_wday;
	
	if(strlen(finalTime) != 0){
		dateTime = *CommandProcessor::stringToTime(finalTime);
		dateTime.tm_wday = wday;
	}
	
	bool isDay, isMonth;
	char tmp[MAX_TIME_SIZE];
	
	if(strlen(finalTime) == 0){
				
		CommandProcessor::dateToString(now, finalTime);
		
	}
		isMonth = isFound(singleWord, monthList);
		isDay = isFound(singleWord, days);
		
		if(isDay ==  true){
			CommandProcessor::incrementDate(&dateTime, (no_next)*7);
			strcpy(finalTime, "");
			CommandProcessor::dateToString(&dateTime, finalTime);
			dateTime = evaluateDate(singleWord, finalTime);
			no_next = 0;
		}
		
		else if(isMonth == true){
			if(no_next != 0){
				CommandProcessor::incrementYear(&dateTime, (no_next ));
				dateTime.tm_mday = 1;
			}
			
			strcpy(finalTime, "");
			CommandProcessor::dateToString(&dateTime, finalTime);
			dateTime = evaluateMonth(singleWord, finalTime);
			no_next = 0;
		}
		
		else if(strcmpi(singleWord, "day") == 0){
			day = 1;
		}
		
		else if(strcmpi(singleWord, "after") == 0){
			after = 1;
		}
		
		else if(strcmpi(singleWord, "tomorrow") == 0){
			tomorrow = 1;
		}
		
		else if(strcmpi(singleWord, "now") == 0){
			dateTime = *now;
			CommandProcessor::dateToString(&dateTime, finalTime);
		}
		
		else if(strcmpi(singleWord, "week") == 0){
			CommandProcessor::incrementDate(&dateTime, no_next*7);
			strcpy(finalTime, "");
			CommandProcessor::dateToString(&dateTime, finalTime);
			no_next = 0;
		}
		
		else if(strcmpi(singleWord, "month") == 0){
			CommandProcessor::incrementMonth(&dateTime, no_next);
			dateTime.tm_mday = 1;
			strcpy(finalTime, "");
			while(dateTime.tm_mon > 12){
				dateTime.tm_year += dateTime.tm_mon / 13;		
				dateTime.tm_mon -= 12;
			}
			CommandProcessor::dateToString(&dateTime, finalTime);
			no_next = 0;
		}
		
		else if(strcmpi(singleWord, "year") == 0){
			CommandProcessor::incrementYear(&dateTime, no_next);
			strcpy(finalTime, "");
			CommandProcessor::dateToString(&dateTime, finalTime);
			no_next = 0;
		}
		
		else{
			
			if(strcmpi(singleWord, "next") == 0){
				no_next++;
			}
		}
		
		if(day == 1 && after == 1 && tomorrow == 1){
			dateTime = *now;
			
			if(no_next != 0){
				CommandProcessor::incrementDate(&dateTime, 2 + (no_next ));
				no_next = 0;
			}
			
			else{
			CommandProcessor::incrementDate(&dateTime, 2);
			}
			
			CommandProcessor::dateToString(&dateTime, finalTime);
			day = after = tomorrow = 0;

		}
		
		else if(tomorrow == 1){
			dateTime = *now;
			
			if(no_next != 0){
				CommandProcessor::incrementDate(&dateTime, 1 + (no_next ));
				no_next = 0;
			}
			
			else{
				CommandProcessor::incrementDate(&dateTime, 1 );
			}
			
			CommandProcessor::dateToString(&dateTime, finalTime);
			tomorrow = 0;
		}
		
		strcpy(finalTime, "");
		CommandProcessor::dateToString(&dateTime, finalTime);
}

//evaluates the Date according to the value in day and returns the time structure corresponding to the date
tm CommandProcessor::evaluateDate(char day[MAX_TIME_SIZE], char finalTime[MAX_TIME_SIZE]){
	tm* returnTime = new tm ;
	CommandProcessor::setCurrentTime(returnTime);
	int wday = returnTime->tm_wday;
	
	if(strlen(finalTime) != 0){
		returnTime = CommandProcessor::stringToTime(finalTime);
		returnTime->tm_wday = wday;
	}
	
	int days;
	bool isMonday = !(bool)(strcmpi(day, "monday") );
	bool isTuesday = !(bool)(strcmpi(day, "tuesday"));
	bool isWednesday = !(bool)(strcmpi(day, "wednesday"));
	bool isThursday = !(bool)(strcmpi(day, "thursday"));
	bool isFriday = !(bool)(strcmpi(day, "friday"));
	bool isSaturday = !(bool)(strcmpi(day, "saturday"));
	bool isSunday = !(bool)(strcmpi(day, "sunday"));
	
	const int monday = 1, tuesday = 2, wednesday = 3, thursday = 4, friday = 5, saturday = 6, sunday = 0, totalDays = 7;
	if(isMonday){
		
		if(returnTime->tm_wday > monday){
			days = totalDays - (returnTime->tm_wday - monday) ;
		}
		
		else{
			days = monday - returnTime->tm_wday;
		}
	}
	
	if(isTuesday){
		
		if(returnTime->tm_wday > tuesday){
			days = totalDays - (returnTime->tm_wday - tuesday) ;
		}
		
		else{
			days = tuesday - returnTime->tm_wday;
		}
	}
	
	if(isWednesday){
		
		if(returnTime->tm_wday > wednesday){
			days = totalDays - ( returnTime->tm_wday - wednesday) ;
		}
		
		else{
			days = wednesday - returnTime->tm_wday;
		}
	}
	
	if(isThursday){
		
		if(returnTime->tm_wday > thursday){
			days = totalDays - ( returnTime->tm_wday - thursday) ;
		}
		
		else{
			days = thursday - returnTime->tm_wday;
		}
	}

	if(isFriday){
		
		if(returnTime->tm_wday > 5){
			days = totalDays - ( returnTime->tm_wday - friday) ;
		}
		
		else{
			days = friday - returnTime->tm_wday;
		}
	}
	
	if(isSaturday){
		
		if(returnTime->tm_wday > 6){
			days = totalDays - ( returnTime->tm_wday - saturday) ;
		}
		
		else{
			days = saturday - returnTime->tm_wday;
		}
	}
	
	if(isSunday){
		
		if(returnTime->tm_wday > 0){
			days = totalDays - ( returnTime->tm_wday - sunday) ;
		}
		
		else{
			days = sunday;
		}
	}
	
	CommandProcessor::incrementDate(returnTime, days);

	return *returnTime;
}

//increments the Date by the number of days specified
void CommandProcessor::incrementDate(tm *date, int days){

	bool isLeap;
	switch(date->tm_mon){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		date->tm_mon += (date->tm_mday + days) / 32;
		date->tm_mday = (date->tm_mday + days) % 32;
		
		break;
	
	case 2:
		isLeap = CommandProcessor::isLeapYear(date->tm_yday);
		
		if(isLeap == true){
			date->tm_mon += (date->tm_mday + days) / 30;
			date->tm_mday = (date->tm_mday + days) % 30;
		}
		
		else{
			date->tm_mon += (date->tm_mday + days) / 29;
			date->tm_mday = (date->tm_mday + days) % 29;
		}
		
		break;
	
	default:
		date->tm_mon += (date->tm_mday + days) / 31;
		date->tm_mday = (date->tm_mday + days) % 31;
		
		break;
	}
	date->tm_year += date->tm_mon / 13;
	
}

//increments the month by the number of months specified
void CommandProcessor::incrementMonth(tm *date, int months){
	date->tm_mon += months;
	while(date->tm_mon > 12){
				date->tm_year += date->tm_mon / 13;		
				date->tm_mon -= 12;
			}
	
}

//increments the year by the number of years specified
void CommandProcessor::incrementYear(tm *date, int years){
	date->tm_year += years;
}

//checks if a year s a leap year
bool CommandProcessor::isLeapYear(int year){
	
	if(((year % 100) == 0) && ((year % 400) == 0)){
		return true;
	}
	
	else if((year % 100) == 0){
		return false;
	}
	
	else if((year % 4) == 0){
		return true;
	}
	
	else {
		return false;
	}
}

//converts a date specified by the tm structuure date to a string of the form ddmmyyyyhhmm
void CommandProcessor::dateToString(tm* date, char finalDate[MAX_TIME_SIZE]){

	char tmp[MAX_TIME_SIZE];
	if(date->tm_mday < 10){
		strcat(finalDate, "0");
	}
	
	itoa(date->tm_mday,tmp , 10);
	strcat(finalDate, tmp);

	if(date->tm_mon < 10){
		strcat(finalDate, "0");
	}
	
	itoa(date->tm_mon ,tmp , 10);
	strcat(finalDate, tmp);

	if(date->tm_year < 10){
		strcat(finalDate, "0");
	}
	
	itoa(date->tm_year ,tmp , 10);
	strcat(finalDate, tmp);

	if(date->tm_hour < 10){
		strcat(finalDate, "0");
	}
	
	itoa(date->tm_hour,tmp , 10);
	strcat(finalDate, tmp);

	if(date->tm_min < 10){
		strcat(finalDate, "0");
	}
	
	itoa(date->tm_min,tmp , 10);
	strcat(finalDate, tmp);
}

//deletes consecutive spaces in the input
void CommandProcessor::deleteConsecSpaces(char input[MAX_INPUT_SIZE]){
	int i, j;
	for(i = 0; i < strlen(input); i++){
		
		if(input[i] == ' ' && input[i + 1] == ' '){
			
			for(j = i; j < strlen(input); j++){
				input[j] = input[j + 1];
			}
			i--;
		}
	}
}

//evaluates the date according to the value in month and returns the time structure corresponding to the date
tm CommandProcessor::evaluateMonth(char month[MAX_TIME_SIZE], char finalTime[MAX_TIME_SIZE]){
	tm* returnTime ,*now = new tm;
	CommandProcessor::setCurrentTime(now);
	now->tm_mday = 1;
	int wday = now->tm_wday;
	
	if(strlen(finalTime) != 0){
		returnTime = CommandProcessor::stringToTime(finalTime);
		returnTime->tm_wday = wday;
	}
	
	else{
		returnTime = now;
	}
	
	
	bool isJan = !(bool)(strcmpi(month, "January") );
	bool isFeb = !(bool)(strcmpi(month, "February"));
	bool isMar = !(bool)(strcmpi(month, "March"));
	bool isApr = !(bool)(strcmpi(month, "April"));
	bool isMay = !(bool)(strcmpi(month, "May"));
	bool isJun = !(bool)(strcmpi(month, "June"));
	bool isJul = !(bool)(strcmpi(month, "July"));
	bool isAug = !(bool)(strcmpi(month, "August"));
	bool isSep = !(bool)(strcmpi(month, "September"));
	bool isOct = !(bool)(strcmpi(month, "October"));
	bool isNov = !(bool)(strcmpi(month, "November"));
	bool isDec = !(bool)(strcmpi(month, "December"));
	
	if(isJan == true){
		returnTime->tm_year++;
		returnTime->tm_mon = jan;
	}
	
	else if(isFeb == true){
		returnTime->tm_mon = feb;
		
		if((now->tm_mon > feb) || (now ->tm_mon == feb && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isMar == true){
		returnTime->tm_mon = mar;
		
		if((now->tm_mon > mar) || (now ->tm_mon == mar && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
		
	}
	
	else if(isApr == true){
		returnTime->tm_mon = apr;
		
		if((now->tm_mon > apr) || (now ->tm_mon == apr && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isMay == true){
		returnTime->tm_mon = may;
		
		if((now->tm_mon > may) || (now ->tm_mon == may && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isJun == true){
		returnTime->tm_mon = june;
		
		if((now->tm_mon > june) || (now ->tm_mon == june && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isJul == true){
		returnTime->tm_mon = july;
		
		if((now->tm_mon > july) || (now ->tm_mon == july && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isAug == true){
		returnTime->tm_mon = aug;
		
		if((now->tm_mon > aug) || (now ->tm_mon == aug && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isSep == true){
		returnTime->tm_mon = sep;
		
		if((now->tm_mon > sep) || (now ->tm_mon == sep && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isOct == true){
		returnTime->tm_mon = octo;
	
		if((now->tm_mon > octo) || (now ->tm_mon == octo && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isNov == true){
		returnTime->tm_mon = novem;
		
		if((now->tm_mon > novem) || (now ->tm_mon == novem && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	
	else if(isDec == true){
		returnTime->tm_mon = decem;
		
		if((now->tm_mon > decem) || (now ->tm_mon == decem && now->tm_mday > returnTime->tm_mday)){
			returnTime->tm_year++;			
		}
	}
	while(returnTime->tm_mon > 12){
				returnTime->tm_year += returnTime->tm_mon / 13;		
				returnTime->tm_mon -= 12;
			}
	
	return *returnTime;
}

//sets the current time into now
void CommandProcessor::setCurrentTime(tm * now){
	time_t curr;
	time(&curr);
	tm* currtime = localtime(&curr);
	*now = *currtime;
	now->tm_mon++;
	now->tm_year += 1900;

}

//Validates and corrects date. e.g. feb 30 is invalid
void CommandProcessor::correctTaskDate(tm *t){
	
	switch(t->tm_mon){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		if(t->tm_mday > 31){
			t->tm_mday = 31;
		}

		break;
	case 2: 
		if(CommandProcessor::isLeapYear(t->tm_year)){
			if(t ->tm_mday > 29){
				t->tm_mday = 29;
			}
		}
		else{
			if(t ->tm_mday > 28){
				t->tm_mday = 28;
			}

		}
		break;
	default: 
		if(t->tm_mday > 30){
			t->tm_mday = 30;
		}
		break;
	}

}