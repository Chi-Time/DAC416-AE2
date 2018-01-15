#include "SimulationController.h"



const int ESC_KEY = 27;
const int LEFT_ARROW = 'a';
const int RIGHT_ARROW = 'd';

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
		UpdateSimulationUI ();

		// short delay between moves to make them visible
		Sleep (m_Speed);

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

void SimulationController::UpdateSimulationUI ()
{
	// Display timing updates
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 2 }, "Limit =  " + std::to_string (m_Maze.getTimeLimit_ms ()) + " ms");
	m_Console.WriteLine ("Elapsed =  " + std::to_string (m_Timer.getElapsed_ms ()) + " ms");

	// Display current simulation speed to user.
	m_Console.ClearLine ((SHORT)m_Maze.getHeight () + 4);
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 4 }, "Simulation Speed: " + std::to_string (m_Speed) + "ms");
}

bool SimulationController::EndSimulation ()
{
	// Check for any input from the user.
	if (_kbhit ())
	{
		// Grab the users current input and compare it.
		char choice = _getch ();

		switch (choice)
		{
			// If the right arrow key was pressed, increase the simulation speed.
		case RIGHT_ARROW:
			if (m_Speed > 25)
				m_Speed -= 25;
			break;
			// If the left arrow key was pressed, decrease the simulation speed.
		case LEFT_ARROW:
			if (m_Speed < 250)
				m_Speed += 25;
			break;
			// If the escape key was pressed, return true and signal that the application should quit.
		case ESC_KEY:
			return true;
		default:
			break;
		}
	}

	return false;
}

void SimulationController::DisplaySimulationResults ()
{
	m_Console.ClearScreen ();
	m_Maze.print ();
	DrawMousePath ();

	// Gran the fully elapsed time of the simulation and display it on screen.
	double elapsed = m_Timer.getElapsed_ms ();
	m_Console.EndLine ();
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 3 }, "Total Elapsed =  " + std::to_string (elapsed));
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 5 }, "Path errors: " + std::to_string (m_Mouse->GetErrorCount ()));
	m_Console.WaitForInput ("Press a key to exit");
}

void SimulationController::DrawMousePath ()
{
	// Get the mouse's current path within the maze.
	const std::vector<cVector2> path = m_Mouse->GetMousePath ();

	// Run through the mouses's path and print each position onto the maze.
	for (int i = 0; i < path.size (); i++)
		m_Console.WriteLine ({ (SHORT)path[i].x, (SHORT)path[i].y }, "+", FOREGROUND_INTENSITY | 5);

	// Re-draw the end character for clarification of the path.
	m_Console.WriteLine ({ (SHORT)m_Mouse->GetPos ().x, (SHORT)m_Mouse->GetPos ().y }, "E", FOREGROUND_INTENSITY | 7);
}

SimulationController::~SimulationController ()
{
	// Clean up the dynamic memory created.
	delete m_Mouse;
	m_Mouse = nullptr;
}
