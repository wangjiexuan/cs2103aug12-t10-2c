//User Interface class
//Has function(s) to get input from user and pass it on to internal components, if called by those components
//Has function(s) to display appropriate feedback to user depending on direction received from internal components

#ifndef UI_H_
#define UI_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <time.h>
#include "Task.h" 

using namespace std ;

class UI
{
 
private:
	
	string userInput ;

	void placeCursorAt(const int, const int) ;

	int displayTimedTask(tm * &, tm * &, string) ;
	int displayDeadlineTask(tm * &, string) ;
	int displayFloatingTask(string) ;

	void goToNextLineBeginning(int) ;
	void goToDescriptionBeginning() ;
	void goToFromBeginning() ;
	void goToToBeginning() ;
	int printDescription(string) ;

	COORD currentCursor ;

	static const int MAX_DESCRIPTION_SIZE = 36 ;

	static const int TABLE_START_POSITION_X = 2 ;
	static const int TABLE_START_POSITION_Y = 4 ;
	static const string TABLE_FIELDS ;

	static const string MESSAGE_TODAY ;
	static const string MESSAGE_NEXT_COMMAND ;
	static const string MESSAGE_WELCOME ; 
	static const string MESSAGE_HELP ;
	static const string MESSAGE_INVALID ;

	static const string MESSAGE_ALTERNATE_SUCCESS ; 
	static const string MESSAGE_ALTERNATE_FAIL ;

	static const string MESSAGE_ADDED ;
	static const string MESSAGE_INVALID_ADD ;

	static const string MESSAGE_DELETED ;
	static const string MESSAGE_INVALID_DELETE ;

	static const string MESSAGE_EDITED ;
	static const string MESSAGE_INVALID_EDIT ;

	static const string MESSAGE_SEARCH_SUCCESS ;
	static const string MESSAGE_INVALID_SEARCH ;

	static const string MESSAGE_EXIT ;
	static const string MESSAGE_UNDONE ;
	static const string MESSAGE_UNDO_FAIL ;

	static const string UI::MESSAGE_REDO;
	static const string UI::MESSAGE_REDO_FAIL;
	static const string UI::MESSAGE_NO_TASK;
 public:

	void displayHomeScreen(vector<Task*>) ; 

	//so that the tm pointer is compatible with the asctime() function of time.h library
	//asctime() converts to string
	void makeConvertible(tm * timePointer) ;

	//so that any changes made to make tm pointer compatible with asctime() do not affect any internal functioning... 
	//...where the tm pointer is used
	void changeBackTimePointer(tm *) ;

	string convertToString(char * char_Array) ;

	//remove endl at the end, and the day of the week from the beginning for display
	//also remove seconds counter from display 
	string makePrintableTimeString(char *) ;

	void feedback(bool, string command) ;

	void displayTrueFeedback(string command) ;

	void displayFalseFeedback(string command) ;

	void printThis(string) ;
	
	string getUserInput() ;

	tm* getCurrentTime() ;

	void helpScreen();

} ;

#endif 