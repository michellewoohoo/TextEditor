#include "CursorEnd.hpp"
#include "EditorModel.hpp"


CursorEnd::CursorEnd()
	:cursorLine{1},cursorColumn{1},lineCount{1}
	{	
	}


void CursorEnd::execute(EditorModel& model){
	cursorLine=model.cursorLine();
	lineCount=model.lineCount();
	int x=model.returnLastCharLocation(cursorLine);
	model.changeCursor(cursorLine,x,lineCount);

}
void CursorEnd::undo(EditorModel& model){
	model.changeCursor(cursorLine,cursorColumn,lineCount);
}