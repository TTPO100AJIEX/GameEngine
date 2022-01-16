#include <PrecompiledHeaders.h>

#include "LayersList.h"

namespace Engine
{
	LayersList::LayersList()
	{

	}
	LayersList::~LayersList()
	{
		for (int i = 0; i < Layers.size(); i++)
		{
			Layers[i]->OnRemove();
			delete Layers[i];
		}
	}

	void LayersList::Push(Layer* layer, int index)
	{
		Layers.emplace(Layers.begin() + std::clamp(index, 0, (int)(Layers.size())), layer);
		for (int i = 0; i < Layers.size(); i++) Layers[i]->SetID(i);
		layer->OnAdd();
	}
	void LayersList::Remove(unsigned int index)
	{
		if (index >= Layers.size()) [[unlikely]]
		{
			ENGINE_ERROR("Failed to remove a layer. No layer with ID {0} found!", index);
			return;
		}
		Layers[index]->OnRemove();
		delete Layers[index];
		Layers.erase(Layers.begin() + index);
		for (int i = 0; i < Layers.size(); i++) Layers[i]->SetID(i);
	}
}