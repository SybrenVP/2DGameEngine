#pragma once

namespace svp
{
	class InputCommands
	{
	public:
		virtual ~InputCommands() = default;
		virtual void Execute() = 0;
	};

	class MoveUpCommand final : public InputCommands
	{
		void Execute() override;
	};
}