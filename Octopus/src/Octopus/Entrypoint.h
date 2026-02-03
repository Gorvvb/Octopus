#pragma once

extern Octopus::Application* Octopus::CreateApplication();

int main(int argc, char** argv)
{
	Octopus::Log::Init();
	LOG_CORE_WARN("Initialized Core Log!");
	int num = 25;
	LOG_INFO("Hello! Var={0}", num);

	auto app = Octopus::CreateApplication();
	app->Run();
	delete app;

	return 0;
}