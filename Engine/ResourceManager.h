#pragma once
#include "Singleton.h"

namespace svp
{
	class Texture2D;
	class Font;

	class ResourceManager final : public Singleton<ResourceManager>
	{
		std::string m_DataPath;

	public:
		ResourceManager() = default;
		
		void Init(std::string&& dataPath);

		Font* LoadFont(const std::string& file, unsigned int size);
		Texture2D* LoadTexture(const std::string& file);
	};
}