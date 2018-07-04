#pragma once

#include "EventsHandler.h"
#include <vector>
#include "GameWindowRender.h"

class Renderer
{
	RenderWindow* renderWindow;

	int* currentLocation = nullptr;
	vector<DrawableObject*>* drawableObjects;
public:
	Renderer(RenderWindow* renderWindow);

	~Renderer();

	void InitializeRenderWindow(RenderWindow* renderWindow);

	void ObjectsRendering();

	void GetGameDataFromDataContainer(vector<DrawableObject*>* drawableObjects, int* locationNumber);

private:
	void RenderingLoop();

	bool CheckLayerAndLocation(DrawableObject* object, int layer, int location);
};
