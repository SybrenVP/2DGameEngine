#pragma once
#include <XInput.h>
#include "Singleton.h"

namespace svp
{
	class InputComponent;

	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY
	};
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool IsNotQuitting();
		bool IsPressed(ControllerButton button) const;
		void ProcessInput();
		void AddPlayer(InputComponent * pPlayer);
	private:
		std::vector<XINPUT_STATE> m_pCurrentStates;
		std::vector<InputComponent*> m_pPlayers;
	};
}
