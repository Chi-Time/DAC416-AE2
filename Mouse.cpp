#include <vector>
#include "Mouse.h"
#include "Console.h"



Mouse::Mouse (cVector2 & spawnPos, std::vector<std::string> maze)
{
	m_Maze = maze;
	m_Pos = spawnPos;
	m_Dir = { -1, 0 };
	m_HasFoundCheese = false;
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
