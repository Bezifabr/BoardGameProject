#pragma once

#include "GameLoadingSystem.h"

class CameraMovingSystem
{
	Camera* camera;
	sf::FloatRect background;

	sf::Vector2f targetPosition;

	float timeOfCameraMovement;
	sf::Vector2f distance; 
	sf::Vector2f timeOfMovement;
	sf::Vector2f cameraSpeed;

	sf::Clock movingTimer;

public:

	void AddRectOfBackground(const sf::FloatRect& floatRect);

	void SetCamera(Camera* camera);

	void MoveCameraToTargetPositionInTime(sf::Vector2f targetPosition, float timeOfMovement);

private:

	void CalculateDistanceBetweenTargetAndCamera();

	void CalculateCameraSpeed();

	void CalculateCameraSpeedWithDeltaTime();

};