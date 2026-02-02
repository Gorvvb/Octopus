#pragma once

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	LOG_CORE_WARN("Initialized Core Log!");
	int num = 25;
	LOG_INFO("Hello! Var={0}", num);

	auto app = Engine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}