#pragma once

#include "Events.h"

#include "../Window/Window.h"

namespace GameEngine
{
	class KeyPress : public Event
	{
	private:
		const KeyCodes::Keys KeyCode;
		const unsigned int RepeatCount;

		const std::shared_ptr<Window> s_Window;

	public:
		KeyPress(KeyCodes::Keys keyCode, unsigned int repeatCount, std::shared_ptr<Window> window)
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

		const std::shared_ptr<Window> GetWindow() { return(this->s_Window); }
	};

	class KeyRelease : public Event
	{
	private:
		const KeyCodes::Keys KeyCode;

		const std::shared_ptr<Window> s_Window;

	public:
		KeyRelease(KeyCodes::Keys keyCode, std::shared_ptr<Window> window) 
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

		const std::shared_ptr<Window> GetWindow() { return(this->s_Window); }
	};

	class KeyType : public Event
	{
	private:
		const char Symbol;

		const std::shared_ptr<Window> s_Window;

	public:
		KeyType(char symbol, std::shared_ptr<Window> window) 
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

		const std::shared_ptr<Window> GetWindow() { return(this->s_Window); }
	};
}