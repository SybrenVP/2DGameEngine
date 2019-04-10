#include "pch.h"
#include "InputComponent.h"


svp::InputComponent::InputComponent(GameObject* const pGameObject)
	: BaseComponent(pGameObject)
{
	InputManager::GetInstance().AddPlayer(this);
}


svp::InputComponent::~InputComponent()
{
}

void svp::InputComponent::SetButton(ControllerButton button, InputCommands* pCommand)
{
	for (auto boundButtons : m_BoundButtons)
	{
		if (boundButtons.first == button && boundButtons.second == pCommand)
		{
			Logger::GetInstance().Log(Logger::LogType::Warning, "This button and command are already in the list; In 'InputComponent::SetButton()'");
			return;
		}
		if (boundButtons.first == button)
		{
			Logger::GetInstance().Log(Logger::LogType::Warning, "This button is already in use for another command; In 'InputComponent::SetButton()'.");
		}
		if (boundButtons.second == pCommand)
		{
			Logger::GetInstance().Log(Logger::LogType::Error, "This command is assigned to another button; In 'InputComponent::SetButton()'.");
			return;
		}
	}

	m_BoundButtons.push_back({ button, pCommand });
}

void svp::InputComponent::ProcessCommands(svp::ControllerButton* pButtons)
{

}