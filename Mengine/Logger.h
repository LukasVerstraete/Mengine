#pragma once
#include "LogMessage.h"

namespace logging
{
	class Logger
	{
	public:
		LogMessage operator()(const std::string& file, int line);
		void flush(const LogMessage& message);
	};
}