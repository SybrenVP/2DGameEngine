#pragma once
#include "BaseComponent.h"

namespace svp
{
	class InputComponent;

	class CharacterControllerComponent final : public BaseComponent
	{
	public:
		CharacterControllerComponent(GameObject* const pGameObject);
		~CharacterControllerComponent();

	private:
		InputComponent* m_InputComp;
	};
}