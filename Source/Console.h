#ifndef INCLUDE_H_CONSOLE
#define INCLUDE_H_CONSOLE

// Define NOMINMAX to stop it from causing issues with std::max 
// as the windows SDK was defined before c++ and thus has it's own versions which conflict with the template.
#define NOMINMAX

#include <string>
#include <Windows.h>

/*Description: A wrapper for outputting to and handling the console window.*/
class Console
{
// Getters/Setters
public:
	/* Description: Retrieves the current colour attribute of the console.*/
	const WORD& GetCurrentAttribute () { return m_Attribute; }
	/* Description: Retrieves the current number of characters written to the console instance.*/
	const DWORD& GetNumberOfCharsWritten () { return m_CharsWritten; }
	/* Description: Retrieves the current handle used for all console operations.*/
	const HANDLE& GetConsoleHandle () { return m_Handle; }
	/* Description: Retrieves the current position of the console cursor.*/
	const COORD& GetCursorPosition () { return m_CursorPosition; }
	/* Description: Retrieves the current buffer info of the console instance.*/
	const CONSOLE_SCREEN_BUFFER_INFO& GetConsoleInfo () { return m_Info; }
	/* Description: Set's the position of the console cursor to the given screen coordinates.
	*position: The position on screen to the set the console cursor to.*/
	void SetCursorPosition (COORD position);

//  Methods
public:
	Console ();
	/* Description: Clears the console window of any and all text.*/
	void ClearScreen ();
	/* Description: Clears the given row of any and all text.
	*row: The row of the window in which to clear.*/
	void ClearLine (SHORT row);
	/* Description: Draw's the given message onto the screen at the cursors current position.
	*message: The message to write to the screen.*/
	void Draw (std::string message);
	/* Description: Draw's the given message with it's given color onto the screen at the cursors current position.
	*message: The message to write to the screen.
	*color: The color of the text/background when written to the screen.*/
	void Draw (std::string message, WORD color);
	/* Description: Draws the given message at the given screen position.
	*position: The position of the text on the screen.
	*message: The message to write to the screen.*/
	void Draw (COORD position, std::string message);
	/* Description: Draws the given message the given screen position with the given color.
	*position: The position of the text on the screen.
	*message: The message to write to the screen.
	*color The color of the text/background when written to the screen.*/
	void Draw (COORD position, std::string message, WORD color);
	/* Description: Write's the given message to the screen at the cursors current position, leaving a newline when done.
	*message: The message to write to the screen.*/
	void WriteLine (std::string message);
	/* Description: Write's the given message to the screen at the cursors current position with the given color, leaving a newline when done.
	*position: The position of the text on the screen.
	*message: The message to write to the screen.*/
	void WriteLine (std::string message, WORD color);
	/* Description: Write's the given message at the given screen position, leaving a newline when done.
	*position: The position of the text on the screen.
	*message: The message to write to the screen.*/
	void WriteLine (COORD position, std::string message);
	/* Description: Write's the given message at the given screen position with the given color, leaving a newline when done.
	*position: The position of the text on the screen.
	*message: The message to write to the screen.
	*color The color of the text/background when written to the screen.*/
	void WriteLine (COORD position, std::string message, WORD color);
	/* Description: Outputs an empty line to the screen.*/
	void EndLine ();
	/* Description: Outputs an empty line and displays the given message, waiting for any input from the user before continuing.
	*message: The message to write to the screen.*/
	void WaitForInput (std::string message);
	~Console ();

// Members
private:
	/* Description: The current color attribute of the console.*/
	WORD m_Attribute;
	/* Description: The number of characters written to the console instance's window.*/
	DWORD m_CharsWritten;
	/* Description: Output handle.*/
	HANDLE m_Handle;
	/* Description: Current position of cursor on screen.*/
	COORD m_CursorPosition;
	/* Description: Info of the console's screen buffer at initialisation.*/
	CONSOLE_SCREEN_BUFFER_INFO m_Info;

};

#endif // !INCLUDE_H_CONSOLE
