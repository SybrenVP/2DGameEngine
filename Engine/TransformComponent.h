#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include "../lib/glm/glm/vec3.hpp"
#pragma warning(pop)

namespace svp
{
	class Transform final
	{
	public:
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z)
		{
			m_Position = { x, y, z };
		}

	private:
		glm::vec3 m_Position;
	};
}