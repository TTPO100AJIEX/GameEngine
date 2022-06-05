#pragma once

namespace GameEngine::KeyCodes
{
	int ToGLFW(const Keys& keycode);
	Keys FromGLFW(const int& keycode);
}