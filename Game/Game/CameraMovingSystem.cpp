#include "CameraMovingSystem.h"

void CameraMovingSystem::AddRectOfBackground(const sf::FloatRect & floatRect)
{
	background = floatRect;
}

void CameraMovingSystem::SetCamera(Camera * camera)
{
	this->camera = camera;
	assert(this->camera);
}

void CameraMovingSystem::MoveCameraToTargetPositionInTime(sf::Vector2f targetPosition, float timeOfMovement)
{
	this->targetPosition = targetPosition;
	timeOfCameraMovement = timeOfMovement;

	CalculateDistanceBetweenTargetAndCamera();
	CalculateCameraSpeed();
	CalculateCameraSpeedWithDeltaTime();


	camera->Move(cameraSpeed);
}

void CameraMovingSystem::CalculateDistanceBetweenTargetAndCamera()
{
	assert(camera);
	distance = sf::Vector2f(this->targetPosition.x - camera->GetCameraView().getCenter().x, this->targetPosition.y - camera->GetCameraView().getCenter().y);
}

void CameraMovingSystem::CalculateCameraSpeed()
{
	cameraSpeed = sf::Vector2f(distance.x / timeOfCameraMovement, distance.y / timeOfCameraMovement);
}

void CameraMovingSystem::CalculateCameraSpeedWithDeltaTime()
{
	float deltaTime = movingTimer.restart().asMilliseconds();
	cameraSpeed.x *= deltaTime;
	cameraSpeed.y *= deltaTime;
}
