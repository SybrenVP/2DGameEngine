#include "pch.h"
#include "FPSScene.h"

#include "GameObject.h"
#include "Components.h"

#include "Renderer.h"
#include "GameTime.h"
#include "ResourceManager.h"
#include "Font.h"


svp::FPSScene::FPSScene()
	: Scene("FPSScene")
{
}


svp::FPSScene::~FPSScene()
{
	for (auto gameObject : m_pGameObjects)
	{
		if (gameObject)
			delete gameObject;
	}
}

void svp::FPSScene::Initialize()
{
	std::string fullPath{ "../Data/Lingua.otf" };
	GameObject* backGround = new GameObject();
	TextureComponent* backGroundTexture = new TextureComponent(backGround, "background.jpg");
	backGround->AddComponent(backGroundTexture);
	Add(backGround);
	
	auto logo = new GameObject();
	logo->SetPosition(216.f, 180.f);
	TextureComponent* logoTexture = new TextureComponent(logo, "logo.png", 216.f, 180.f);
	logo->AddComponent(logoTexture);
	Add(logo);

	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textGameObject = new GameObject();
	TextComponent* text = new TextComponent(textGameObject, "Programming 4 assignment", font);
	text->SetPosition(80.f, 20.f);
	textGameObject->AddComponent(text);
	Add(textGameObject);

	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 18);
	auto fpsObject = new GameObject();
	const SDL_Color& fpsTextColor = { 255, 255, 0 };
	auto fpsComp = new FPSComponent(fpsObject, font, fpsTextColor);
	fpsComp->SetPosition(10.f, 10.f);
	fpsObject->AddComponent(fpsComp);
	Add(fpsObject);
}

void svp::FPSScene::Update()
{
	for (const auto gameObject : m_pGameObjects)
		gameObject->Update();
}

void svp::FPSScene::Render() const
{
	for (const auto gameObject : m_pGameObjects)
		gameObject->Render();
}
