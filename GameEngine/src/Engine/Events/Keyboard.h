#pragma once

#include "Events.h"
#include "../Definitions/KeyCodes/KeyCodes.h"

namespace Engine
{
	class KeyPress : public Event
	{
	private:
		KeyCodes::Keys KeyCode;
		unsigned int RepeatCount;
	public:
		KeyPress(KeyCodes::Keys keyCode, unsigned int repeatCount) : KeyCode(keyCode), RepeatCount(repeatCount) { EventType = EventTypes::KeyPress; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyPress: " << KeyCodes::ToString(KeyCode) << " " << RepeatCount;
				return(ss.str());
			}
		#endif
	};

	class KeyRelease : public Event
	{
	private:
		KeyCodes::Keys KeyCode;
	public:
		KeyRelease(KeyCodes::Keys keyCode) : KeyCode(keyCode) { EventType = EventTypes::KeyRelease; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyRelease: " << KeyCodes::ToString(KeyCode);
				return(ss.str());
			}
		#endif
	};

	class KeyType : public Event
	{
	private:
		char Symbol;
	public:
		KeyType(char symbol) : Symbol(symbol) { EventType = EventTypes::KeyType; }

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyType: " << Symbol;
				return(ss.str());
			}
		#endif
	};
}