#include "pch.h"
#include "GameTime.h"

void svp::GameTime::Initialize()
{
	m_PreviousTime = GetCurrentTime();
}

void svp::GameTime::Update()
{
	double currentTime = GetCurrentTime();
	m_DeltaTime = currentTime - m_PreviousTime;
	m_PreviousTime = currentTime;

	m_Lag += m_DeltaTime;
	m_TotalTime += m_DeltaTime;

	UpdateTimers();
}

void svp::GameTime::UpdateLag()
{
	m_Lag -= m_MsPerUpdate;
}

void svp::GameTime::UpdateTimers()
{
	if (m_Timers.size() > 0)
	{
		for (auto timer : m_Timers)
		{
			if (!timer.finished)
				timer.time -= m_DeltaTime;
			else if (timer.time <= 0)
				timer.finished = true;
		}
	}
}

void svp::GameTime::SetTimer(double time, int index)
{
	Timer timer{};
	timer.time = time;
	timer.finished = false;
	timer.index = index;

	m_Timers.push_back(timer);
}

bool svp::GameTime::IsTimerFinished(int index)
{
	for (auto timer : m_Timers)
	{
		if (timer.index == index)
		{
			if (timer.finished)
				return true;
			else
				return false;
		}
	}
	Logger::GetInstance().Log(Logger::LogType::Error, "Timer index was not found in 'IsTimerFinished()'.");
	return false; //Log that the index was not found
}

void svp::GameTime::CleanupTimers()
{
	for (size_t i{}; i < m_Timers.size(); i++)
	{
		if (m_Timers[i].finished)
		{
			Timer temp = m_Timers[m_Timers.size() - 1];
			m_Timers[m_Timers.size() - 1] = m_Timers[i];
			m_Timers[i] = temp;
			m_Timers.pop_back();
		}
	}
}
