#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include "EditorException.hpp"

class CursorDown: public Command{

	public:
		CursorDown();
		virtual ~CursorDown()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	EditorException exception(std::string);

};


#endif