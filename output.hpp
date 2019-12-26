#pragma once
#include <string>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h>
#else
#include <iostream>
#define normal "\x1B[0m"
#define red "\x1B[31m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define blue "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan "\x1B[35m"
#define white "\x1B[37m"
#endif

inline void print(const std::string& contents, unsigned int color = 7) {
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	printf(contents.c_str());
	SetConsoleTextAttribute(hConsole, 7);
	#else
	std::cout << "\x1B[" << 30 + color << "m" << contents << "\x1B[0m";
	#endif
}