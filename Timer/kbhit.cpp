#include "kbhit.h"

#ifdef _WIN32

#include <Windows.h>
#include <conio.h>

bool isKeyPressed()
{
	return _kbhit() > 0;
}

void turnEchoOff()
{
	HANDLE hStdin{ GetStdHandle(STD_INPUT_HANDLE) };
	DWORD mode{ 0 };
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & ~ENABLE_ECHO_INPUT);
}

void turnEchoOn()
{
	HANDLE hStdin{ GetStdHandle(STD_INPUT_HANDLE) };
	DWORD mode{ 0 };
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
}

#else

#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>

bool isKeyPressed()
{
	static const int STDIN{ 0 };

	termios term{};
	int bytesWaiting{ 0 };
	tcgetattr(STDIN, &term);

	term.c_lflag &= ~ICANON;
	tcsetattr(STDIN, TCSANOW, &term);

	ioctl(0, FIONREAD, &bytesWaiting);

	term.c_lflag |= ICANON;
	tcsetattr(STDIN, TCSANOW, &term);

	return bytesWaiting > 0;
}

void turnEchoOff()
{
	static const int STDIN{ 0 };
	termios term{};
	tcgetattr(STDIN, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(STDIN, TCSANOW, &term);
}

void turnEchoOn()
{
	static const int STDIN{ 0 };
	termios term{};
	tcgetattr(STDIN, &term);
	term.c_lflag |= ECHO;
	tcsetattr(STDIN, TCSANOW, &term);
}

#endif // _WIN32
