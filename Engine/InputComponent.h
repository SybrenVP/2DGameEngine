#pragma once
#include "BaseComponent.h"
#include "InputManager.h"
#include "InputCommands.h"

namespace svp
{
	class InputComponent final : public BaseComponent
	{
	public:
		InputComponent(GameObject* const pGameObject);
		~InputComponent();

		void SetButton(ControllerButton button, InputCommands* command);
		void ProcessCommands(ControllerButton* pButton );

	private:
		std::vector<std::pair<ControllerButton, InputCommands*>> m_BoundButtons;
	};
}