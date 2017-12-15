#include "Timer.h"
#include "kbhit.h"

#include <iostream>

int main(int argc, char *argv[])
{
	Timer timer{ Timer::StopCond::ByCount };
	Timer::Value tickCount{ 100 };
	Timer::Value tickInterval{ 100 }; // msec
	Timer::Value finishValue{ tickCount * tickInterval };
	Timer::Value currentValue{ 0 };

	std::cout << "Wait for the program to finish or press any key" << std::endl;

	timer.start(tickInterval, 0, finishValue, [&currentValue](Timer::Value) { currentValue++; });

	turnEchoOff();

	while (!isKeyPressed() && timer.isRunning())
		std::this_thread::sleep_for(std::chrono::milliseconds(tickInterval));
	
	std::cout << "Result: " << currentValue << std::endl;
	std::cout << "Press Enter key to exit please" << std::endl;

	if (isKeyPressed()) std::cin.ignore();
	std::cin.get();
	turnEchoOn();

	return 0;
}