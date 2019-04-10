#pragma once
#include "BaseComponent.h"
#include "TextComponent.h"
#include "TransformComponent.h"

namespace svp
{
	class FPSComponent : public BaseComponent
	{
	public:
		FPSComponent(GameObject* gameObject, Font* font, const SDL_Color& color);
		virtual ~FPSComponent();

		virtual void Update();
		virtual void Render();
		virtual void FixedUpdate() { return; }
		void SetPosition(float x, float y);

	private:
		TextComponent* m_pText;
		int m_FPS;
		int m_FrameCounter;
	};
}