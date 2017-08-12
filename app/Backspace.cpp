#include "Backspace.hpp"
#include "EditorModel.hpp"
#include "BooEditLog.hpp"


Backspace::Backspace()
	:cursorLine{1},cursorColumn{1},lineCount{1}, text{""},deletedchar{""}
	{	
	}


void Backspace::execute(EditorModel& model){
	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	text=model.returnText();
	if (cursorColumn==1 &&cursorLine==1){
		throw EditorException("Already at beginning");
	}
	else {

		if(cursorColumn==1 && cursorLine!=1){
			std::string previous=model.returnTextofLine(cursorLine-1);
			if(previous==""){
				booEditLog("its empty fam");
				cursorLine=cursorLine-1;
				lineCount=lineCount-1;
				model.changeCursor(cursorLine,cursorColumn,lineCount);
			}
			else{


			std::string end=model.returnEndtext(cursorColumn,cursorLine);
			cursorColumn=model.returnLastCharLocation(cursorLine-1)+1;
			
			model.removeVectorElement(cursorLine, cursorColumn);
			booEditLog("ya");
			cursorLine=cursorLine-1;
			lineCount=lineCount-1;
			model.changeCursor(cursorLine,cursorColumn,lineCount);
			

			std::string potato=model.deleteCharacter(cursorColumn,cursorLine);

			potato+=end;
			
			model.returnElementofVector(cursorLine,potato);
			model.line(cursorLine);

			}


		}
		else{
			std::string thetextrn=model.returnTextofLine(cursorLine);
			deletedchar+=thetextrn.substr(cursorColumn-2,1);
			std::string potato=model.deleteCharacter(cursorColumn,cursorLine);

			//std::string wattext=model.returnTextofLine(cursorLine);
			model.returnElementofVector(cursorLine,potato);
			model.line(cursorLine);
		}
	}

	
}
void Backspace::undo(EditorModel& model){
	if(deletedchar!=""){


	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	model.insertCharacter(deletedchar.back(),cursorColumn,cursorLine);
	deletedchar=deletedchar.substr(0,deletedchar.size()-1);
	
	text=model.returnText();
	model.returnElementofVector(cursorLine,text);
	model.line(cursorLine);
}
}