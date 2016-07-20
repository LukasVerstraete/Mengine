#pragma once

#include "Logger.h"

#define g_log::mengine::logger(_FILE_, _LINE_);

namespace mengine
{
	extern logging::Logger logger;
}

int main()
{
	return 0;
}
