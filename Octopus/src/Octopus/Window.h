#pragma once

#include "ocpch.h"

#include "Octopus/Base.h"
#include "Octopus/Events/Event.h"

#include <GLFW/glfw3.h>

namespace Octopus {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Octopus Application",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title), Width(width), Height(height) { }
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(const WindowProps& props);
		virtual ~Window();

		void OnUpdate();

		unsigned int GetWidth() const { return m_Data.Width; }
		unsigned int GetHeight() const { return m_Data.Height; }

		void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled);
		bool IsVSync() const;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}