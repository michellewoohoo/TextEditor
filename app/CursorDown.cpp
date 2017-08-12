#include "CursorDown.hpp"
#include "EditorModel.hpp"


CursorDown::CursorDown()
	:cursorLine{1},cursorColumn{1},lineCount{1}
	{	
	}


void CursorDown::execute(EditorModel& model){

	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	int below=model.returnLastCharLocation(cursorLine+1);
	
	if(cursorLine==lineCount){
		int x=cursorLine;
		cursorLine=x;
		throw EditorException("Already at bottom");

	}
	else if(below<cursorColumn){
		model.changeCursor(cursorLine+1,below,lineCount);

	}
	else{
		model.changeCursor(cursorLine+1,cursorColumn,lineCount);

	}

	
	

	

	

}
void CursorDown::undo(EditorModel& model){
	model.changeCursor(cursorLine,cursorColumn,lineCount);
}