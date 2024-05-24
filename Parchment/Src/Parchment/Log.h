#pragma once

#include <memory>

#include "Parchment/Core.h"
#include "spdlog/spdlog.h"

namespace Parch
{
	class PCH_API Log
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
#define PCH_CORE_ERROR(...)   ::Parch::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PCH_CORE_WARN(...)	  ::Parch::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PCH_CORE_INFO(...)	  ::Parch::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PCH_CORE_TRACE(...)   ::Parch::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PCH_CORE_FATAL(...)   ::Parch::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define PCH_ERROR(...) ::Parch::Log::GetClientLogger()->error(__VA_ARGS__)
#define PCH_WARN(...)  ::Parch::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PCH_INFO(...)  ::Parch::Log::GetClientLogger()->info(__VA_ARGS__)
#define PCH_TRACE(...) ::Parch::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PCH_FATAL(...) ::Parch::Log::GetClientLogger()->fatal(__VA_ARGS__)