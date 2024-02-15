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

int Cli_init();
void Cli_quit();

int Cli_setColor(int fg, int bg);
int Cli_setForegroundColor(int r, int g, int b);
int Cli_setBackgroundColor(int r, int g, int b);
int Cli_resetColor();

int Cli_clear();
int Cli_clearLine();
int Cli_write(char *str);
int Cli_print(const char* format, ...);

int Cli_cursorPos(int x, int y);
int Cli_inlinePos(int x);
int Cli_moveCursor(int x, int y);
int Cli_moveLines(int n);
int Cli_scroll(int n);

int Cli_getChar();
int Cli_getLine(char *buffer, int bufSize);
int Cli_getChar_nc();

// May not be supported
int Cli_hideCursor();

// May not be supported
int Cli_showCursor();

#endif