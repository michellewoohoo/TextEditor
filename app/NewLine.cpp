#include "NewLine.hpp"
#include "EditorModel.hpp"
#include "BooEditLog.hpp"
#include <iostream>

NewLine::NewLine()
	:cursorLine{1},cursorColumn{1},lineCount{1}, text{""}
	{	
	}


void NewLine::execute(EditorModel& model){
	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	text=model.returnText();
	model.newVectorElement(cursorLine, cursorColumn);

	booEditLog("------------");
	std::string beginning=model.returnBeginningtext(cursorColumn,text);
	//edited returnENDTEXT ***
	std::string end=model.returnEndtext(cursorColumn,cursorLine);
	model.returnElementofVector(cursorLine,beginning);
	booEditLog("lol wat am i doing");
	model.returnElementofVector(cursorLine+1,end);

	model.line(cursorLine);
	model.line(cursorLine+1);

	model.changeCursor(cursorLine+1,1,lineCount+1);



	

	

}
void NewLine::undo(EditorModel& model){
	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	

	booEditLog("undoing");
	std::string end=model.returnEndtext(cursorColumn,cursorLine);
	model.removeVectorElement(cursorLine,cursorColumn);
	std::string previousline=model.returnTextofLine(cursorLine-2);
	

	model.returnElementofVector(cursorLine-1,text);
	int lastcursor=model.returnLastCharLocation(cursorLine-1);
	model.changeCursor(cursorLine-1,lastcursor,lineCount-1);
	model.line(cursorLine-1);
	


	/*previousline+=end;
	
	int lastcursor=model.returnLastCharLocation(cursorLine-1);
	model.returnElementofVector(cursorLine,previousline);
	model.line(cursorLine);

	model.changeCursor(cursorLine-1,lastcursor,lineCount-1);*/


}