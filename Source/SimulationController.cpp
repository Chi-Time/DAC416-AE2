#include "SimulationController.h"
#include "Vector2.h"



const int ESC_KEY = 27;

SimulationController::SimulationController ()
{
	// Create a console object for interfacing with the console window.
	m_Console = Console ();

	// Check if the maze was created successfully.
	if (!MazeCreated ())
		// If it was not, then log this to the console and exit safely.
		LogCreationError ();

	DisplayIntroMenu ();
	LoopSimulation ();
	DisplaySimulationResults ();
}

bool SimulationController::MazeCreated ()
{
	// Initialise a maze of a random size.
	m_Maze.createRandomSize ();

	// print the maze to the console.
	m_Maze.print ();

	// ensure the maze was created successfully with a start point
	cVector2 startPos;

	if (!m_Maze.getStart (startPos))
		return false;

	// create the "mouse"
	m_Mouse = new Mouse (startPos, m_Maze.getStrings ());

	return true;
}

void SimulationController::DisplayIntroMenu ()
{
	// Display timing updates
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 2 }, "Limit =  " + std::to_string (m_Maze.getTimeLimit_ms ()) + " ms");
	m_Console.WaitForInput ("Press a key to start the mouse.");
	m_Console.ClearLine ((SHORT)m_Maze.getHeight () + 4);
}

void SimulationController::LogCreationError ()
{
	// Clear the screen of any content and log the error to the screen, waiting for user input to end.
	m_Console.ClearScreen ();
	m_Console.WriteLine ("Error occurred in maze creation. Simulation could not continue!");
	m_Console.WaitForInput ("Press a key to exit");
}

void SimulationController::LoopSimulation ()
{
	do
	{
		// start keeping time
		m_Timer.start ();

		m_Mouse->CalculateMovement ();
		m_Mouse->Draw (m_Console);

		// stop keeping time
		m_Timer.stop ();

		// Display timing updates
		m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 2 }, "Limit =  " + std::to_string (m_Maze.getTimeLimit_ms ()) + " ms");
		m_Console.WriteLine ("Elapsed =  " + std::to_string (m_Timer.getElapsed_ms ()) + " ms");

		// short delay between moves to make them visible
		Sleep (200);

		// Quit if Escape is pressed.
		if (_kbhit ())
		{
			if (ESC_KEY == _getch ())
				return;
		}

	} while (!m_Mouse->FoundCheese ());
}

void SimulationController::DisplaySimulationResults ()
{
	double elapsed = m_Timer.getElapsed_ms ();
	m_Console.EndLine ();
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 3 }, "Total Elapsed =  " + std::to_string (elapsed));
	m_Console.WaitForInput ("Press a key to exit");
}

SimulationController::~SimulationController ()
{
	delete m_Mouse;
	m_Mouse = nullptr;
}
