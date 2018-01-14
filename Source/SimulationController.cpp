#include <windows.h>		// for sleep()
#include <iostream>
#include <conio.h>
#include <assert.h>
#include <vector>
#include <string>
#include "SimulationController.h"
#include "cMaze.h"
#include "cTimer.h"
#include "cVector2.h"
#include "Mouse.h"
#include "Console.h"

const int ESC_KEY = 27;

SimulationController::SimulationController ()
{
	// Create a console object for interfacing with the console window.
	m_Console = Console ();

	// create a maze variable and create a new maze
	m_Maze;// = cMaze ();
	m_Maze.createRandomSize ();

	// print the maze
	m_Maze.print ();

	// Display timing updates
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 2 }, "Limit =  " + std::to_string (m_Maze.getTimeLimit_ms ()) + " ms");
	m_Console.WaitForInput ("Press a key to start the mouse.");
	m_Console.ClearLine ((SHORT)m_Maze.getHeight () + 4);

	// create a timer to keep track of elapsed time
	m_Timer;// = cTimer ();

	// ensure the maze was created successfully with a start point
	cVector2 startPos;

	//if (!maze.getStart (startPos))
	//	return 1;
	m_Maze.getStart (startPos);

	// create the "mouse"
	m_Mouse = new Mouse (startPos, m_Maze.getStrings ());

	double elapsed = m_Timer.getElapsed_ms ();
	m_Console.EndLine ();
	m_Console.WriteLine ({ 0, (SHORT)m_Maze.getHeight () + 3 }, "Total Elapsed =  " + std::to_string (elapsed));
	m_Console.WaitForInput ("Press a key to exit");

	LoopSimulation ();
}

void SimulationController::LoopSimulation ()
{
	do
	{
		// start keeping time
		m_Timer.start ();

		// make the mouse move - REPLACE WITH YOUR CODE

		// If moving left.
		if (m_Mouse->GetDir () == cVector2 (-1, 0))
		{
			// Check down first (our immediate left from this position.)
			if (m_Mouse->MoveTo (cVector2{ 0, 1 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ -1, 0 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 0, -1 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 1, 0 }))
				m_Mouse->Draw (m_Console);
		}
		// If moving down.
		else if (m_Mouse->GetDir () == cVector2 (0, 1))
		{
			// Check right first (our immediate left from this position.)
			if (m_Mouse->MoveTo (cVector2{ 1, 0 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 0, 1 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ -1, 0 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 0, -1 }))
				m_Mouse->Draw (m_Console);
		}
		// If moving right.
		else if (m_Mouse->GetDir () == cVector2 (1, 0))
		{
			// Check up first, (our immediate left from this position.)
			if (m_Mouse->MoveTo (cVector2{ 0, -1 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 1, 0 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 0, 1 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ -1, 0 }))
				m_Mouse->Draw (m_Console);
		}
		// If moving up.
		else if (m_Mouse->GetDir () == cVector2 (0, -1))
		{
			// Cbeck left first, (our immediate left from this position.)
			if (m_Mouse->MoveTo (cVector2{ -1, 0 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 0, -1 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 1, 0 }))
				m_Mouse->Draw (m_Console);
			else if (m_Mouse->MoveTo (cVector2{ 0, 1 }))
				m_Mouse->Draw (m_Console);
		}

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
			/*if (ESC_KEY == _getch ())
			return 0;*/
		}

	} while (!m_Mouse->FoundCheese ());
}

SimulationController::~SimulationController ()
{
}
