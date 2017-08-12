// InteractionProcessor.cpp
//
// ICS 45C Fall 2016
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <stack>


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.
std::stack <Command*> undo;
std::stack <Command*> redo;

void InteractionProcessor::run()
{
    view.refresh();

    while (true)
    {
        view.refresh();
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if(undo.empty()==false){
                undo.top()->undo(model);
                redo.push(undo.top());
                undo.pop();
            }
           

        }
        else if (interaction.type() == InteractionType::redo)
        {
            if(redo.empty()==false){
                redo.top()->execute(model);
                undo.push(redo.top());
                redo.pop();
            }
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();
            while(!redo.empty()){
                redo.pop();
            }
            undo.push(command);


            try
            {
                command->execute(model);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            
            //delete command;
        }
    }
}

