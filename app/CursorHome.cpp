#include "CursorHome.hpp"
#include "EditorModel.hpp"


CursorHome::CursorHome()
	:cursorLine{1},cursorColumn{1},lineCount{1}
	{	
	}


void CursorHome::execute(EditorModel& model){
	cursorLine=model.cursorLine();

	lineCount=model.lineCount();
	model.changeCursor(cursorLine,1,lineCount);

}
void CursorHome::undo(EditorModel& model){
	model.changeCursor(cursorLine,cursorColumn,lineCount);
}