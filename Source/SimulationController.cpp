#include "SimulationController.h"



const int ESC_KEY = 27;

SimulationController::SimulationController ()
{
	// Create a console object for interfacing with the console window.
	m_Console = Console ();

	// Check if the maze was created successfully.
	if (!MazeCreated ())
		// If it was not, then log this to the console and exit safely.
		LogCreationError ();
}

void SimulationController::StartSimulation ()
{
	DisplayIntroMenu ();
	LoopSimulation ();
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
		UpdateSimulation ();
		UpdateTimer ();

		// short delay between moves to make them visible
		Sleep (200);

		if (EndSimulation ())
			return;

	} while (!m_Mouse->FoundCheese ());

	DisplaySimulationResults ();
}

void SimulationController::UpdateSimulation ()
{
	// start keeping time
	m_Timer.start ();

	// Update mouse information.
	m_Mouse->CalculateMovement ();
	m_Mouse->Draw (m_Console);

	// Stop keeping time
	m_Timer.stop ();
}

void SimulationController::UpdateTimer ()
{
	// Display timing updates
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 2 }, "Limit =  " + std::to_string (m_Maze.getTimeLimit_ms ()) + " ms");
	m_Console.WriteLine ("Elapsed =  " + std::to_string (m_Timer.getElapsed_ms ()) + " ms");
}

bool SimulationController::EndSimulation ()
{
	// Quit if Escape is pressed.
	if (_kbhit ())
	{
		if (ESC_KEY == _getch ())
			return true;
	}

	return false;
}

void SimulationController::DisplaySimulationResults ()
{
	DrawMousePath ();

	// Gran the fully elapsed time of the simulation and display it on screen.
	double elapsed = m_Timer.getElapsed_ms ();
	m_Console.EndLine ();
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 3 }, "Total Elapsed =  " + std::to_string (elapsed));
	m_Console.WaitForInput ("Press a key to exit");
}

void SimulationController::DrawMousePath ()
{
	// Get the mouse's current path within the maze.
	const std::vector<cVector2> path = m_Mouse->GetMousePath ();

	// Run through the mouses's path and print each position onto the maze.
	for (int i = 0; i < path.size (); i++)
		m_Console.WriteLine ({ (SHORT)path[i].x, (SHORT)path[i].y }, "+", FOREGROUND_INTENSITY | 5);
}

SimulationController::~SimulationController ()
{
	// Clean up the dynamic memory created.
	delete m_Mouse;
	m_Mouse = nullptr;
}
