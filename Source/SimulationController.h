#ifndef INCLUDE_H_SIMULATION_CONTROLLER
#define INCLUDE_H_SIMULATION_CONTROLLER

#include "cMaze.h"
#include "cTimer.h"
#include "cVector2.h"
#include "Console.h"

class Mouse;

/* Description: Controller object for starting and controlling the maze solver simulation.*/
class SimulationController
{
// Methods
public:
	SimulationController ();
	/* Description: Prints the maze and starts the simulation loop for the player to begin.*/
	void StartSimulation ();
	~SimulationController ();

// Methods
private:
	/* Description: Attempts to create a maze of a random size. Initialising it with start and end positions.
	[returns]: True if the maze was created successfully, false if it failed.*/
	bool MazeCreated ();
	/* Description: Log's an error encountered with the creation of the maze to the console.*/
	void LogCreationError ();
	/* Description: Displays the maze and the intro to the simulation on screen.*/
	void DisplayIntroMenu ();
	/* Description: Begins the simulation loop until either the user exits or the simulation ends.*/
	void LoopSimulation ();
	/* Description: Updates the simulation timer and character.*/
	void UpdateSimulation ();
	/* Description: Updates the simulations stats and data.*/
	void UpdateSimulationUI ();
	/* Description: Get's the users inputs and checks to see if the player has quit.
	[returns]: True if the player has chosen to quit, false if the user has not.*/
	bool ExitSimulation ();
	/* Description: Displays the end simulation results to the screen/*/
	void DisplaySimulationResults ();
	/* Description: Draw's the path of the mouse's movement and the final direct route from start to cheese.*/
	void DrawMousePath ();

// Members
private:
	/* Description: The current maze instance of the simulation.*/
	cMaze m_Maze;
	/* Description: The current timer instance for the simulation.*/
	cTimer m_Timer;
	/* Description: The current console instance for interfacing with the simulation.*/
	Console m_Console;
	/* Description: The speed of the simulation.*/
	int m_Speed{ 200 };
	/* Description: The mouse object within the simulation.*/
	Mouse* m_Mouse{ nullptr };

private:
	/* Description: Code identifiers for required keys.*/
	enum KEYS
	{
		ESC = 27,
		LEFT_ARROW = 75,
		RIGHT_ARROW = 77
	};

};

#endif // !INCLUDE_H_SIMULATION_CONTROLLER
