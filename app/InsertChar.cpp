#include "InsertChar.hpp"
#include "EditorModel.hpp"
#include "BooEditLog.hpp"

InsertChar::InsertChar(char x)
	:x{x},cursorLine{1},cursorColumn{1},lineCount{1}, text{""}
{
}


void InsertChar::execute(EditorModel& model){

	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	model.insertCharacter(x,cursorColumn,cursorLine);
	text=model.returnText();
	booEditLog(model.line(lineCount));
	// booEditLog(text);
	model.returnElementofVector(cursorLine,text);
	model.line(cursorLine);

}
void InsertChar::undo(EditorModel& model){
	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	text=model.returnText();
	std::string potato=model.deleteCharacter(cursorColumn,cursorLine);
	text=model.returnText();
	model.returnElementofVector(cursorLine,potato);
	model.line(cursorLine);



}