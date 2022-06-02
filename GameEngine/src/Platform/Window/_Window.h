#pragma once

namespace GameEngine
{
	class Event;
}

namespace GameEngine
{
	class _Window
	{
	protected:
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		std::function<void(Event&)> EventCallback;

		virtual void RegisterEvents() const = 0;

	public:
		_Window(unsigned int width, unsigned int height, const std::string& title, std::function<void(Event&)> event_callback) :
			Width(width), Height(height), Title(title), EventCallback(event_callback) {};
		virtual ~_Window() = default;

		virtual void Use(bool vSync) const = 0;
		//virtual const void* GetProcAdressFunction() const = 0;

		std::pair<unsigned int, unsigned int> GetSize() const { return(std::make_pair(this->Width, this->Height)); }
		virtual void SetSize(unsigned int width, unsigned int height) = 0;


		virtual void Update() = 0;


		virtual bool IsKeyPressed(const KeyCodes::Keys& keycode) const = 0;
		virtual bool IsMouseButtonPressed(const KeyCodes::Keys& keycode) const = 0;
		virtual std::pair<double, double> GetMousePosition() const = 0;
		virtual double GetMouseX() const = 0;
		virtual double GetMouseY() const = 0;
	};
}