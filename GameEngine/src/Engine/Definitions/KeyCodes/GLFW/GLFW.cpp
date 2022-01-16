#include <PrecompiledHeaders.h>

#include "GLFW.h"
#include "../../KeyCodes.h"

namespace Engine::KeyCodes
{
	const std::unordered_map <Keys, GLFWKeys> To_GLFW({
		{ Keys::MOUSE_BUTTON_1, GLFWKeys::MouseButton1 }, { Keys::MOUSE_BUTTON_2, GLFWKeys::MouseButton2 }, { Keys::MOUSE_BUTTON_3, GLFWKeys::MouseButton3 }, 
			{ Keys::MOUSE_BUTTON_4, GLFWKeys::MouseButton4 }, { Keys::MOUSE_BUTTON_5, GLFWKeys::MouseButton5 }, { Keys::MOUSE_BUTTON_6, GLFWKeys::MouseButton6 }, 
			{ Keys::MOUSE_BUTTON_7, GLFWKeys::MouseButton7 }, { Keys::MOUSE_BUTTON_8, GLFWKeys::MouseButton8 },

		{ Keys::SPACE, GLFWKeys::Space }, { Keys::APOSTROPHE, GLFWKeys::Apostrophe }, { Keys::COMMA, GLFWKeys::Comma }, { Keys::MINUS, GLFWKeys::Minus },
			{ Keys::PERIOD, GLFWKeys::Period }, { Keys::SLASH, GLFWKeys::Slash },

		{ Keys::D0, GLFWKeys::D0 }, { Keys::D1, GLFWKeys::D1 }, { Keys::D2, GLFWKeys::D2 }, { Keys::D3, GLFWKeys::D3 }, { Keys::D4, GLFWKeys::D4 }, { Keys::D5, GLFWKeys::D5 }, 
			{ Keys::D6, GLFWKeys::D6 }, { Keys::D7, GLFWKeys::D7 }, { Keys::D8, GLFWKeys::D8 }, { Keys::D9, GLFWKeys::D9 },

		{ Keys::SEMICOLON, GLFWKeys::Semicolon }, { Keys::EQUAL, GLFWKeys::Equal },

		{ Keys::A, GLFWKeys::A }, { Keys::B, GLFWKeys::B }, { Keys::C, GLFWKeys::C }, { Keys::D, GLFWKeys::D }, { Keys::E, GLFWKeys::E }, { Keys::F, GLFWKeys::F }, 
			{ Keys::G, GLFWKeys::G }, { Keys::H, GLFWKeys::H }, { Keys::I, GLFWKeys::I }, { Keys::J, GLFWKeys::J }, { Keys::K, GLFWKeys::K }, { Keys::L, GLFWKeys::L }, { Keys::M, GLFWKeys::M }, 
			{ Keys::N, GLFWKeys::N }, { Keys::O, GLFWKeys::O }, { Keys::P, GLFWKeys::P }, { Keys::Q, GLFWKeys::Q }, { Keys::R, GLFWKeys::R }, { Keys::S, GLFWKeys::S }, { Keys::T, GLFWKeys::T }, 
			{ Keys::U, GLFWKeys::U }, { Keys::V, GLFWKeys::V }, { Keys::W, GLFWKeys::W }, { Keys::X, GLFWKeys::X }, { Keys::Y, GLFWKeys::Y }, { Keys::Z, GLFWKeys::Z },
			
		{ Keys::LEFTBRACKET, GLFWKeys::LeftBracket }, { Keys::BACKSLASH, GLFWKeys::Backslash }, { Keys::RIGHTBRACKET, GLFWKeys::RightBracket }, { Keys::GRAVEACCENT, GLFWKeys::GraveAccent },

		{ Keys::WORLD1, GLFWKeys::World1 }, { Keys::WORLD2, GLFWKeys::World2 },

		{ Keys::ESCAPE, GLFWKeys::Escape }, { Keys::ENTER, GLFWKeys::Enter }, { Keys::TAB, GLFWKeys::Tab }, { Keys::BACKSPACE, GLFWKeys::Backspace }, { Keys::INSERT, GLFWKeys::Insert }, { Keys::DEL, GLFWKeys::Delete },
			{ Keys::RIGHT, GLFWKeys::Right }, { Keys::LEFT, GLFWKeys::Left }, { Keys::DOWN, GLFWKeys::Down }, { Keys::UP, GLFWKeys::Up },

		{ Keys::PAGEUP, GLFWKeys::PageUp }, { Keys::PAGEDOWN, GLFWKeys::PageDown }, { Keys::HOME, GLFWKeys::Home }, { Keys::END, GLFWKeys::End }, { Keys::CAPSLOCK, GLFWKeys::CapsLock }, 
			{ Keys::SCROLLLOCK, GLFWKeys::ScrollLock }, { Keys::NUMLOCK, GLFWKeys::NumLock }, { Keys::PRINTSCREEN, GLFWKeys::PrintScreen }, { Keys::PAUSE, GLFWKeys::Pause },

		{ Keys::F1, GLFWKeys::F1 }, { Keys::F2, GLFWKeys::F2 }, { Keys::F3, GLFWKeys::F3 }, { Keys::F4, GLFWKeys::F4 }, { Keys::F5, GLFWKeys::F5 }, 
			{ Keys::F6, GLFWKeys::F6 }, { Keys::F7, GLFWKeys::F7 }, { Keys::F8, GLFWKeys::F8 }, { Keys::F9, GLFWKeys::F9 }, { Keys::F10, GLFWKeys::F10 }, 
			{ Keys::F11, GLFWKeys::F11 }, { Keys::F12, GLFWKeys::F12 }, { Keys::F13, GLFWKeys::F13 }, { Keys::F14, GLFWKeys::F14 }, { Keys::F15, GLFWKeys::F15 }, 
			{ Keys::F16, GLFWKeys::F16 }, { Keys::F17, GLFWKeys::F17 }, { Keys::F18, GLFWKeys::F18 }, { Keys::F19, GLFWKeys::F19 }, { Keys::F20, GLFWKeys::F20 }, 
			{ Keys::F21, GLFWKeys::F21 }, { Keys::F22, GLFWKeys::F22 }, { Keys::F23, GLFWKeys::F23 }, { Keys::F24, GLFWKeys::F24 }, { Keys::F25, GLFWKeys::F25 },
			
		{ Keys::KP0, GLFWKeys::KP0 }, { Keys::KP1, GLFWKeys::KP1 }, { Keys::KP2, GLFWKeys::KP2 }, { Keys::KP3, GLFWKeys::KP3 }, { Keys::KP4, GLFWKeys::KP4 }, 
			{ Keys::KP5, GLFWKeys::KP5 }, { Keys::KP6, GLFWKeys::KP6 }, { Keys::KP7, GLFWKeys::KP7 }, { Keys::KP8, GLFWKeys::KP8 }, { Keys::KP9, GLFWKeys::KP9 },

		{ Keys::KPDECIMAL, GLFWKeys::KPDecimal }, { Keys::KPDIVIDE, GLFWKeys::KPDivide }, { Keys::KPMULTIPLY, GLFWKeys::KPMultiply }, { Keys::KPSUBTRACT, GLFWKeys::KPSubtract }, 
			{ Keys::KPADD, GLFWKeys::KPAdd }, { Keys::KPEQUAL, GLFWKeys::KPEqual }, { Keys::KPENTER, GLFWKeys::KPEnter },

		{ Keys::LETSHIFT, GLFWKeys::LeftShift }, { Keys::LEFTCONTROL, GLFWKeys::LeftControl }, { Keys::LEFTALT, GLFWKeys::LeftAlt }, { Keys::LEFTSUPER, GLFWKeys::LeftSuper }, 
			{ Keys::RIGHTSHFIT, GLFWKeys::RightShift }, { Keys::RIGHTCONTROL, GLFWKeys::RightControl }, { Keys::RIGHTALT, GLFWKeys::RightAlt }, { Keys::RIGHTSUPER, GLFWKeys::RightSuper },
		{ Keys::MENU, GLFWKeys::Menu }
	});
	const std::unordered_map <GLFWKeys, Keys> From_GLFW = traverse_unordered_map<GLFWKeys, Keys>(To_GLFW);

		
	API inline GLFWKeys ToGLFW(Keys keycode)
	{
		std::unordered_map<Keys, GLFWKeys>::const_iterator element = To_GLFW.find(keycode);
		if (element == To_GLFW.end()) return(GLFWKeys::Unknown);
		return(element->second);
	}
	API inline Keys FromGLFW(GLFWKeys keycode)
	{
		std::unordered_map<GLFWKeys, Keys>::const_iterator element = From_GLFW.find(keycode);
		if (element == From_GLFW.end()) return(Keys::UNKNOWN);
		return(element->second);
	}
}