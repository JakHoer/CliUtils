# CliUtils
A small library to create terminal uis more easily. Uses ANSI escape codes.
## Commands
### Cli_init()
Initializes the library. 
Returns 0 un success and -1 on failure.
### Cli_quit()
Clean up and recreate initial state of terminal (won't clear console).
### Cli_setColor(int fg, int bg)
Changes color of future text to default colors.

Colors:
  - CLI_COLOR_BLACK
  - CLI_COLOR_RED
  - CLI_COLOR_GREEN
  - CLI_COLOR_YELLOW
  - CLI_COLOR_BLUE
  - CLI_COLOR_MAGENTA
  - CLI_COLOR_CYAN
  - CLI_COLOR_WHITE
### Cli_setForegroundColor(int r, int g, int b) & Cli_setBackgroundColor(int r, int g, int b)
Sets the foreground or background color to the given rgb value. Might not be supported.
### Cli_resetColor()
Reset color to terminal default
### Cli_clear()
Clears console and moves cursor to 1,1
### Cli_clearLine()
Clears the line the cursor is currently on
### Cli_write(char *str)
Writes Zero-Terminated string to console.
Returns length of printed string.
### Cli_print(char *format, ...)
Formats string and prints to console.
Returns length of printed string.
### Cli_cursorPos(int x, int y)
Sets cursor position
### Cli_inlinePos(int x)
Sets cursor x-position inside current line
### Cli_moveCursor(int x, int y)
Moves cursor relative to current position.
### Cli_moveLines(int n)
Moves to the start of the n-th line below or minus n-th line above.
### Cli_scroll(int n)
Move n lines downwards or -n line upwards.
### Cli_getChar()
Returns a user inputed char after Return has been pressed
### Cli_getLine()
Read line from user and stores inside buffer.
Returns length of line.
### Cli_getChar_nc()
Reads input from user non canonical (without waiting for input or Return).
Returns read char.
### Cli_hideCursor()
Hides cursor. Might not be supported.
### Cli_showCursor()
Shows cursor. Might not be supported.