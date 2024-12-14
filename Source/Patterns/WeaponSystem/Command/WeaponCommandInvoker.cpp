#include "WeaponCommandInvoker.h"

void UWeaponCommandInvoker::ExecuteCommand(UWeaponCommand* Command)
{
	if (!Command)
	{
		return;
	}

	Command->Execute();
	CommandHistory.Add(Command);
}

void UWeaponCommandInvoker::UndoLastCommand()
{
	if (CommandHistory.Num() > 0)
	{
		UWeaponCommand* LastCommand = CommandHistory.Last();
		if (LastCommand)
		{
			LastCommand->Undo();
			CommandHistory.RemoveAt(CommandHistory.Num() - 1);
		}
	}
}

void UWeaponCommandInvoker::ClearHistory()
{
	CommandHistory.Empty();
}
