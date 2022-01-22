#pragma once

#include "../../Events/Events.h"

namespace Engine
{
	class Layer
	{
	protected: 
		unsigned int ID;
	public:
		Layer() { ID = UINT_MAX; };
		virtual ~Layer() = default;

		virtual void OnAdd() {};
		virtual void OnRemove() {};
		virtual void Update() {};
		virtual void OnEvent(Event& New_Event) {};

		void SetID(unsigned int id) { ID = id; }
		inline unsigned int GetID() { return(ID); }
	};
}