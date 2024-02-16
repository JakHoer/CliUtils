# CliUtils
A small library to create terminal UIs more easily. Uses ANSI escape codes
## Commands
### Cli_init()
Initialize the library
Returns 0 on success and -1 on failure
### Cli_quit()
Clean up and recreate the initial state of terminal (won't clear console)
### Cli_setColor(int fg, int bg)
Change the color of future text to standard colors
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
Set the foreground or background color to the given RGB value. Might not be supported.
### Cli_resetColor()
Reset color to terminal default
### Cli_clear()
Clear console and move the cursor to 1,1
### Cli_clearLine()
Clear the line the cursor is currently on
### Cli_write(char *str)
Write Zero-Terminated string to the console
Returns the length of the printed string
### Cli_print(char *format, ...)
Format string and print to console
Returns the length of the printed string
### Cli_cursorPos(int x, int y)
Set cursor position
### Cli_inlinePos(int x)
Set cursor x-position inside current line
### Cli_moveCursor(int x, int y)
Move cursor relative to the current position
### Cli_moveLines(int n)
Move to the start of the n-th line below or minus the n-th line above
### Cli_scroll(int n)
Move n lines downwards or -n line upwards
### Cli_getChar()
Read a single character from input after Return has been pressed
Returns inputted character
### Cli_getLine()
Read one line from the user and store it inside the buffer
Returns length of line.
### Cli_getChar_nc()
Read non-canonical (without waiting for input or Return) input from the user
Returns read char.
### Cli_hideCursor()
Hide cursor. Might not be supported.
### Cli_showCursor()
Show cursor. Might not be supported.