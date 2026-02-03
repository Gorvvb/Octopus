#include "ocpch.h"
#include "Application.h"

namespace Octopus {

	Application::Application(const WindowProps& props)
	{
		m_Window = std::make_unique<Window>(props);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
}