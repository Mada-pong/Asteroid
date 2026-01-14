#include "Cooldown.h"

Cooldown::Cooldown(float duration)
	: time(duration)
{
	this->duration = duration;
}

/// Count down the cooldown timer with the update function.
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

/// Start the cooldown timer from the initial duration and reset it.
void Cooldown::start()
{
	isFinished = false;
	time = duration;
}

void Cooldown::setNewTime(float newDuration)
{
	this->duration = newDuration;
}

/// Store a callback function to be called back when the cooldown has been completed.
void Cooldown::setOnFinished(std::function<void()> callback)
{
	onFinished = std::move(callback);
}

float Cooldown::getTime()
{
	return this->time;
}
