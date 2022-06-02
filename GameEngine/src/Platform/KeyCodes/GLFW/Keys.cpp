#include <PrecompiledHeaders.h>

#include <GLFW/glfw3.h>

#include "Keys.h"

namespace GameEngine::KeyCodes
{
	int ToGLFW(const Keys& keycode)
	{
		switch (keycode)
		{
			case(Keys::MOUSE_BUTTON_1): { return(GLFW_MOUSE_BUTTON_1); break; }
			case(Keys::MOUSE_BUTTON_2): { return(GLFW_MOUSE_BUTTON_2); break; }
			case(Keys::MOUSE_BUTTON_3): { return(GLFW_MOUSE_BUTTON_3); break; }
			case(Keys::MOUSE_BUTTON_4): { return(GLFW_MOUSE_BUTTON_4); break; }
			case(Keys::MOUSE_BUTTON_5): { return(GLFW_MOUSE_BUTTON_5); break; }
			case(Keys::MOUSE_BUTTON_6): { return(GLFW_MOUSE_BUTTON_6); break; }
			case(Keys::MOUSE_BUTTON_7): { return(GLFW_MOUSE_BUTTON_7); break; }
			case(Keys::MOUSE_BUTTON_8): { return(GLFW_MOUSE_BUTTON_8); break; }

			case(Keys::SPACE): { return(GLFW_KEY_SPACE); break; }
			case(Keys::APOSTROPHE): { return(GLFW_KEY_APOSTROPHE); break; }
			case(Keys::COMMA): { return(GLFW_KEY_COMMA); break; }
			case(Keys::MINUS): { return(GLFW_KEY_MINUS); break; }
			case(Keys::PERIOD): { return(GLFW_KEY_PERIOD); break; }
			case(Keys::SLASH): { return(GLFW_KEY_SLASH); break; }

			case(Keys::D0): { return(GLFW_KEY_0); break; }
			case(Keys::D1): { return(GLFW_KEY_1); break; }
			case(Keys::D2): { return(GLFW_KEY_2); break; }
			case(Keys::D3): { return(GLFW_KEY_3); break; }
			case(Keys::D4): { return(GLFW_KEY_4); break; }
			case(Keys::D5): { return(GLFW_KEY_5); break; }
			case(Keys::D6): { return(GLFW_KEY_6); break; }
			case(Keys::D7): { return(GLFW_KEY_7); break; }
			case(Keys::D8): { return(GLFW_KEY_8); break; }
			case(Keys::D9): { return(GLFW_KEY_9); break; }

			case(Keys::SEMICOLON): { return(GLFW_KEY_SEMICOLON); break; }
			case(Keys::EQUAL): { return(GLFW_KEY_EQUAL); break; }

			case(Keys::A): { return(GLFW_KEY_A); break; }
			case(Keys::B): { return(GLFW_KEY_B); break; }
			case(Keys::C): { return(GLFW_KEY_C); break; }
			case(Keys::D): { return(GLFW_KEY_D); break; }
			case(Keys::E): { return(GLFW_KEY_E); break; }
			case(Keys::F): { return(GLFW_KEY_F); break; }
			case(Keys::G): { return(GLFW_KEY_G); break; }
			case(Keys::H): { return(GLFW_KEY_H); break; }
			case(Keys::I): { return(GLFW_KEY_I); break; }
			case(Keys::J): { return(GLFW_KEY_J); break; }
			case(Keys::K): { return(GLFW_KEY_K); break; }
			case(Keys::L): { return(GLFW_KEY_L); break; }
			case(Keys::M): { return(GLFW_KEY_M); break; }
			case(Keys::N): { return(GLFW_KEY_N); break; }
			case(Keys::O): { return(GLFW_KEY_O); break; }
			case(Keys::P): { return(GLFW_KEY_P); break; }
			case(Keys::Q): { return(GLFW_KEY_Q); break; }
			case(Keys::R): { return(GLFW_KEY_R); break; }
			case(Keys::S): { return(GLFW_KEY_S); break; }
			case(Keys::T): { return(GLFW_KEY_T); break; }
			case(Keys::U): { return(GLFW_KEY_U); break; }
			case(Keys::V): { return(GLFW_KEY_V); break; }
			case(Keys::W): { return(GLFW_KEY_W); break; }
			case(Keys::X): { return(GLFW_KEY_X); break; }
			case(Keys::Y): { return(GLFW_KEY_Y); break; }
			case(Keys::Z): { return(GLFW_KEY_Z); break; }

			case(Keys::LEFTBRACKET): { return(GLFW_KEY_LEFT_BRACKET); break; }
			case(Keys::BACKSLASH): { return(GLFW_KEY_BACKSLASH); break; }
			case(Keys::RIGHTBRACKET): { return(GLFW_KEY_RIGHT_BRACKET); break; }
			case(Keys::GRAVEACCENT): { return(GLFW_KEY_GRAVE_ACCENT); break; }

			case(Keys::WORLD1): { return(GLFW_KEY_WORLD_1); break; }
			case(Keys::WORLD2): { return(GLFW_KEY_WORLD_2); break; }

			case(Keys::ESCAPE): { return(GLFW_KEY_ESCAPE); break; }
			case(Keys::ENTER): { return(GLFW_KEY_ENTER); break; }
			case(Keys::TAB): { return(GLFW_KEY_TAB); break; }
			case(Keys::BACKSPACE): { return(GLFW_KEY_BACKSPACE); break; }
			case(Keys::INSERT): { return(GLFW_KEY_INSERT); break; }
			case(Keys::DEL): { return(GLFW_KEY_DELETE); break; }
			case(Keys::RIGHT): { return(GLFW_KEY_RIGHT); break; }
			case(Keys::LEFT): { return(GLFW_KEY_LEFT); break; }
			case(Keys::DOWN): { return(GLFW_KEY_DOWN); break; }
			case(Keys::UP): { return(GLFW_KEY_UP); break; }

			case(Keys::PAGEUP): { return(GLFW_KEY_PAGE_UP); break; }
			case(Keys::PAGEDOWN): { return(GLFW_KEY_PAGE_DOWN); break; }
			case(Keys::HOME): { return(GLFW_KEY_HOME); break; }
			case(Keys::END): { return(GLFW_KEY_END); break; }
			case(Keys::CAPSLOCK): { return(GLFW_KEY_CAPS_LOCK); break; }
			case(Keys::SCROLLLOCK): { return(GLFW_KEY_SCROLL_LOCK); break; }
			case(Keys::NUMLOCK): { return(GLFW_KEY_NUM_LOCK); break; }
			case(Keys::PRINTSCREEN): { return(GLFW_KEY_PRINT_SCREEN); break; }
			case(Keys::PAUSE): { return(GLFW_KEY_PAUSE); break; }

			case(Keys::F1): { return(GLFW_KEY_F1); break; }
			case(Keys::F2): { return(GLFW_KEY_F2); break; }
			case(Keys::F3): { return(GLFW_KEY_F3); break; }
			case(Keys::F4): { return(GLFW_KEY_F4); break; }
			case(Keys::F5): { return(GLFW_KEY_F5); break; }
			case(Keys::F6): { return(GLFW_KEY_F6); break; }
			case(Keys::F7): { return(GLFW_KEY_F7); break; }
			case(Keys::F8): { return(GLFW_KEY_F8); break; }
			case(Keys::F9): { return(GLFW_KEY_F9); break; }
			case(Keys::F10): { return(GLFW_KEY_F10); break; }
			case(Keys::F11): { return(GLFW_KEY_F11); break; }
			case(Keys::F12): { return(GLFW_KEY_F12); break; }
			case(Keys::F13): { return(GLFW_KEY_F13); break; }
			case(Keys::F14): { return(GLFW_KEY_F14); break; }
			case(Keys::F15): { return(GLFW_KEY_F15); break; }
			case(Keys::F16): { return(GLFW_KEY_F16); break; }
			case(Keys::F17): { return(GLFW_KEY_F17); break; }
			case(Keys::F18): { return(GLFW_KEY_F18); break; }
			case(Keys::F19): { return(GLFW_KEY_F19); break; }
			case(Keys::F20): { return(GLFW_KEY_F20); break; }
			case(Keys::F21): { return(GLFW_KEY_F21); break; }
			case(Keys::F22): { return(GLFW_KEY_F22); break; }
			case(Keys::F23): { return(GLFW_KEY_F23); break; }
			case(Keys::F24): { return(GLFW_KEY_F24); break; }
			case(Keys::F25): { return(GLFW_KEY_F25); break; }

			case(Keys::KP0): { return(GLFW_KEY_KP_0); break; }
			case(Keys::KP1): { return(GLFW_KEY_KP_1); break; }
			case(Keys::KP2): { return(GLFW_KEY_KP_2); break; }
			case(Keys::KP3): { return(GLFW_KEY_KP_3); break; }
			case(Keys::KP4): { return(GLFW_KEY_KP_4); break; }
			case(Keys::KP5): { return(GLFW_KEY_KP_5); break; }
			case(Keys::KP6): { return(GLFW_KEY_KP_6); break; }
			case(Keys::KP7): { return(GLFW_KEY_KP_7); break; }
			case(Keys::KP8): { return(GLFW_KEY_KP_8); break; }
			case(Keys::KP9): { return(GLFW_KEY_KP_9); break; }

			case(Keys::KPDECIMAL): { return(GLFW_KEY_KP_DECIMAL); break; }
			case(Keys::KPDIVIDE): { return(GLFW_KEY_KP_DIVIDE); break; }
			case(Keys::KPMULTIPLY): { return(GLFW_KEY_KP_MULTIPLY); break; }
			case(Keys::KPSUBTRACT): { return(GLFW_KEY_KP_SUBTRACT); break; }
			case(Keys::KPADD): { return(GLFW_KEY_KP_ADD); break; }
			case(Keys::KPEQUAL): { return(GLFW_KEY_KP_EQUAL); break; }
			case(Keys::KPENTER): { return(GLFW_KEY_KP_ENTER); break; }

			case(Keys::LETSHIFT): { return(GLFW_KEY_LEFT_SHIFT); break; }
			case(Keys::LEFTCONTROL): { return(GLFW_KEY_LEFT_CONTROL); break; }
			case(Keys::LEFTALT): { return(GLFW_KEY_LEFT_ALT); break; }
			case(Keys::LEFTSUPER): { return(GLFW_KEY_LEFT_SUPER); break; }
			case(Keys::RIGHTSHIFT): { return(GLFW_KEY_RIGHT_SHIFT); break; }
			case(Keys::RIGHTCONTROL): { return(GLFW_KEY_RIGHT_CONTROL); break; }
			case(Keys::RIGHTALT): { return(GLFW_KEY_RIGHT_ALT); break; }
			case(Keys::RIGHTSUPER): { return(GLFW_KEY_RIGHT_SUPER); break; }

			case(Keys::MENU): { return(GLFW_KEY_MENU); break; }

			default: { return(GLFW_KEY_UNKNOWN); }
		}
	}


	Keys FromGLFW(const int& keycode)
	{
		switch (keycode)
		{
			case(GLFW_MOUSE_BUTTON_1): { return(Keys::MOUSE_BUTTON_1); break; }
			case(GLFW_MOUSE_BUTTON_2): { return(Keys::MOUSE_BUTTON_2); break; }
			case(GLFW_MOUSE_BUTTON_3): { return(Keys::MOUSE_BUTTON_3); break; }
			case(GLFW_MOUSE_BUTTON_4): { return(Keys::MOUSE_BUTTON_4); break; }
			case(GLFW_MOUSE_BUTTON_5): { return(Keys::MOUSE_BUTTON_5); break; }
			case(GLFW_MOUSE_BUTTON_6): { return(Keys::MOUSE_BUTTON_6); break; }
			case(GLFW_MOUSE_BUTTON_7): { return(Keys::MOUSE_BUTTON_7); break; }
			case(GLFW_MOUSE_BUTTON_8): { return(Keys::MOUSE_BUTTON_8); break; }

			case(GLFW_KEY_SPACE): { return(Keys::SPACE); break; }
			case(GLFW_KEY_APOSTROPHE): { return(Keys::APOSTROPHE); break; }
			case(GLFW_KEY_COMMA): { return(Keys::COMMA); break; }
			case(GLFW_KEY_MINUS): { return(Keys::MINUS); break; }
			case(GLFW_KEY_PERIOD): { return(Keys::PERIOD); break; }
			case(GLFW_KEY_SLASH): { return(Keys::SLASH); break; }

			case(GLFW_KEY_0): { return(Keys::D0); break; }
			case(GLFW_KEY_1): { return(Keys::D1); break; }
			case(GLFW_KEY_2): { return(Keys::D2); break; }
			case(GLFW_KEY_3): { return(Keys::D3); break; }
			case(GLFW_KEY_4): { return(Keys::D4); break; }
			case(GLFW_KEY_5): { return(Keys::D5); break; }
			case(GLFW_KEY_6): { return(Keys::D6); break; }
			case(GLFW_KEY_7): { return(Keys::D7); break; }
			case(GLFW_KEY_8): { return(Keys::D8); break; }
			case(GLFW_KEY_9): { return(Keys::D9); break; }

			case(GLFW_KEY_SEMICOLON): { return(Keys::SEMICOLON); break; }
			case(GLFW_KEY_EQUAL): { return(Keys::EQUAL); break; }

			case(GLFW_KEY_A): { return(Keys::A); break; }
			case(GLFW_KEY_B): { return(Keys::B); break; }
			case(GLFW_KEY_C): { return(Keys::C); break; }
			case(GLFW_KEY_D): { return(Keys::D); break; }
			case(GLFW_KEY_E): { return(Keys::E); break; }
			case(GLFW_KEY_F): { return(Keys::F); break; }
			case(GLFW_KEY_G): { return(Keys::G); break; }
			case(GLFW_KEY_H): { return(Keys::H); break; }
			case(GLFW_KEY_I): { return(Keys::I); break; }
			case(GLFW_KEY_J): { return(Keys::J); break; }
			case(GLFW_KEY_K): { return(Keys::K); break; }
			case(GLFW_KEY_L): { return(Keys::L); break; }
			case(GLFW_KEY_M): { return(Keys::M); break; }
			case(GLFW_KEY_N): { return(Keys::N); break; }
			case(GLFW_KEY_O): { return(Keys::O); break; }
			case(GLFW_KEY_P): { return(Keys::P); break; }
			case(GLFW_KEY_Q): { return(Keys::Q); break; }
			case(GLFW_KEY_R): { return(Keys::R); break; }
			case(GLFW_KEY_S): { return(Keys::S); break; }
			case(GLFW_KEY_T): { return(Keys::T); break; }
			case(GLFW_KEY_U): { return(Keys::U); break; }
			case(GLFW_KEY_V): { return(Keys::V); break; }
			case(GLFW_KEY_W): { return(Keys::W); break; }
			case(GLFW_KEY_X): { return(Keys::X); break; }
			case(GLFW_KEY_Y): { return(Keys::Y); break; }
			case(GLFW_KEY_Z): { return(Keys::Z); break; }

			case(GLFW_KEY_LEFT_BRACKET): { return(Keys::LEFTBRACKET); break; }
			case(GLFW_KEY_BACKSLASH): { return(Keys::BACKSLASH); break; }
			case(GLFW_KEY_RIGHT_BRACKET): { return(Keys::RIGHTBRACKET); break; }
			case(GLFW_KEY_GRAVE_ACCENT): { return(Keys::GRAVEACCENT); break; }

			case(GLFW_KEY_WORLD_1): { return(Keys::WORLD1); break; }
			case(GLFW_KEY_WORLD_2): { return(Keys::WORLD2); break; }

			case(GLFW_KEY_ESCAPE): { return(Keys::ESCAPE); break; }
			case(GLFW_KEY_ENTER): { return(Keys::ENTER); break; }
			case(GLFW_KEY_TAB): { return(Keys::TAB); break; }
			case(GLFW_KEY_BACKSPACE): { return(Keys::BACKSPACE); break; }
			case(GLFW_KEY_INSERT): { return(Keys::INSERT); break; }
			case(GLFW_KEY_DELETE): { return(Keys::DEL); break; }
			case(GLFW_KEY_RIGHT): { return(Keys::RIGHT); break; }
			case(GLFW_KEY_LEFT): { return(Keys::LEFT); break; }
			case(GLFW_KEY_DOWN): { return(Keys::DOWN); break; }
			case(GLFW_KEY_UP): { return(Keys::UP); break; }

			case(GLFW_KEY_PAGE_UP): { return(Keys::PAGEUP); break; }
			case(GLFW_KEY_PAGE_DOWN): { return(Keys::PAGEDOWN); break; }
			case(GLFW_KEY_HOME): { return(Keys::HOME); break; }
			case(GLFW_KEY_END): { return(Keys::END); break; }
			case(GLFW_KEY_CAPS_LOCK): { return(Keys::CAPSLOCK); break; }
			case(GLFW_KEY_SCROLL_LOCK): { return(Keys::SCROLLLOCK); break; }
			case(GLFW_KEY_NUM_LOCK): { return(Keys::NUMLOCK); break; }
			case(GLFW_KEY_PRINT_SCREEN): { return(Keys::PRINTSCREEN); break; }
			case(GLFW_KEY_PAUSE): { return(Keys::PAUSE); break; }

			case(GLFW_KEY_F1): { return(Keys::F1); break; }
			case(GLFW_KEY_F2): { return(Keys::F2); break; }
			case(GLFW_KEY_F3): { return(Keys::F3); break; }
			case(GLFW_KEY_F4): { return(Keys::F4); break; }
			case(GLFW_KEY_F5): { return(Keys::F5); break; }
			case(GLFW_KEY_F6): { return(Keys::F6); break; }
			case(GLFW_KEY_F7): { return(Keys::F7); break; }
			case(GLFW_KEY_F8): { return(Keys::F8); break; }
			case(GLFW_KEY_F9): { return(Keys::F9); break; }
			case(GLFW_KEY_F10): { return(Keys::F10); break; }
			case(GLFW_KEY_F11): { return(Keys::F11); break; }
			case(GLFW_KEY_F12): { return(Keys::F12); break; }
			case(GLFW_KEY_F13): { return(Keys::F13); break; }
			case(GLFW_KEY_F14): { return(Keys::F14); break; }
			case(GLFW_KEY_F15): { return(Keys::F15); break; }
			case(GLFW_KEY_F16): { return(Keys::F16); break; }
			case(GLFW_KEY_F17): { return(Keys::F17); break; }
			case(GLFW_KEY_F18): { return(Keys::F18); break; }
			case(GLFW_KEY_F19): { return(Keys::F19); break; }
			case(GLFW_KEY_F20): { return(Keys::F20); break; }
			case(GLFW_KEY_F21): { return(Keys::F21); break; }
			case(GLFW_KEY_F22): { return(Keys::F22); break; }
			case(GLFW_KEY_F23): { return(Keys::F23); break; }
			case(GLFW_KEY_F24): { return(Keys::F24); break; }
			case(GLFW_KEY_F25): { return(Keys::F25); break; }

			case(GLFW_KEY_KP_0): { return(Keys::KP0); break; }
			case(GLFW_KEY_KP_1): { return(Keys::KP1); break; }
			case(GLFW_KEY_KP_2): { return(Keys::KP2); break; }
			case(GLFW_KEY_KP_3): { return(Keys::KP3); break; }
			case(GLFW_KEY_KP_4): { return(Keys::KP4); break; }
			case(GLFW_KEY_KP_5): { return(Keys::KP5); break; }
			case(GLFW_KEY_KP_6): { return(Keys::KP6); break; }
			case(GLFW_KEY_KP_7): { return(Keys::KP7); break; }
			case(GLFW_KEY_KP_8): { return(Keys::KP8); break; }
			case(GLFW_KEY_KP_9): { return(Keys::KP9); break; }

			case(GLFW_KEY_KP_DECIMAL): { return(Keys::KPDECIMAL); break; }
			case(GLFW_KEY_KP_DIVIDE): { return(Keys::KPDIVIDE); break; }
			case(GLFW_KEY_KP_MULTIPLY): { return(Keys::KPMULTIPLY); break; }
			case(GLFW_KEY_KP_SUBTRACT): { return(Keys::KPSUBTRACT); break; }
			case(GLFW_KEY_KP_ADD): { return(Keys::KPADD); break; }
			case(GLFW_KEY_KP_EQUAL): { return(Keys::KPEQUAL); break; }
			case(GLFW_KEY_KP_ENTER): { return(Keys::KPENTER); break; }

			case(GLFW_KEY_LEFT_SHIFT): { return(Keys::LETSHIFT); break; }
			case(GLFW_KEY_LEFT_CONTROL): { return(Keys::LEFTCONTROL); break; }
			case(GLFW_KEY_LEFT_ALT): { return(Keys::LEFTALT); break; }
			case(GLFW_KEY_LEFT_SUPER): { return(Keys::LEFTSUPER); break; }
			case(GLFW_KEY_RIGHT_SHIFT): { return(Keys::RIGHTSHIFT); break; }
			case(GLFW_KEY_RIGHT_CONTROL): { return(Keys::RIGHTCONTROL); break; }
			case(GLFW_KEY_RIGHT_ALT): { return(Keys::RIGHTALT); break; }
			case(GLFW_KEY_RIGHT_SUPER): { return(Keys::RIGHTSUPER); break; }

			case(GLFW_KEY_MENU): { return(Keys::MENU); break; }

			default: { return(Keys::UNKNOWN); }
		}
	}
}