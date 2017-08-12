#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include "EditorException.hpp"


class CursorLeft: public Command{

	public:
		CursorLeft();
		virtual ~CursorLeft()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	EditorException exception(std::string);

};


#endif