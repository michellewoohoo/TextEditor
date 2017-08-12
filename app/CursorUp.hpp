#ifndef CURSORUP_HPP
#define CURSORUP_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include "EditorException.hpp"


class CursorUp: public Command{

	public:
		CursorUp();
		virtual ~CursorUp()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	EditorException exception(std::string);


};


#endif