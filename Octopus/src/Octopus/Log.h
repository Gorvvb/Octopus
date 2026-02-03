#pragma once

#include "Octopus/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Octopus
{
	class Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

// Core log macros
#define LOG_CORE_TRACE(...)		::Octopus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)		::Octopus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)		::Octopus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)		::Octopus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...)	::Octopus::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)			::Octopus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)			::Octopus::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)			::Octopus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)			::Octopus::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)		::Octopus::Log::GetClientLogger()->critical(__VA_ARGS__)