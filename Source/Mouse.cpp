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
	if (GetDir () == Vector2::Left ())
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
	else if (GetDir () == Vector2::Down ())
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
	else if (GetDir () == Vector2::Right ())
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
	else if (GetDir () == Vector2::Up ())
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
	if ('E' == m_Maze[m_Pos.y + toPos.y][m_Pos.x + toPos.x])
		m_HasFoundCheese = true;
	else if (' ' != m_Maze[m_Pos.y + toPos.y][m_Pos.x + toPos.x])
		return false;

	m_PrevPos = m_Pos;
	m_Pos += toPos;
	m_Dir = toPos;

	return true;
}

void Mouse::Draw (Console& console)
{
	console.WriteLine ({ (SHORT)m_Pos.x, (SHORT)m_Pos.y }, m_Symbol, FOREGROUND_INTENSITY | 6);

	// If the position the mouse previously was in, is not a start position. Clear the space back to empty again.
	if (m_Maze[m_PrevPos.y][m_PrevPos.x] != 'S')
		console.WriteLine ({ (SHORT)m_PrevPos.x, (SHORT)m_PrevPos.y }, " ", FOREGROUND_INTENSITY | 7);
}

Mouse::~Mouse ()
{
}
