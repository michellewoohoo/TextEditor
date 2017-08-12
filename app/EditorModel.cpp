// EditorModel.cpp
//
// ICS 45C Fall 2016
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include "BooEditLog.hpp"
#include <vector>
#include <string>
#include <iostream>




EditorModel::EditorModel()
	:current_cursorLine{1},current_cursorColumn{1},current_lineCount{1},
	current_line{"heh"}, text{""}

{
}


int EditorModel::cursorLine() const
{
    return current_cursorLine;
}


int EditorModel::cursorColumn() const
{
    return current_cursorColumn;
}


int EditorModel::lineCount() const
{
    return current_lineCount;
}
std::string EditorModel::returnText() const{
	return text;
}

std::string EditorModel::returnTextofLine(int linenumber){
	booEditLog("***returnTextofLine**");
	booEditLog(theline[linenumber-1]);

	return theline[linenumber-1];

}

void EditorModel::returnElementofVector(int lineNumber, std::string thetext){
	theline[lineNumber-1]=thetext;
	booEditLog("returnElementof");
	booEditLog(thetext);

}

std::string EditorModel::changeElementofVector(int lineNumber, std::string thetext){
	theline[lineNumber-1]=thetext;
	booEditLog("returnElementof");
	booEditLog(thetext);
	return thetext;
}

const std::string& EditorModel::line(int lineNumber) const
{
    return theline[lineNumber-1];
}

void EditorModel::changeText(std::string thetext){
	text=thetext;
}
void EditorModel::changeCursor(int line, int column, int count)
{
	
	current_cursorLine=line;
	current_cursorColumn=column;
	current_lineCount=count;

}

int EditorModel::returnLastCharLocation(int line){
	return theline[line-1].length()+1;
}


void EditorModel::insertCharacter(char x, int column, int curline){
	std::string t=line(curline);
	if(t==""){
		t+=x;
	}
	else{

		if(t.substr(column-1)==""){
			t+=x;
		}
			else{
			std::string restofstring=t.substr(column-1);
			std::string beginning=t.substr(0,column-1);
			beginning+=x;
			beginning+=restofstring;
			t=beginning;
	}
	}
	current_cursorColumn+=1;
	text=t;
	
}

std::string EditorModel::deleteCharacter(int column,int line){
	std::string thetext=returnTextofLine(line);
	booEditLog(thetext);
	if(thetext!=""){
		booEditLog("its not ");
		
		thetext=thetext.erase(column-2,1);
		current_cursorColumn=current_cursorColumn-1;
		booEditLog("DELETING");
		booEditLog(thetext);
		booEditLog("?????????");
		return thetext;
	}

}

void EditorModel::newVectorElement(int line, int column){
	
	theline.insert(theline.begin()+line,"");
	//take in last line number, column number
	int i=theline.size();
	std::string s=std::to_string(i);
		booEditLog("added new line");
	booEditLog(s);


}

void EditorModel::removeVectorElement(int line, int column){
	theline.erase(theline.begin()+line-1);
	int i=theline.size();
	std::string s=std::to_string(i);
	booEditLog("removing vector element");
	booEditLog(s);


	
}

std::string EditorModel::returnBeginningtext(int column, std::string thetext){
	std::string beginningtext=thetext.substr(0,column-1);
	booEditLog(beginningtext);
	return beginningtext;

}

std::string EditorModel::returnEndtext(int column,int line){
	std::string thetext=returnTextofLine(line);
	std::string endtext=thetext.substr(column-1);
	booEditLog(endtext);
	return endtext;
}





/*void EditorModel::moveRight()
{
	current_cursorColumn+=1;
	clearErrorMessage();
}
void EditorModel::moveLeft()
{
	if (((current_cursorColumn-1)==0)&&((current_cursorLine-1)==0))
	{
		current_cursorColumn=1;
		setErrorMessage("Already at beginning");
	}
	else{
		current_cursorColumn=current_cursorColumn-1;
		clearErrorMessage();
	}
}
	
void EditorModel::moveUp()
{
	if(current_cursorLine==1){
		current_cursorLine=1;
		setErrorMessage("Already at the top");

	}
	else{
		current_cursorLine=current_cursorLine-1;
		clearErrorMessage();

	}
	
}

void EditorModel::moveDown()
{

	current_cursorLine+=1;
	clearErrorMessage();
}

void EditorModel::moveBeginning()
{

	current_cursorColumn=1;
}*/

const std::string& EditorModel::currentErrorMessage() const
{
    //static std::string current_error="";
    return errormessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	
	errormessage=errorMessage;

}


void EditorModel::clearErrorMessage()
{
	setErrorMessage("");

}



