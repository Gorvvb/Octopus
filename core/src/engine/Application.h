#pragma once

#include "base.h"
#include "events/Event.h"
#include "Window.h"

namespace Engine {

	class Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	public:
		Application(const WindowProps& props = WindowProps());
		virtual ~Application();
		
		void Run();
	};

	// Define in client.
	Application* CreateApplication();
}
