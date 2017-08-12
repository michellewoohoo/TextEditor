#include "CursorRight.hpp"
#include "EditorModel.hpp"
#include <string>
#include "BooEditLog.hpp"

CursorRight::CursorRight()
	:cursorLine{1},cursorColumn{1},lineCount{1}
{
}


void CursorRight::execute(EditorModel& model){


	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	int x=model.returnLastCharLocation(cursorLine);
	if(x==cursorColumn && cursorLine!=lineCount){
		model.changeCursor(cursorLine+1,1,lineCount);

	}
	else if(x!=cursorColumn){
	
	model.changeCursor(cursorLine,cursorColumn+1,lineCount);
	}
	else{
		throw EditorException("Already at end");
	}
}
void CursorRight::undo(EditorModel& model){
	model.changeCursor(cursorLine,cursorColumn,lineCount);
}