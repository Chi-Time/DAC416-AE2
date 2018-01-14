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
	/* Description: Retrieves the current colour attribute of the console.
	*/
	const WORD& GetCurrentAttribute () { return m_Attribute; }
	/* Description: Retrieves the current number of characters written to the console instance.
	*/
	const DWORD& GetNumberOfCharsWritten () { return m_CharsWritten; }
	/* Description: Retrieves the current handle used for all console operations.
	*/
	const HANDLE& GetConsoleHandle () { return m_Handle; }
	/* Description: Retrieves the current position of the console cursor.
	*/
	const COORD& GetCursorPosition () { return m_CursorPosition; }
	/* Description: Retrieves the current buffer info of the console instance.
	*/
	const CONSOLE_SCREEN_BUFFER_INFO& GetConsoleInfo () { return m_Info; }
	/* Description: Set's the position of the console cursor to the given screen coordinates.
	*Position: The position on screen to the set the console cursor to.
	*/
	void SetCursorPosition (COORD position);

//  Methods
public:
	Console ();
	void ClearScreen ();
	void ClearLine (SHORT row);
	void Draw (std::string message);
	void Draw (std::string message, WORD color);
	void Draw (COORD position, std::string message);
	void Draw (COORD position, std::string message, WORD color);
	void WriteLine (std::string message);
	void WriteLine (std::string message, WORD color);
	void WriteLine (COORD position, std::string message);
	void WriteLine (COORD position, std::string message, WORD color);
	void EndLine ();
	void WaitForInput (std::string message);
	~Console ();

// Members
private:
	WORD m_Attribute;
	DWORD m_CharsWritten;
	HANDLE m_Handle;
	COORD m_CursorPosition;
	CONSOLE_SCREEN_BUFFER_INFO m_Info;

};

#endif // !INCLUDE_H_CONSOLE
