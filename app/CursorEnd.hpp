#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class CursorEnd: public Command{

	public:
		CursorEnd();
		virtual ~CursorEnd()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		int cursorLine;
		int cursorColumn;
    	int lineCount;


};


#endif