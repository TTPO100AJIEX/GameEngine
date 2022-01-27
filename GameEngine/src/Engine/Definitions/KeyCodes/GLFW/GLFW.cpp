#include <PrecompiledHeaders.h>

#include "GLFW.h"

namespace Engine::KeyCodes
{
	GLFWKeys ToGLFW(Keys keycode)
	{
		switch(keycode)
		{
			case(Keys::MOUSE_BUTTON_1): { return(GLFWKeys::MouseButton1); break; }
			case(Keys::MOUSE_BUTTON_2): { return(GLFWKeys::MouseButton2); break; }
			case(Keys::MOUSE_BUTTON_3): { return(GLFWKeys::MouseButton3); break; }
			case(Keys::MOUSE_BUTTON_4): { return(GLFWKeys::MouseButton4); break; }
			case(Keys::MOUSE_BUTTON_5): { return(GLFWKeys::MouseButton5); break; }
			case(Keys::MOUSE_BUTTON_6): { return(GLFWKeys::MouseButton6); break; }
			case(Keys::MOUSE_BUTTON_7): { return(GLFWKeys::MouseButton7); break; }
			case(Keys::MOUSE_BUTTON_8): { return(GLFWKeys::MouseButton8); break; }

			case(Keys::SPACE): { return(GLFWKeys::Space); break; }
			case(Keys::APOSTROPHE): { return(GLFWKeys::Apostrophe); break; }
			case(Keys::COMMA): { return(GLFWKeys::Comma); break; }
			case(Keys::MINUS): { return(GLFWKeys::Minus); break; }
			case(Keys::PERIOD): { return(GLFWKeys::Period); break; }
			case(Keys::SLASH): { return(GLFWKeys::Slash); break; }

			case(Keys::D0): { return(GLFWKeys::D0); break; }
			case(Keys::D1): { return(GLFWKeys::D1); break; }
			case(Keys::D2): { return(GLFWKeys::D2); break; }
			case(Keys::D3): { return(GLFWKeys::D3); break; }
			case(Keys::D4): { return(GLFWKeys::D4); break; }
			case(Keys::D5): { return(GLFWKeys::D5); break; }
			case(Keys::D6): { return(GLFWKeys::D6); break; }
			case(Keys::D7): { return(GLFWKeys::D7); break; }
			case(Keys::D8): { return(GLFWKeys::D8); break; }
			case(Keys::D9): { return(GLFWKeys::D9); break; }

			case(Keys::SEMICOLON): { return(GLFWKeys::Semicolon); break; }
			case(Keys::EQUAL): { return(GLFWKeys::Equal); break; }

			case(Keys::A): { return(GLFWKeys::A); break; }
			case(Keys::B): { return(GLFWKeys::B); break; }
			case(Keys::C): { return(GLFWKeys::C); break; }
			case(Keys::D): { return(GLFWKeys::D); break; }
			case(Keys::E): { return(GLFWKeys::E); break; }
			case(Keys::F): { return(GLFWKeys::F); break; }
			case(Keys::G): { return(GLFWKeys::G); break; }
			case(Keys::H): { return(GLFWKeys::H); break; }
			case(Keys::I): { return(GLFWKeys::I); break; }
			case(Keys::J): { return(GLFWKeys::J); break; }
			case(Keys::K): { return(GLFWKeys::K); break; }
			case(Keys::L): { return(GLFWKeys::L); break; }
			case(Keys::M): { return(GLFWKeys::M); break; }
			case(Keys::N): { return(GLFWKeys::N); break; }
			case(Keys::O): { return(GLFWKeys::O); break; }
			case(Keys::P): { return(GLFWKeys::P); break; }
			case(Keys::Q): { return(GLFWKeys::Q); break; }
			case(Keys::R): { return(GLFWKeys::R); break; }
			case(Keys::S): { return(GLFWKeys::S); break; }
			case(Keys::T): { return(GLFWKeys::T); break; }
			case(Keys::U): { return(GLFWKeys::U); break; }
			case(Keys::V): { return(GLFWKeys::V); break; }
			case(Keys::W): { return(GLFWKeys::W); break; }
			case(Keys::X): { return(GLFWKeys::X); break; }
			case(Keys::Y): { return(GLFWKeys::Y); break; }
			case(Keys::Z): { return(GLFWKeys::Z); break; }

			case(Keys::LEFTBRACKET): { return(GLFWKeys::LeftBracket); break; }
			case(Keys::BACKSLASH): { return(GLFWKeys::Backslash); break; }
			case(Keys::RIGHTBRACKET): { return(GLFWKeys::RightBracket); break; }
			case(Keys::GRAVEACCENT): { return(GLFWKeys::GraveAccent); break; }

			case(Keys::WORLD1): { return(GLFWKeys::World1); break; }
			case(Keys::WORLD2): { return(GLFWKeys::World2); break; }

			case(Keys::ESCAPE): { return(GLFWKeys::Escape); break; }
			case(Keys::ENTER): { return(GLFWKeys::Enter); break; }
			case(Keys::TAB): { return(GLFWKeys::Tab); break; }
			case(Keys::BACKSPACE): { return(GLFWKeys::Backspace); break; }
			case(Keys::INSERT): { return(GLFWKeys::Insert); break; }
			case(Keys::DEL): { return(GLFWKeys::Delete); break; }
			case(Keys::RIGHT): { return(GLFWKeys::Right); break; }
			case(Keys::LEFT): { return(GLFWKeys::Left); break; }
			case(Keys::DOWN): { return(GLFWKeys::Down); break; }
			case(Keys::UP): { return(GLFWKeys::Up); break; }

			case(Keys::PAGEUP): { return(GLFWKeys::PageUp); break; }
			case(Keys::PAGEDOWN): { return(GLFWKeys::PageDown); break; }
			case(Keys::HOME): { return(GLFWKeys::Home); break; }
			case(Keys::END): { return(GLFWKeys::End); break; }
			case(Keys::CAPSLOCK): { return(GLFWKeys::CapsLock); break; }
			case(Keys::SCROLLLOCK): { return(GLFWKeys::ScrollLock); break; }
			case(Keys::NUMLOCK): { return(GLFWKeys::NumLock); break; }
			case(Keys::PRINTSCREEN): { return(GLFWKeys::PrintScreen); break; }
			case(Keys::PAUSE): { return(GLFWKeys::Pause); break; }

			case(Keys::F1): { return(GLFWKeys::F1); break; }
			case(Keys::F2): { return(GLFWKeys::F2); break; }
			case(Keys::F3): { return(GLFWKeys::F3); break; }
			case(Keys::F4): { return(GLFWKeys::F4); break; }
			case(Keys::F5): { return(GLFWKeys::F5); break; }
			case(Keys::F6): { return(GLFWKeys::F6); break; }
			case(Keys::F7): { return(GLFWKeys::F7); break; }
			case(Keys::F8): { return(GLFWKeys::F8); break; }
			case(Keys::F9): { return(GLFWKeys::F9); break; }
			case(Keys::F10): { return(GLFWKeys::F10); break; }
			case(Keys::F11): { return(GLFWKeys::F11); break; }
			case(Keys::F12): { return(GLFWKeys::F12); break; }
			case(Keys::F13): { return(GLFWKeys::F13); break; }
			case(Keys::F14): { return(GLFWKeys::F14); break; }
			case(Keys::F15): { return(GLFWKeys::F15); break; }
			case(Keys::F16): { return(GLFWKeys::F16); break; }
			case(Keys::F17): { return(GLFWKeys::F17); break; }
			case(Keys::F18): { return(GLFWKeys::F18); break; }
			case(Keys::F19): { return(GLFWKeys::F19); break; }
			case(Keys::F20): { return(GLFWKeys::F20); break; }
			case(Keys::F21): { return(GLFWKeys::F21); break; }
			case(Keys::F22): { return(GLFWKeys::F22); break; }
			case(Keys::F23): { return(GLFWKeys::F23); break; }
			case(Keys::F24): { return(GLFWKeys::F24); break; }
			case(Keys::F25): { return(GLFWKeys::F25); break; }

			case(Keys::KP0): { return(GLFWKeys::KP0); break; }
			case(Keys::KP1): { return(GLFWKeys::KP1); break; }
			case(Keys::KP2): { return(GLFWKeys::KP2); break; }
			case(Keys::KP3): { return(GLFWKeys::KP3); break; }
			case(Keys::KP4): { return(GLFWKeys::KP4); break; }
			case(Keys::KP5): { return(GLFWKeys::KP5); break; }
			case(Keys::KP6): { return(GLFWKeys::KP6); break; }
			case(Keys::KP7): { return(GLFWKeys::KP7); break; }
			case(Keys::KP8): { return(GLFWKeys::KP8); break; }
			case(Keys::KP9): { return(GLFWKeys::KP9); break; }

			case(Keys::KPDECIMAL): { return(GLFWKeys::KPDecimal); break; }
			case(Keys::KPDIVIDE): { return(GLFWKeys::KPDivide); break; }
			case(Keys::KPMULTIPLY): { return(GLFWKeys::KPMultiply); break; }
			case(Keys::KPSUBTRACT): { return(GLFWKeys::KPSubtract); break; }
			case(Keys::KPADD): { return(GLFWKeys::KPAdd); break; }
			case(Keys::KPEQUAL): { return(GLFWKeys::KPEqual); break; }
			case(Keys::KPENTER): { return(GLFWKeys::KPEnter); break; }

			case(Keys::LETSHIFT): { return(GLFWKeys::LeftShift); break; }
			case(Keys::LEFTCONTROL): { return(GLFWKeys::LeftControl); break; }
			case(Keys::LEFTALT): { return(GLFWKeys::LeftAlt); break; }
			case(Keys::LEFTSUPER): { return(GLFWKeys::LeftSuper); break; }
			case(Keys::RIGHTSHIFT): { return(GLFWKeys::RightShift); break; }
			case(Keys::RIGHTCONTROL): { return(GLFWKeys::RightControl); break; }
			case(Keys::RIGHTALT): { return(GLFWKeys::RightAlt); break; }
			case(Keys::RIGHTSUPER): { return(GLFWKeys::RightSuper); break; }

			case(Keys::MENU): { return(GLFWKeys::Menu); break; }

			default: { return(GLFWKeys::Unknown); }
		}
	}


	Keys FromGLFW(GLFWKeys keycode)
	{
		switch(keycode)
		{
			case(GLFWKeys::MouseButton1): { return(Keys::MOUSE_BUTTON_1); break; }
			case(GLFWKeys::MouseButton2): { return(Keys::MOUSE_BUTTON_2); break; }
			case(GLFWKeys::MouseButton3): { return(Keys::MOUSE_BUTTON_3); break; }
			case(GLFWKeys::MouseButton4): { return(Keys::MOUSE_BUTTON_4); break; }
			case(GLFWKeys::MouseButton5): { return(Keys::MOUSE_BUTTON_5); break; }
			case(GLFWKeys::MouseButton6): { return(Keys::MOUSE_BUTTON_6); break; }
			case(GLFWKeys::MouseButton7): { return(Keys::MOUSE_BUTTON_7); break; }
			case(GLFWKeys::MouseButton8): { return(Keys::MOUSE_BUTTON_8); break; }

			case(GLFWKeys::Space): { return(Keys::SPACE); break; }
			case(GLFWKeys::Apostrophe): { return(Keys::APOSTROPHE); break; }
			case(GLFWKeys::Comma): { return(Keys::COMMA); break; }
			case(GLFWKeys::Minus): { return(Keys::MINUS); break; }
			case(GLFWKeys::Period): { return(Keys::PERIOD); break; }
			case(GLFWKeys::Slash): { return(Keys::SLASH); break; }

			case(GLFWKeys::D0): { return(Keys::D0); break; }
			case(GLFWKeys::D1): { return(Keys::D1); break; }
			case(GLFWKeys::D2): { return(Keys::D2); break; }
			case(GLFWKeys::D3): { return(Keys::D3); break; }
			case(GLFWKeys::D4): { return(Keys::D4); break; }
			case(GLFWKeys::D5): { return(Keys::D5); break; }
			case(GLFWKeys::D6): { return(Keys::D6); break; }
			case(GLFWKeys::D7): { return(Keys::D7); break; }
			case(GLFWKeys::D8): { return(Keys::D8); break; }
			case(GLFWKeys::D9): { return(Keys::D9); break; }

			case(GLFWKeys::Semicolon): { return(Keys::SEMICOLON); break; }
			case(GLFWKeys::Equal): { return(Keys::EQUAL); break; }

			case(GLFWKeys::A): { return(Keys::A); break; }
			case(GLFWKeys::B): { return(Keys::B); break; }
			case(GLFWKeys::C): { return(Keys::C); break; }
			case(GLFWKeys::D): { return(Keys::D); break; }
			case(GLFWKeys::E): { return(Keys::E); break; }
			case(GLFWKeys::F): { return(Keys::F); break; }
			case(GLFWKeys::G): { return(Keys::G); break; }
			case(GLFWKeys::H): { return(Keys::H); break; }
			case(GLFWKeys::I): { return(Keys::I); break; }
			case(GLFWKeys::J): { return(Keys::J); break; }
			case(GLFWKeys::K): { return(Keys::K); break; }
			case(GLFWKeys::L): { return(Keys::L); break; }
			case(GLFWKeys::M): { return(Keys::M); break; }
			case(GLFWKeys::N): { return(Keys::N); break; }
			case(GLFWKeys::O): { return(Keys::O); break; }
			case(GLFWKeys::P): { return(Keys::P); break; }
			case(GLFWKeys::Q): { return(Keys::Q); break; }
			case(GLFWKeys::R): { return(Keys::R); break; }
			case(GLFWKeys::S): { return(Keys::S); break; }
			case(GLFWKeys::T): { return(Keys::T); break; }
			case(GLFWKeys::U): { return(Keys::U); break; }
			case(GLFWKeys::V): { return(Keys::V); break; }
			case(GLFWKeys::W): { return(Keys::W); break; }
			case(GLFWKeys::X): { return(Keys::X); break; }
			case(GLFWKeys::Y): { return(Keys::Y); break; }
			case(GLFWKeys::Z): { return(Keys::Z); break; }

			case(GLFWKeys::LeftBracket): { return(Keys::LEFTBRACKET); break; }
			case(GLFWKeys::Backslash): { return(Keys::BACKSLASH); break; }
			case(GLFWKeys::RightBracket): { return(Keys::RIGHTBRACKET); break; }
			case(GLFWKeys::GraveAccent): { return(Keys::GRAVEACCENT); break; }

			case(GLFWKeys::World1): { return(Keys::WORLD1); break; }
			case(GLFWKeys::World2): { return(Keys::WORLD2); break; }

			case(GLFWKeys::Escape): { return(Keys::ESCAPE); break; }
			case(GLFWKeys::Enter): { return(Keys::ENTER); break; }
			case(GLFWKeys::Tab): { return(Keys::TAB); break; }
			case(GLFWKeys::Backspace): { return(Keys::BACKSPACE); break; }
			case(GLFWKeys::Insert): { return(Keys::INSERT); break; }
			case(GLFWKeys::Delete): { return(Keys::DEL); break; }
			case(GLFWKeys::Right): { return(Keys::RIGHT); break; }
			case(GLFWKeys::Left): { return(Keys::LEFT); break; }
			case(GLFWKeys::Down): { return(Keys::DOWN); break; }
			case(GLFWKeys::Up): { return(Keys::UP); break; }

			case(GLFWKeys::PageUp): { return(Keys::PAGEUP); break; }
			case(GLFWKeys::PageDown): { return(Keys::PAGEDOWN); break; }
			case(GLFWKeys::Home): { return(Keys::HOME); break; }
			case(GLFWKeys::End): { return(Keys::END); break; }
			case(GLFWKeys::CapsLock): { return(Keys::CAPSLOCK); break; }
			case(GLFWKeys::ScrollLock): { return(Keys::SCROLLLOCK); break; }
			case(GLFWKeys::NumLock): { return(Keys::NUMLOCK); break; }
			case(GLFWKeys::PrintScreen): { return(Keys::PRINTSCREEN); break; }
			case(GLFWKeys::Pause): { return(Keys::PAUSE); break; }

			case(GLFWKeys::F1): { return(Keys::F1); break; }
			case(GLFWKeys::F2): { return(Keys::F2); break; }
			case(GLFWKeys::F3): { return(Keys::F3); break; }
			case(GLFWKeys::F4): { return(Keys::F4); break; }
			case(GLFWKeys::F5): { return(Keys::F5); break; }
			case(GLFWKeys::F6): { return(Keys::F6); break; }
			case(GLFWKeys::F7): { return(Keys::F7); break; }
			case(GLFWKeys::F8): { return(Keys::F8); break; }
			case(GLFWKeys::F9): { return(Keys::F9); break; }
			case(GLFWKeys::F10): { return(Keys::F10); break; }
			case(GLFWKeys::F11): { return(Keys::F11); break; }
			case(GLFWKeys::F12): { return(Keys::F12); break; }
			case(GLFWKeys::F13): { return(Keys::F13); break; }
			case(GLFWKeys::F14): { return(Keys::F14); break; }
			case(GLFWKeys::F15): { return(Keys::F15); break; }
			case(GLFWKeys::F16): { return(Keys::F16); break; }
			case(GLFWKeys::F17): { return(Keys::F17); break; }
			case(GLFWKeys::F18): { return(Keys::F18); break; }
			case(GLFWKeys::F19): { return(Keys::F19); break; }
			case(GLFWKeys::F20): { return(Keys::F20); break; }
			case(GLFWKeys::F21): { return(Keys::F21); break; }
			case(GLFWKeys::F22): { return(Keys::F22); break; }
			case(GLFWKeys::F23): { return(Keys::F23); break; }
			case(GLFWKeys::F24): { return(Keys::F24); break; }
			case(GLFWKeys::F25): { return(Keys::F25); break; }

			case(GLFWKeys::KP0): { return(Keys::KP0); break; }
			case(GLFWKeys::KP1): { return(Keys::KP1); break; }
			case(GLFWKeys::KP2): { return(Keys::KP2); break; }
			case(GLFWKeys::KP3): { return(Keys::KP3); break; }
			case(GLFWKeys::KP4): { return(Keys::KP4); break; }
			case(GLFWKeys::KP5): { return(Keys::KP5); break; }
			case(GLFWKeys::KP6): { return(Keys::KP6); break; }
			case(GLFWKeys::KP7): { return(Keys::KP7); break; }
			case(GLFWKeys::KP8): { return(Keys::KP8); break; }
			case(GLFWKeys::KP9): { return(Keys::KP9); break; }

			case(GLFWKeys::KPDecimal): { return(Keys::KPDECIMAL); break; }
			case(GLFWKeys::KPDivide): { return(Keys::KPDIVIDE); break; }
			case(GLFWKeys::KPMultiply): { return(Keys::KPMULTIPLY); break; }
			case(GLFWKeys::KPSubtract): { return(Keys::KPSUBTRACT); break; }
			case(GLFWKeys::KPAdd): { return(Keys::KPADD); break; }
			case(GLFWKeys::KPEqual): { return(Keys::KPEQUAL); break; }
			case(GLFWKeys::KPEnter): { return(Keys::KPENTER); break; }

			case(GLFWKeys::LeftShift): { return(Keys::LETSHIFT); break; }
			case(GLFWKeys::LeftControl): { return(Keys::LEFTCONTROL); break; }
			case(GLFWKeys::LeftAlt): { return(Keys::LEFTALT); break; }
			case(GLFWKeys::LeftSuper): { return(Keys::LEFTSUPER); break; }
			case(GLFWKeys::RightShift): { return(Keys::RIGHTSHIFT); break; }
			case(GLFWKeys::RightControl): { return(Keys::RIGHTCONTROL); break; }
			case(GLFWKeys::RightAlt): { return(Keys::RIGHTALT); break; }
			case(GLFWKeys::RightSuper): { return(Keys::RIGHTSUPER); break; }

			case(GLFWKeys::Menu): { return(Keys::MENU); break; }

			default: { return(Keys::UNKNOWN); }
		}
	}
}