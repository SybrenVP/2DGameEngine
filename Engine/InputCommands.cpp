#include "pch.h"
#include "InputCommands.h"

void svp::MoveUpCommand::Execute()
{
	Logger::GetInstance().Log(Logger::LogType::Debug, "Moving up.");
}
