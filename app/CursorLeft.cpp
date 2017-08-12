#include "CursorLeft.hpp"
#include "EditorModel.hpp"


CursorLeft::CursorLeft()
	:cursorLine{1},cursorColumn{1},lineCount{1}
	{	
	}

void CursorLeft::execute(EditorModel& model){
	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();

	if(cursorColumn==1 && cursorLine==1){
		cursorColumn=1;
		throw EditorException("Already at beginning");

	}
	else if(cursorColumn==1 && cursorLine!=1){
		int col=model.returnLastCharLocation(cursorLine-1);
		model.changeCursor(cursorLine-1,col,lineCount);
	
	}
	else{
		model.changeCursor(cursorLine,cursorColumn-1,lineCount);
	}

}
void CursorLeft::undo(EditorModel& model){
	model.changeCursor(cursorLine,cursorColumn,lineCount);
}