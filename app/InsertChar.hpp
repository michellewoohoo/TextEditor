#ifndef INSERTCHAR_HPP
#define INSERTCHAR_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class InsertChar: public Command{

	public:
		InsertChar(char x);
		virtual ~InsertChar()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		char x;

		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	std::string text;
};


#endif