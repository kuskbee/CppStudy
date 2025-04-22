#pragma once

class UWorld;
class UInput;

class UEngine
{
public:
	UEngine();
	virtual ~UEngine();

	void Initialize();
	void Run();
	void Terminate();
private:
	void Input();
	void Render();
	void Tick();

	UWorld* World;
	UInput* InputDevice;
};

