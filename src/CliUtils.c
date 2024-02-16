/*
	MIT License

	Copyright (c) 2024 Jakob Höroldt

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "CliUtils/CliUtils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int cursorHidden; // Needed because some calls besides "hide" also hide the cursor
#if defined(WIN32)
	#include <windows.h>
	#include <conio.h>
	HANDLE consoleHandle;
	DWORD consoleMode;
	
	int Cli_getChar_nc(){
		if(!cursorHidden) Cli_showCursor();
		return getch();
	}

#elif defined(__unix__)
	#include <termios.h>
	struct termios initialAttr;
	struct termios canonAttr;
	struct termios nonCanonAttr;
	int isCanon = 1;

	void enterCanonInput(){
		if(isCanon) return;
		isCanon = 1;
		tcsetattr(STDIN_FILENO, TCSANOW, &canonAttr);
	}

	void exitCanonInput(){
		if(!isCanon) return;
		isCanon = 0;
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &nonCanonAttr);
	}

	int Cli_getChar_nc(){
		exitCanonInput();
		if(!cursorHidden) Cli_showCursor();
		return getchar();
	}
#endif

#define write(str) fwrite(str, 1, strlen(str), (FILE* restrict)stdout)

int Cli_init(){
	int error;
	cursorHidden = 0;
	Cli_showCursor();
	#if defined(WIN32)
		consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		error = GetConsoleMode(consoleHandle, &consoleMode);
		if(!error) consoleMode = 0;
		error = SetConsoleMode(consoleHandle, ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_OUTPUT);
		if(!error) return -1;
	#elif defined(__unix__)
		tcgetattr(STDIN_FILENO, &initialAttr);
		tcgetattr(STDIN_FILENO, &canonAttr);
		tcgetattr(STDIN_FILENO, &nonCanonAttr);
		canonAttr.c_lflag |= ICANON|ECHO;
		nonCanonAttr.c_lflag &= ~(ICANON|ECHO);
	#endif
	return 0;
}

void Cli_quit(){
	Cli_resetColor();
	Cli_showCursor();
	#if defined(WIN32)
		if(consoleMode) SetConsoleMode(consoleHandle, consoleMode);
	#elif defined(__unix__)
		tcsetattr(STDIN_FILENO, TCSANOW, &initialAttr);
	#endif
}

int Cli_setColor(int fg, int bg){
	if(fg) printf("\e[%dm", fg);
	if(bg) printf("\e[%dm", bg+10);
	return 0;
}

int Cli_setForegroundColor(int r, int g, int b){
	printf("\e[38;2;%d;%d;%dm", r, g, b);
	return 0;
}

int Cli_setBackgroundColor(int r, int g, int b){
	printf("\e[48;2;%d;%d;%dm", r, g, b);
	return 0;
}

int Cli_resetColor(){
	write("\e[0m");
	return 0;
}

int Cli_clear(){
	write("\e[2J\e[3J\e[H");
	return 0;
}

int Cli_clearLine(){
	write("\e[2K\e[G");
	return 0;
}

int Cli_write(char *str){
	return write(str);
}

int Cli_print(const char* format, ...){
	va_list args;
	va_start(args, format);
	int ret = vprintf(format, args);
	va_end(args);
	return ret;
}

int Cli_cursorPos(int x, int y){
	printf("\e[%d;%dH", y, x);
	return 0;
}

int Cli_inlinePos(int x){
	printf("\e[%dG", x);
	return 0;
}

int Cli_moveCursor(int x, int y){
	printf("\e[%d%c\e%d%c", abs(y), y < 0 ? 'C' : 'D', abs(x), x < 0 ? 'B' : 'A');
	return 0;
}

int Cli_moveLines(int n){
	printf("\e[%d%c", abs(n), n < 0 ? 'F' : 'E');
	return 0;
}

int Cli_scroll(int n){
	printf("\e[%d%c", abs(n), n < 0 ? 'T' : 'S');
	return 0;
}

int Cli_getChar(){
	#if defined(__unix__)
		enterCanonInput();
	#endif
	if(!cursorHidden) Cli_showCursor();
	return getchar();
}

int Cli_getLine(char *buffer, int bufSize){
	#if defined(__unix__)
		enterCanonInput();
	#endif

	if(!cursorHidden) Cli_showCursor();

	int c;
	int len = 0;
	while((c = getchar()) != '\n' && c != '\r'){
		if(buffer && len < bufSize-1) buffer[len] = c;
		len++;
	}
	if(buffer) buffer[len] = 0;
	return len;
}

int Cli_hideCursor(){
	write("\e[?25l");
	cursorHidden = 1;
	return 0;
}

int Cli_showCursor(){
	write("\e[?25h");
	cursorHidden = 0;
	return 0;
}