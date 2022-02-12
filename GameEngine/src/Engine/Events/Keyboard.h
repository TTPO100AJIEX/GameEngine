#pragma once

#include "Events.h"

namespace GameEngine
{
	class KeyPress : public Event
	{
	private:
		const KeyCodes::Keys KeyCode;
		const unsigned int RepeatCount;

	public:
		KeyPress(KeyCodes::Keys keyCode, unsigned int repeatCount) : Event(EventTypes::KeyPress), KeyCode(keyCode), RepeatCount(repeatCount) {};
		virtual ~KeyPress() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyPress: " << KeyCodes::ToString(KeyCode) << " " << RepeatCount;
				return(ss.str());
			}
		#endif

		inline const KeyCodes::Keys& GetKey() { return(KeyCode); };
	};

	class KeyRelease : public Event
	{
	private:
		const KeyCodes::Keys KeyCode;

	public:
		KeyRelease(KeyCodes::Keys keyCode) : Event(EventTypes::KeyRelease), KeyCode(keyCode) {};
		virtual ~KeyRelease() = default;

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
		const char Symbol;

	public:
		KeyType(char symbol) : Event(EventTypes::KeyType), Symbol(symbol) {};
		virtual ~KeyType() = default;

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