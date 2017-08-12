#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include "EditorException.hpp"

class CursorRight: public Command{

	public:
		CursorRight();
		virtual ~CursorRight()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	EditorException exception(std::string);



};


#endif