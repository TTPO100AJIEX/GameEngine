#include <PrecompiledHeaders.h>

#include "KeyCodes.h"

#ifdef DEBUG
	namespace Engine::KeyCodes
	{
		const std::unordered_map <Keys, std::string> To_String({
			{ Keys::MOUSE_BUTTON_1, "MOUSE_BUTTON_1" }, { Keys::MOUSE_BUTTON_2, "MOUSE_BUTTON_2" }, { Keys::MOUSE_BUTTON_3, "MOUSE_BUTTON_3" }, { Keys::MOUSE_BUTTON_4, "MOUSE_BUTTON_4" },
				{ Keys::MOUSE_BUTTON_5, "MOUSE_BUTTON_5" }, { Keys::MOUSE_BUTTON_6, "MOUSE_BUTTON_6" }, { Keys::MOUSE_BUTTON_7, "MOUSE_BUTTON_7" }, { Keys::MOUSE_BUTTON_8, "MOUSE_BUTTON_8" },

			{ Keys::SPACE, "SPACE" }, { Keys::APOSTROPHE, "APOSTROPHE" }, { Keys::COMMA, "COMMA" }, { Keys::MINUS, "MINUS" }, { Keys::PERIOD, "PERIOD" }, { Keys::SLASH, "SLASH" },

			{ Keys::D0, "D0" }, {Keys::D1, "D1" }, {Keys::D2, "D2" }, {Keys::D3, "D3" }, {Keys::D4, "D4" }, {Keys::D5, "D5" }, { Keys::D6, "D6" }, {Keys::D7, "D7" }, {Keys::D8, "D8" }, {Keys::D9, "D9" },

			{ Keys::SEMICOLON, "SEMICOLON" }, { Keys::EQUAL, "EQUAL" },

			{ Keys::A, "A" }, {Keys::B, "B" }, {Keys::C, "C" }, {Keys::D, "D" }, {Keys::E, "E" }, {Keys::F, "F" }, { Keys::G, "G" }, { Keys::H, "H" }, { Keys::I, "I" },
				{ Keys::J, "J" }, { Keys::K, "K" }, { Keys::L, "L" }, { Keys::M, "M" }, { Keys::N, "N" }, { Keys::O, "O" }, { Keys::P, "P" }, { Keys::Q, "Q" }, { Keys::R, "R" },
				{ Keys::S, "S" }, { Keys::T, "T" }, { Keys::U, "U" }, { Keys::V, "V" }, { Keys::W, "W" }, { Keys::X, "X" }, { Keys::Y, "Y" }, { Keys::Z, "Z" },

			{ Keys::LEFTBRACKET, "LEFTBRACKET" }, { Keys::BACKSLASH, "BACKSLASH" }, { Keys::RIGHTBRACKET, "RIGHTBRACKET" }, { Keys::GRAVEACCENT, "GRAVEACCENT" },

			{ Keys::WORLD1, "WORLD1" }, { Keys::WORLD2, "WORLD2" },

			{ Keys::ESCAPE, "ESCAPE" }, { Keys::ENTER, "ENTER" }, { Keys::TAB, "TAB" }, { Keys::BACKSPACE, "BACKSPACE" }, { Keys::INSERT, "INSERT" }, { Keys::DEL, "DELETE" },
				{ Keys::RIGHT, "RIGHT" }, { Keys::LEFT, "LEFT" }, { Keys::DOWN, "DOWN" }, { Keys::UP, "UP" },

			{ Keys::PAGEUP, "PAGEUP" }, { Keys::PAGEDOWN, "PAGEDOWN" }, { Keys::HOME, "HOME" }, { Keys::END, "END" }, { Keys::CAPSLOCK, "CAPSLOCK" },
				{ Keys::SCROLLLOCK, "SCROLLLOCK" }, { Keys::NUMLOCK, "NUMLOCK" }, {Keys::PRINTSCREEN, "PRINTSCREEN"}, {Keys::PAUSE, "PAUSE"},

			{ Keys::F1, "F1" }, { Keys::F2, "F2" }, { Keys::F3, "F3" }, { Keys::F4, "F4" }, { Keys::F5, "F5" }, { Keys::F6, "F6" }, { Keys::F7, "F7" }, { Keys::F8, "F8" },
				{ Keys::F9, "F9" }, { Keys::F10, "F10" }, { Keys::F11, "F11" }, { Keys::F12, "F12" }, { Keys::F13, "F13" }, { Keys::F14, "F14" }, { Keys::F15, "F15" },
				{ Keys::F16, "F16" }, { Keys::F17, "F17" }, { Keys::F18, "F18" }, { Keys::F19, "F19" }, { Keys::F20, "F20" }, { Keys::F21, "F21" }, { Keys::F22, "F22" },
				{ Keys::F23, "F23" }, { Keys::F24, "F24" }, { Keys::F25, "F25" },

			{ Keys::KP0, "KP0" }, { Keys::KP1, "KP1" }, { Keys::KP2, "KP2" }, { Keys::KP3, "KP3" }, { Keys::KP4, "KP4" }, { Keys::KP5, "KP5" }, { Keys::KP6, "KP6" },
				{ Keys::KP7, "KP7" }, { Keys::KP8, "KP8" }, { Keys::KP9, "KP9" },

			{ Keys::KPDECIMAL, "KPDECIMAL" }, { Keys::KPDIVIDE, "KPDIVIDE" }, { Keys::KPMULTIPLY, "KPMULTIPLY"}, {Keys::KPSUBTRACT, "KPSUBTRACT" },
				{ Keys::KPADD, "KPADD" }, { Keys::KPEQUAL, "KPEQUAL" }, { Keys::KPENTER, "KPENTER" },

			{ Keys::LETSHIFT, "LETSHIFT" }, { Keys::LEFTCONTROL, "LEFTCONTROL" }, { Keys::LEFTALT, "LEFTALT" }, { Keys::LEFTSUPER, "LEFTSUPER" }, { Keys::RIGHTSHFIT, "RIGHTSHFIT" },
				{ Keys::RIGHTCONTROL, "RIGHTCONTROL" }, { Keys::RIGHTALT, "RIGHTALT" }, { Keys::RIGHTSUPER, "RIGHTSUPER" },
			{ Keys::MENU, "MENU" }
		});

		std::string ToString(Keys keycode)
		{
			std::unordered_map<Keys, std::string>::const_iterator element = To_String.find(keycode);
			if (element == To_String.end()) [[unlikely]] return("Unknown");
			return(element->second);
		}
	}
#endif