#include <PrecompiledHeaders.h>

#include "KeyCodes.h"

namespace GameEngine::KeyCodes
{
	#ifdef DEBUG
		std::string ToString(const Keys& keycode)
		{
			switch (keycode)
			{
				case(Keys::MOUSE_BUTTON_1): { return("MOUSE_BUTTON_1"); break; }
				case(Keys::MOUSE_BUTTON_2): { return("MOUSE_BUTTON_2"); break; }
				case(Keys::MOUSE_BUTTON_3): { return("MOUSE_BUTTON_3"); break; }
				case(Keys::MOUSE_BUTTON_4): { return("MOUSE_BUTTON_4"); break; }
				case(Keys::MOUSE_BUTTON_5): { return("MOUSE_BUTTON_5"); break; }
				case(Keys::MOUSE_BUTTON_6): { return("MOUSE_BUTTON_6"); break; }
				case(Keys::MOUSE_BUTTON_7): { return("MOUSE_BUTTON_7"); break; }
				case(Keys::MOUSE_BUTTON_8): { return("MOUSE_BUTTON_8"); break; }

				case(Keys::SPACE): { return("SPACE"); break; }
				case(Keys::APOSTROPHE): { return("APOSTROPHE"); break; }
				case(Keys::COMMA): { return("COMMA"); break; }
				case(Keys::MINUS): { return("MINUS"); break; }
				case(Keys::PERIOD): { return("PERIOD"); break; }
				case(Keys::SLASH): { return("SLASH"); break; }

				case(Keys::D0): { return("D0"); break; }
				case(Keys::D1): { return("D1"); break; }
				case(Keys::D2): { return("D2"); break; }
				case(Keys::D3): { return("D3"); break; }
				case(Keys::D4): { return("D4"); break; }
				case(Keys::D5): { return("D5"); break; }
				case(Keys::D6): { return("D6"); break; }
				case(Keys::D7): { return("D7"); break; }
				case(Keys::D8): { return("D8"); break; }
				case(Keys::D9): { return("D9"); break; }

				case(Keys::SEMICOLON): { return("SEMICOLON"); break; }
				case(Keys::EQUAL): { return("EQUAL"); break; }

				case(Keys::A): { return("A"); break; }
				case(Keys::B): { return("B"); break; }
				case(Keys::C): { return("C"); break; }
				case(Keys::D): { return("D"); break; }
				case(Keys::E): { return("E"); break; }
				case(Keys::F): { return("F"); break; }
				case(Keys::G): { return("G"); break; }
				case(Keys::H): { return("H"); break; }
				case(Keys::I): { return("I"); break; }
				case(Keys::J): { return("J"); break; }
				case(Keys::K): { return("K"); break; }
				case(Keys::L): { return("L"); break; }
				case(Keys::M): { return("M"); break; }
				case(Keys::N): { return("N"); break; }
				case(Keys::O): { return("O"); break; }
				case(Keys::P): { return("P"); break; }
				case(Keys::Q): { return("Q"); break; }
				case(Keys::R): { return("R"); break; }
				case(Keys::S): { return("S"); break; }
				case(Keys::T): { return("T"); break; }
				case(Keys::U): { return("U"); break; }
				case(Keys::V): { return("V"); break; }
				case(Keys::W): { return("W"); break; }
				case(Keys::X): { return("X"); break; }
				case(Keys::Y): { return("Y"); break; }
				case(Keys::Z): { return("Z"); break; }

				case(Keys::LEFTBRACKET): { return("LEFTBRACKET"); break; }
				case(Keys::BACKSLASH): { return("BACKSLASH"); break; }
				case(Keys::RIGHTBRACKET): { return("RIGHTBRACKET"); break; }
				case(Keys::GRAVEACCENT): { return("GRAVEACCENT"); break; }

				case(Keys::WORLD1): { return("WORLD1"); break; }
				case(Keys::WORLD2): { return("WORLD2"); break; }

				case(Keys::ESCAPE): { return("ESCAPE"); break; }
				case(Keys::ENTER): { return("ENTER"); break; }
				case(Keys::TAB): { return("TAB"); break; }
				case(Keys::BACKSPACE): { return("BACKSPACE"); break; }
				case(Keys::INSERT): { return("INSERT"); break; }
				case(Keys::DEL): { return("DELETE"); break; }
				case(Keys::RIGHT): { return("RIGHT"); break; }
				case(Keys::LEFT): { return("LEFT"); break; }
				case(Keys::DOWN): { return("DOWN"); break; }
				case(Keys::UP): { return("UP"); break; }

				case(Keys::PAGEUP): { return("PAGEUP"); break; }
				case(Keys::PAGEDOWN): { return("PAGEDOWN"); break; }
				case(Keys::HOME): { return("HOME"); break; }
				case(Keys::END): { return("END"); break; }
				case(Keys::CAPSLOCK): { return("CAPSLOCK"); break; }
				case(Keys::SCROLLLOCK): { return("SCROLLLOCK"); break; }
				case(Keys::NUMLOCK): { return("NUMLOCK"); break; }
				case(Keys::PRINTSCREEN): { return("PRINTSCREEN"); break; }
				case(Keys::PAUSE): { return("PAUSE"); break; }

				case(Keys::F1): { return("F1"); break; }
				case(Keys::F2): { return("F2"); break; }
				case(Keys::F3): { return("F3"); break; }
				case(Keys::F4): { return("F4"); break; }
				case(Keys::F5): { return("F5"); break; }
				case(Keys::F6): { return("F6"); break; }
				case(Keys::F7): { return("F7"); break; }
				case(Keys::F8): { return("F8"); break; }
				case(Keys::F9): { return("F9"); break; }
				case(Keys::F10): { return("F10"); break; }
				case(Keys::F11): { return("F11"); break; }
				case(Keys::F12): { return("F12"); break; }
				case(Keys::F13): { return("F13"); break; }
				case(Keys::F14): { return("F14"); break; }
				case(Keys::F15): { return("F15"); break; }
				case(Keys::F16): { return("F16"); break; }
				case(Keys::F17): { return("F17"); break; }
				case(Keys::F18): { return("F18"); break; }
				case(Keys::F19): { return("F19"); break; }
				case(Keys::F20): { return("F20"); break; }
				case(Keys::F21): { return("F21"); break; }
				case(Keys::F22): { return("F22"); break; }
				case(Keys::F23): { return("F23"); break; }
				case(Keys::F24): { return("F24"); break; }
				case(Keys::F25): { return("F25"); break; }

				case(Keys::KP0): { return("KP0"); break; }
				case(Keys::KP1): { return("KP1"); break; }
				case(Keys::KP2): { return("KP2"); break; }
				case(Keys::KP3): { return("KP3"); break; }
				case(Keys::KP4): { return("KP4"); break; }
				case(Keys::KP5): { return("KP5"); break; }
				case(Keys::KP6): { return("KP6"); break; }
				case(Keys::KP7): { return("KP7"); break; }
				case(Keys::KP8): { return("KP8"); break; }
				case(Keys::KP9): { return("KP9"); break; }

				case(Keys::KPDECIMAL): { return("KPDECIMAL"); break; }
				case(Keys::KPDIVIDE): { return("KPDIVIDE"); break; }
				case(Keys::KPMULTIPLY): { return("KPMULTIPLY"); break; }
				case(Keys::KPSUBTRACT): { return("KPSUBTRACT"); break; }
				case(Keys::KPADD): { return("KPADD"); break; }
				case(Keys::KPEQUAL): { return("KPEQUAL"); break; }
				case(Keys::KPENTER): { return("KPENTER"); break; }

				case(Keys::LETSHIFT): { return("LETSHIFT"); break; }
				case(Keys::LEFTCONTROL): { return("LEFTCONTROL"); break; }
				case(Keys::LEFTALT): { return("LEFTALT"); break; }
				case(Keys::LEFTSUPER): { return("LEFTSUPER"); break; }
				case(Keys::RIGHTSHIFT): { return("RIGHTSHIFT"); break; }
				case(Keys::RIGHTCONTROL): { return("RIGHTCONTROL"); break; }
				case(Keys::RIGHTALT): { return("RIGHTALT"); break; }
				case(Keys::RIGHTSUPER): { return("RIGHTSUPER"); break; }

				case(Keys::MENU): { return("MENU"); break; }

				default: { return("UNKNOWN"); }
			}
		}
	#endif
}