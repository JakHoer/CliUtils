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
	IMPLIED, INCLUDING BUT NT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef __CLIUTILS_H__
#define __CLIUTILS_H__

#define CLI_COLOR_BLACK 30
#define CLI_COLOR_RED 31
#define CLI_COLOR_GREEN 32
#define CLI_COLOR_YELLOW 33
#define CLI_COLOR_BLUE 34
#define CLI_COLOR_MAGENTA 35
#define CLI_COLOR_CYAN 36
#define CLI_COLOR_WHITE 37

// Initialize the library
// @return 0 on success and -1 on failure
int Cli_init();

// Clean up and recreate the initial state of terminal (won't clear console)
void Cli_quit();

// Change the color of future text to standard colors
// Standard colors:
//   - CLI_COLOR_BLACK
//   - CLI_COLOR_RED
//   - CLI_COLOR_GREEN
//   - CLI_COLOR_YELLOW
//   - CLI_COLOR_BLUE
//   - CLI_COLOR_MAGENTA
//   - CLI_COLOR_CYAN
//   - CLI_COLOR_WHITE
int Cli_setColor(int fg, int bg);

// Set the foreground color to the given RGB value. Might not be supported.
int Cli_setForegroundColor(int r, int g, int b);

// Set the background color to the given RGB value. Might not be supported.
int Cli_setBackgroundColor(int r, int g, int b);

// Reset color to terminal default
int Cli_resetColor();

// Clear console and move the cursor to 1,1
int Cli_clear();

// Clear the line the cursor is currently on
int Cli_clearLine();

// Write Zero-Terminated string to the console
// @return Length of the printed string.
int Cli_write(char *str);

// Format string and print to console
// @return Length of the printed string
int Cli_print(const char* format, ...);

// Set cursor position
int Cli_cursorPos(int x, int y);

// Set cursor x-position inside current line
int Cli_inlinePos(int x);

// Move cursor relative to the current position
int Cli_moveCursor(int x, int y);

// Move to the start of the n-th line below or minus the n-th line above
int Cli_moveLines(int n);

// Move n lines downwards or -n line upwards.
int Cli_scroll(int n);

// Read a single character from input after Return has been pressed
// @return Inputted character
int Cli_getChar();

// Read one line from the user and store it inside the buffer
// @param buffer Buffer to store line
// @param bufSize size of buffer
// @return Length of line.
int Cli_getLine(char *buffer, int bufSize);

// Read non-canonical (without waiting for input or Return) input from the user
// @return Read char
int Cli_getChar_nc();

// Hide cursor. Might not be supported.
int Cli_hideCursor();

// Show cursor. Might not be supported.
int Cli_showCursor();

#endif