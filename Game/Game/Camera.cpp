#include "Camera.h"

const sf::View & Camera::GetCameraView()
{
	return view;
}

void Camera::SetPosition(sf::Vector2f position)
{
	view.setCenter(position);
}

void Camera::SetSize(sf::Vector2f size)
{
	view.setSize(size);
}

void Camera::Move(sf::Vector2f moveValue)
{
	view.move(moveValue);
}
