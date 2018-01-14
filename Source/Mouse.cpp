#include <vector>
#include "Mouse.h"
#include "Console.h"
#include "Vector2.h"



Mouse::Mouse (cVector2 & spawnPos, std::vector<std::string> maze)
{
	m_Maze = maze;
	m_Pos = spawnPos;
	m_Dir = { -1, 0 };
	m_HasFoundCheese = false;
}

void Mouse::CalculateMovement ()
{
	// If moving left.
	if (m_Dir == Vector2::Left ())
	{
		// Check down first (our immediate left from this position.)
		if (MoveTo (Vector2::Down ()))
			return;
		// Check left, (our immediate forward.)
		else if (MoveTo (Vector2::Left ()))
			return;
		// Check up, (our immediate right.)
		else if (MoveTo (Vector2::Up ()))
			return;
		// If no other movement, check right (our immediate back.)
		else if (MoveTo (Vector2::Right ()))
			return;
	}
	// If moving down.
	else if (m_Dir == Vector2::Down ())
	{
		// Check right first (our immediate left from this position.)
		if (MoveTo (Vector2::Right ()))
			return;
		// Check down, (our immediate forward.)
		else if (MoveTo (Vector2::Down ()))
			return;
		// Check left, (our immediate right.)
		else if (MoveTo (Vector2::Left ()))
			return;
		// If no other movement, check up (our immediate back.)
		else if (MoveTo (Vector2::Up ()))
			return;
	}
	// If moving right.
	else if (m_Dir == Vector2::Right ())
	{
		// Check up first, (our immediate left from this position.)
		if (MoveTo (Vector2::Up ()))
			return;
		// Check right, (our immediate forward.)
		else if (MoveTo (Vector2::Right ()))
			return;
		// Check down, (our immediate right.)
		else if (MoveTo (Vector2::Down ()))
			return;
		// If no other movement, check left (our immediate back.)
		else if (MoveTo (Vector2::Left ()))
			return;
	}
	// If moving up.
	else if (m_Dir == Vector2::Up ())
	{
		// Cbeck left first, (our immediate left from this position.)
		if (MoveTo (Vector2::Left ()))
			return;
		// Check up, (our immediate forward.)
		else if (MoveTo (Vector2::Up ()))
			return;
		// Check right, (our immediate right.)
		else if (MoveTo (Vector2::Right ()))
			return;
		// If no other movement, check down (our immediate back.)
		else if (MoveTo (Vector2::Down ()))
			return;
	}
}

bool Mouse::MoveTo (const cVector2& toPos)
{
	// Is the following vector a valid movement?
	if (!ValidMove (m_Pos + toPos))
		// Return that the movement was unsuccessful.
		return false;

	m_Path.push_back (m_Pos + toPos);
	// Set the previous position the mouse was in.
	m_PrevPos = m_Pos;
	// Set the new position of the mouse.
	m_Pos += toPos;
	// Update the mouse's current direction vector.
	m_Dir = toPos;

	// Return that the movement was successful.
	return true;
}

void Mouse::Draw (Console& console)
{
	// Start position char.
	const char start = 'S';
	// Clear space char.
	const std::string clear = " ";
	// The char of the previous maze space the mouse was in.
	const char previousScreenChar = m_Maze[m_PrevPos.y][m_PrevPos.x];
	// The current position of the mouse in screen COORDs.
	const COORD currentScreenPos = { (SHORT)m_Pos.x, (SHORT)m_Pos.y };
	// The previous position of the mouse in screen COORDs.
	const COORD previouScreenPos = { (SHORT)m_PrevPos.x, (SHORT)m_PrevPos.y };

	// Empty the previous position of the mouse.
	console.WriteLine (currentScreenPos, m_MouseChar, FOREGROUND_INTENSITY | 6);

	// If the previous position is not the maze start. Then clear the space back to empty again.
	if (previousScreenChar != start)
		console.WriteLine (previouScreenPos, clear, FOREGROUND_INTENSITY | 7);
}

Mouse::~Mouse ()
{
}

bool Mouse::ValidMove (const cVector2 nextPos)
{
	// Floor char.
	const char floor = ' ';
	// Cheese char.
	const char cheese = 'E';
	// The current char of the maze space being moved into.
	const char currentMazeChar = m_Maze[nextPos.y][nextPos.x];

	// If the current space being moved to is the cheese.
	if (currentMazeChar == cheese)
	{
		// Collect the cheese and return that the movement was successful.
		m_HasFoundCheese = true;
		return true;
	}
	// If the space being moved to is not the floor.
	else if (currentMazeChar != floor)
		// Return that the movement was unsuccessful.
		return false;
}
