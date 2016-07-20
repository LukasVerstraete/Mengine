#pragma once
#include <ostream>
#include <sstream>

#include "Logger.h"


namespace logging
{

	class LogMessage
	{
	private:
		struct Meta
		{
			std::string m_file;
			int m_line;
		};

		friend class Logger;
		std::ostringstream m_buffer;
		Logger* m_owner;
		Meta m_meta;
	private:
		LogMessage(const std::string& file, int line, Logger* owner);
	
	public:
		LogMessage(LogMessage&& msg);
		~LogMessage();
		template<typename T>
		LogMessage& operator << (const T& value);
		LogMessage& operator << (std::ostream&(*fn)(std::ostream& os));
	};

	LogMessage::LogMessage(const std::string& file , int line, Logger* owner) :
		m_owner(owner),
		m_meta{ file, line }
		{}

	LogMessage::LogMessage(LogMessage&& msg): 
		m_owner(std::move(msg.m_owner)), 
		m_buffer(std::move(msg.m_buffer))
	{
		msg.m_owner = nullptr;
	}

	LogMessage::~LogMessage()
	{
		m_owner->flush(*this);
	}

	template<typename T>
	LogMessage& LogMessage::operator<<(const T& value)
	{
		m_buffer << value;
		return *this;
	}

	LogMessage& LogMessage::operator<<(std::ostream&(*fn)(std::ostream& os))
	{
		fn(m_buffer);
		return *this;
	}

}