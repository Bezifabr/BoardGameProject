#include "Renderer.h"

Renderer::Renderer(RenderWindow * renderWindow)
{
	InitializeRenderWindow(renderWindow);
}

Renderer::~Renderer()
{
	assert(renderWindow);
	renderWindow = nullptr;
	assert(!renderWindow);

	assert(currentLocation);
	currentLocation = nullptr;
	assert(!currentLocation);

	assert(drawableObjects);
	drawableObjects = nullptr;
	assert(!drawableObjects);
}

void Renderer::InitializeRenderWindow(RenderWindow * renderWindow)
{
	this->renderWindow = renderWindow;
	assert(renderWindow != NULL);
}

void Renderer::ObjectsRendering()
{
	assert(renderWindow);
	assert(currentLocation);

	renderWindow->Clear();

	RenderingLoop();

	renderWindow->Display();
}

void Renderer::GetGameDataFromDataContainer(vector<DrawableObject*>* drawableObjects, int * locationNumber)
{
	this->drawableObjects = drawableObjects;
	assert(this->drawableObjects);
	this->currentLocation = locationNumber;
	assert(this->currentLocation);
}

void Renderer::RenderingLoop()
{
	if (!drawableObjects->empty())
		for (int layer = 0; layer != MAX_LAYER_NUMBER; layer++)
			for (auto itr = drawableObjects->begin(), end = drawableObjects->end(); itr != end; itr++)
			{
				assert((*itr));
				if (CheckLayerAndLocation((*itr), layer, (*currentLocation)))
					renderWindow->Draw((*itr)->GetDrawable());
			}
}

bool Renderer::CheckLayerAndLocation(DrawableObject * object, int layer, int location)
{
	return object->GetLayer() == layer && object->GetLocation() == location;
}
