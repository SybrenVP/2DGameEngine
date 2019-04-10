#include "pch.h"
#include "TextureComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"


svp::TextureComponent::TextureComponent(GameObject* const gameObject, const std::string& file, float posX, float posY)
	: BaseComponent(gameObject)
	, m_pTexture{ nullptr }
	, m_PosX{ posX }
	, m_PosY{ posY }
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(file);
}


svp::TextureComponent::~TextureComponent()
{
	if (m_pTexture)
		delete m_pTexture;
}

void svp::TextureComponent::Update()
{
}

void svp::TextureComponent::Render()
{
	if (m_pTexture)
		Renderer::GetInstance().RenderTexture(m_pTexture->GetSDLTexture(), m_PosX, m_PosY);
}
