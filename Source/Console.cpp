#include <conio.h>
#include "Console.h"



Console::Console ()
{
	m_Attribute = FOREGROUND_INTENSITY | 7;
	m_CharsWritten = 0;

	m_Handle = GetStdHandle (STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo (m_Handle, &m_Info);

	CONSOLE_CURSOR_INFO cursorInfo = { 50, false };
	SetConsoleCursorInfo (m_Handle, &cursorInfo);

	m_CursorPosition = { 0, 0 };
	SetConsoleCursorPosition (m_Handle, m_CursorPosition);
}

void Console::SetCursorPosition (COORD position)
{
	m_CursorPosition = position;
	SetConsoleCursorPosition (m_Handle, m_CursorPosition);
}

void Console::ClearScreen ()
{
	// The position of the first cell of the window to clear from.
	const COORD firstCellPosition = { 0, 0 };
	// The size of the current console window instance.
	const DWORD consoleSize = m_Info.dwSize.X * m_Info.dwSize.Y;

	// Fill screen with empty spaces.
	if (!FillConsoleOutputCharacter (m_Handle, (TCHAR)' ', consoleSize, firstCellPosition, &m_CharsWritten))
		return;

	// Reset the console windows attributes.
	if (!FillConsoleOutputAttribute (m_Handle, m_Info.wAttributes, consoleSize, firstCellPosition, &m_CharsWritten))
		return;

	// Reset the cursor position of the console back to where it was before.
	SetConsoleCursorPosition (m_Handle, m_CursorPosition);

	// Reset the number of characters written to the screen.
	m_CharsWritten = 0;
}

void Console::ClearLine (SHORT row)
{
	// The position of the first cell of the line to clear from.
	const COORD firstCellPosition = { 0, row };
	// The size of the current console line instance.
	const DWORD consoleSize = m_Info.dwSize.X;
	// The current position of the cursor on screen before clearing.
	const COORD currentCursorPosition = m_CursorPosition;

	// Fill the line with empty spaces. Thereby clearing it.
	if (!FillConsoleOutputCharacter (m_Handle, (TCHAR)' ', consoleSize, firstCellPosition, &m_CharsWritten))
		return;

	// Reset the cursor position of the console back to where it was before we cleared..
	SetConsoleCursorPosition (m_Handle, currentCursorPosition);
}

void Console::Draw (std::string message)
{
	SetConsoleTextAttribute (m_Handle, m_Attribute);
	WriteConsole (m_Handle, message.c_str (), message.size (), &m_CharsWritten, nullptr);
}

void Console::Draw (std::string message, WORD color)
{
	SetConsoleTextAttribute (m_Handle, color);
	WriteConsole (m_Handle, message.c_str (), message.size (), &m_CharsWritten, nullptr);
	SetConsoleTextAttribute (m_Handle, FOREGROUND_INTENSITY | 7);
}

void Console::Draw (COORD position, std::string message)
{
	SetCursorPosition (position);

	SetConsoleTextAttribute (m_Handle, m_Attribute);
	WriteConsole (m_Handle, message.c_str (), message.size (), &m_CharsWritten, nullptr);
}

void Console::Draw (COORD position, std::string message, WORD color)
{
	SetCursorPosition (position);

	SetConsoleTextAttribute (m_Handle, color);
	WriteConsole (m_Handle, message.c_str (), message.size (), &m_CharsWritten, nullptr);
	SetConsoleTextAttribute (m_Handle, FOREGROUND_INTENSITY | 7);
}

void Console::WriteLine (std::string message)
{
	Draw (message);
	EndLine ();
}

void Console::WriteLine (std::string message, WORD color)
{
	Draw (message, color);
	EndLine ();
}

void Console::WriteLine (COORD position, std::string message)
{
	Draw (position, message);
	EndLine ();
}

void Console::WriteLine (COORD position, std::string message, WORD color)
{
	Draw (position, message, color);
	EndLine ();
}

void Console::EndLine ()
{
	std::string message = "\n";

	WriteConsole (m_Handle, message.c_str (), message.size (), &m_CharsWritten, nullptr);
}

void Console::WaitForInput (std::string message)
{
	EndLine ();

	Draw (message);
	_getch ();

	EndLine ();
}

Console::~Console ()
{
}
