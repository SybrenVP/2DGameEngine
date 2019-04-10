#include "pch.h"
#include "InputManager.h"
#include "InputComponent.h"
#include <SDL.h>

bool svp::InputManager::IsNotQuitting()
{
	SDL_Event e{};
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return false;
		if(e.type == SDL_KEYDOWN)
		{ }
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{ }
	}

	return true;
}

bool svp::InputManager::IsPressed(ControllerButton button) const
{
	/*switch (button)
	{
	case ControllerButton::ButtonA:
		return m_pCurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
	case ControllerButton::ButtonB:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
	case ControllerButton::ButtonX:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
	case ControllerButton::ButtonY:
		return currentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
	default: return false;
	}*/
}

void svp::InputManager::ProcessInput()
{ //Add error logs to this function
	ZeroMemory(&m_pCurrentStates.at(0), sizeof(XINPUT_STATE));
	XInputGetState(0, &m_pCurrentStates.at(0));

	//Go over gameObjects that have the CharacterControllerComponent/InputComponent
	for (size_t i{}; i < m_pPlayers.size(); i++)
	{
		m_pPlayers.at(i)->ProcessCommands(m_pCurrentStates.at(i));
	}
}

void svp::InputManager::AddPlayer(InputComponent* pPlayer)
{
	m_pPlayers.push_back(pPlayer);
	m_pCurrentStates.push_back(XINPUT_STATE());
}