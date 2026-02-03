#pragma once

#include "base.h"
#include "events/Event.h"
#include "Octopus/Events/ApplicationEvent.h"
#include "Window.h"

namespace Octopus {

	class Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application(const WindowProps& props = WindowProps());
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);
	};

	// Define in client.
	Application* CreateApplication();
}
