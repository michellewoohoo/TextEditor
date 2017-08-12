#include "CursorUp.hpp"
#include "EditorModel.hpp"



CursorUp::CursorUp()
	:cursorLine{1},cursorColumn{1},lineCount{1}
	{	
	}


void CursorUp::execute(EditorModel& model){
	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	int previous=model.returnLastCharLocation(cursorLine-1);
	if(cursorLine==1){
		cursorLine=1;
		throw EditorException("Already at top");
	}
	
	else if(previous<cursorColumn){
		model.changeCursor(cursorLine-1,previous,lineCount);
	}
	else{
		cursorLine=cursorLine-1;
		model.changeCursor(cursorLine,cursorColumn,lineCount);

	}

	
}
void CursorUp::undo(EditorModel& model){
	model.changeCursor(cursorLine,cursorColumn,lineCount);
}