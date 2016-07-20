#include <iostream>

#include "Logger.h"
#include "LogMessage.h"

namespace logging
{
	void Logger::flush(const LogMessage& message)
	{
		std::string asString = message.m_buffer.str();
		std::cout << asString << "\n";
	}
}