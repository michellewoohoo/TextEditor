#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class NewLine: public Command{

	public:
		NewLine();
		virtual ~NewLine()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	std::string text;

};


#endif