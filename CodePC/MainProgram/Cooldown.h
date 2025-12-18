#ifndef COOLDOWN_HPP
#define COOLDOWN_HPP

#include <functional>

class Cooldown
{
private: 
	bool isRunning = false;
	bool isReady = false;

	bool isFinished = true;

	std::function<void()> onFinished;

	float time = 0;
	float duration;
public: 
	Cooldown(float duration);
	void update(float deltaTime);
	
	void start();

	void setNewTime(float duration);
	void setOnFinished(std::function<void()> callback);

	float getTime();
};


#endif // !COOLDOWN_HPP