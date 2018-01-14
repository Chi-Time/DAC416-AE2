#ifndef INCLUDE_H_MOUSE
#define INCLUDE_H_MOUSE

#include <vector>
#include "cVector2.h"

class Console;

class Mouse
{
public:
	// Getters/Setters
	cVector2 GetDir () { return m_Dir; }
	cVector2 GetPos () { return m_Pos; }
	std::string GetSymbol () { return m_Symbol; }
	bool FoundCheese () { return m_HasFoundCheese; }

public:
	// Methods
	Mouse (cVector2& spawnPos, std::vector<std::string> maze);
	void CalculateMovement ();
	void Draw (Console& console);
	bool MoveTo (const cVector2& toPos);

	~Mouse ();

private:
	// Members
	cVector2 m_Pos{ 0, 0 };
	cVector2 m_Dir{ -1, 0 };
	cVector2 m_PrevPos{ 0, 0 };
	std::string m_Symbol{ 'M' };
	bool m_HasFoundCheese{ false };
	std::vector<std::string> m_Maze;

};
#endif //!INCLUDE_H_MOUSE
