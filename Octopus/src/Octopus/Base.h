#pragma once

#ifdef ENABLE_ASSERTS
	#define OC_ASSERT(x, ...) { if(!(x)) { OC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define OC_CORE_ASSERT(x, ...) { if(!(x)) { OC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ASSERT(x, ...)
	#define CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)