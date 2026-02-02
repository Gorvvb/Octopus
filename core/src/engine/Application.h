#pragma once

namespace Engine {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// Define in client.
	Application* CreateApplication();
}
