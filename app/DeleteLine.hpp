#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include <vector>

class DeleteLine: public Command{

	public:
		DeleteLine();
		virtual ~DeleteLine()=default;
		virtual void execute(EditorModel& model);
		virtual void undo(EditorModel& model);
	private:
		int cursorLine;
		int cursorColumn;
    	int lineCount;
    	std::string text;
    	std::vector<std::string> deleted{1,""};

};


#endif