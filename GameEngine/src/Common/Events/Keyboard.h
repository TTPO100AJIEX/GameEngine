#pragma once

#include "Event.h"

namespace GameEngine
{
	class Window;
}

namespace GameEngine
{
	class KeyPress : public Event
	{
	private:
		const KeyCodes::Keys KeyCode;
		const unsigned int RepeatCount;

		const Window* s_Window;

	public:
		KeyPress(KeyCodes::Keys keyCode, unsigned int repeatCount, const Window* window)
			: Event(EventTypes::KeyPress), KeyCode(keyCode), RepeatCount(repeatCount), s_Window(window) {};
		virtual ~KeyPress() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyPress: " << KeyCodes::ToString(KeyCode) << " " << RepeatCount;
				return(ss.str());
			}
		#endif

		const KeyCodes::Keys& GetKey() { return(this->KeyCode); };

		const Window* GetWindow() { return(this->s_Window); }
	};

	class KeyRelease : public Event
	{
	private:
		const KeyCodes::Keys KeyCode;

		const Window* s_Window;

	public:
		KeyRelease(KeyCodes::Keys keyCode, const Window* window)
			: Event(EventTypes::KeyRelease), KeyCode(keyCode), s_Window(window) {};
		virtual ~KeyRelease() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyRelease: " << KeyCodes::ToString(KeyCode);
				return(ss.str());
			}
		#endif

		const KeyCodes::Keys& GetKey() { return(this->KeyCode); }

		const Window* GetWindow() { return(this->s_Window); }
	};

	class KeyType : public Event
	{
	private:
		const char Symbol;

		const Window* s_Window;

	public:
		KeyType(char symbol, const Window* window)
			: Event(EventTypes::KeyType), Symbol(symbol), s_Window(window) {};
		virtual ~KeyType() = default;

		#ifdef DEBUG
			virtual std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyType: " << Symbol;
				return(ss.str());
			}
		#endif

		const char GetSymbol() { return(this->Symbol); }

		const Window* GetWindow() { return(this->s_Window); }
	};
}