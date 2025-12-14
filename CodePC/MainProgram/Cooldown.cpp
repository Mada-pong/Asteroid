#include "Cooldown.h"
#include <iostream>
#include <string>

Cooldown::Cooldown(float duration)
	: time(duration)
{
	this->duration = duration;
}

/// <summary>
/// Count down the cooldown timer with the update function.
/// </summary>
/// <param name="deltaTime"></param>
void Cooldown::update(float deltaTime)
{
	if (isFinished == true)
		return;

	if (time <= 0)
	{
		isFinished = true;
		onFinished();
	}
	else
	{
		time -= deltaTime;
	}
}

/// <summary>
/// Start the cooldown timer from the initial duration.
/// </summary>
void Cooldown::start()
{
	isFinished = false;
	time = duration;
}

/// <summary>
/// Store a callback function to be called back when the cooldown has been completed.
/// </summary>
/// <param name="callback"></param>
void Cooldown::setOnFinished(std::function<void()> callback)
{
	onFinished = std::move(callback);
}
