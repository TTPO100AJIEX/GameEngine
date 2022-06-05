#pragma once

struct GLFWwindow;
namespace GameEngine
{
	class Event;
}

namespace GameEngine
{
	class Window
	{
	private:
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		std::function<void(Event&)> EventCallback;

		GLFWwindow* l_Window;

		void RegisterEvents() const;

	public:
		Window(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback);
		~Window();

		void Use(bool vSync) const;
		static const void* GetProcAdressFunction();

		std::pair<unsigned int, unsigned int> GetSize() const;
		void SetSize(unsigned int width, unsigned int height);


		void Update();


		bool IsKeyPressed(const KeyCodes::Keys& keycode) const;
		bool IsMouseButtonPressed(const KeyCodes::Keys& keycode) const;
		std::pair<double, double> GetMousePosition() const;
		double GetMouseX() const;
		double GetMouseY() const;
	};
}