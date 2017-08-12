#include "DeleteLine.hpp"
#include "EditorModel.hpp"
#include "BooEditLog.hpp"
#include <iostream>


DeleteLine::DeleteLine()
	:cursorLine{1},cursorColumn{1},lineCount{1}, text{""}
	{	

	}
void DeleteLine::execute(EditorModel& model){
	cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	text=model.returnText();
	if(cursorLine==1){
		std::string deleteln=model.returnTextofLine(cursorLine);
		deleted.push_back(deleteln);
		model.changeCursor(cursorLine,1,lineCount);
		std::string setempty=model.changeElementofVector(cursorLine,"");
		model.returnElementofVector(cursorLine,setempty);
		model.line(cursorLine);
	}
	else{
		std::string deleteln=model.returnTextofLine(cursorLine);
		model.removeVectorElement(cursorLine,cursorColumn);
		deleted.push_back(deleteln);
		if(cursorLine==lineCount){
			int previous=model.returnLastCharLocation(cursorLine-1);
			if(previous<cursorColumn){
				std::string setempty=model.changeElementofVector(cursorLine,"");
				model.returnElementofVector(cursorLine,setempty);
				model.changeCursor(cursorLine-1,previous,lineCount-1);
				model.line(cursorLine);
			}
			else{
				std::string setempty=model.changeElementofVector(cursorLine,"");
				model.returnElementofVector(cursorLine,setempty);
				cursorLine=cursorLine-1;
				model.changeCursor(cursorLine,cursorColumn,lineCount-1);
				model.line(cursorLine);
			}

		}
		else{
			int below=model.returnLastCharLocation(cursorLine+1);
	
			if(below<cursorColumn){
				std::string setempty=model.changeElementofVector(cursorLine,"");
				model.returnElementofVector(cursorLine,setempty);
				model.changeCursor(cursorLine-1,below,lineCount-1);
				model.line(cursorLine-1);
			}
			else{
				std::string setempty=model.changeElementofVector(cursorLine,"");
				model.returnElementofVector(cursorLine,setempty);
				
				model.changeCursor(cursorLine+1,cursorColumn,lineCount-1);
				model.line(cursorLine-1);
			}

		}



	}
	

}
void DeleteLine::undo(EditorModel& model){
	if(!deleted.empty()){
		cursorLine=model.cursorLine();
	cursorColumn=model.cursorColumn();
	lineCount=model.lineCount();
	
	model.newVectorElement(cursorLine,cursorColumn);
	std::string lastone=deleted.back();

	model.returnElementofVector(cursorLine+1,lastone);
	model.line(cursorLine+1);
	}
	}