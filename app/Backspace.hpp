#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include "EditorException.hpp"

class Backspace: public Command{

	public:
		Backspace();
		virtual ~Backspace()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		
		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	std::string text;
    	std::string deletedchar;
    	EditorException exception(std::string);



};


#endif