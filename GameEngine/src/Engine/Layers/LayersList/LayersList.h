#pragma once

#include "../Layer/Layer.h"

namespace Engine
{
	class LayersList
	{
	private:
		std::vector <Layer*> Layers;
	public:
		LayersList();
		~LayersList();

		inline std::vector <Layer*>::iterator begin() { return(Layers.begin()); }
		inline std::vector <Layer*>::iterator end() { return(Layers.end()); }
		inline std::vector <Layer*>::reverse_iterator rbegin() { return(Layers.rbegin()); }
		inline std::vector <Layer*>::reverse_iterator rend() { return(Layers.rend()); }

		void Push(Layer* layer, int index);
		void Remove(unsigned int index);
	};
}