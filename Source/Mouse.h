#ifndef INCLUDE_H_MOUSE
#define INCLUDE_H_MOUSE

#include "cVector2.h"

class Console;

/* Description: Mouse object which handles drawing, movement and pathing around the maze.
*/
class Mouse
{
// Getters/Setters
public:
	/* Description: Retrieves the current directional vector of the mouse.
	*/
	cVector2 GetDir () { return m_Dir; }
	/* Description: Retrieves the current position of the mouse on the screen.
	*/
	cVector2 GetPos () { return m_Pos; }
	/* Description: Retrieves the current character used to denote the mouse on screen.
	*/
	std::string GetMouseChar () { return m_MouseChar; }
	std::vector<cVector2> GetMousePath () { return m_Path; }
	/* Description: Retrieves whether or not the mouse has found the cheese in the maze.
	*/
	bool FoundCheese () { return m_HasFoundCheese; }

// Methods
public:
	Mouse (cVector2& spawnPos, std::vector<std::string> maze);
	/* Description: Calculates the mouse's next movement within the maze.
	*/
	void CalculateMovement ();
	/* Description: Draws the mouse at it's current position onto the screen. Clearing it's previous position.
	*console: Reference to the console object to draw the mouse to the screen.
	*/
	void Draw (Console& console);
	/* Description: Attempts to move the mouse to the given position.
	*toPos: The position on the screen to add to the current mouse's position.
	[returns]: True if the movement was successful. False if failed.
	*/
	bool MoveTo (const cVector2& toPos);

	~Mouse ();

// Members
private:
	/* Description: The mouse's current position.
	*/
	cVector2 m_Pos{ 0, 0 };
	/* Description: The mouse's current movement direction.
	*/
	cVector2 m_Dir{ -1, 0 };
	/* Description: The mouses's previous position.
	*/
	cVector2 m_PrevPos{ 0, 0 };
	/* Description: The character used to display the mouse in the maze.
	*/
	std::string m_MouseChar{ 'M' };
	/* Description: Whether the mouse has found the cheese in the maze or not.
	*/
	bool m_HasFoundCheese{ false };
	/* Description: The current maze as a multidimensional array.
	*/
	std::vector<std::string> m_Maze;
	std::vector<cVector2> m_Path;

// Methods
private:
	/* Description: Checks whether the given position is valid to move into.
	*nextPos: The position to check.
	[returns]: True if the movement is valid. False if invalid.
	*/
	bool ValidMove (const cVector2 nextPos);

};
#endif //!INCLUDE_H_MOUSE
