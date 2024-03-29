#include <windows.h>		// for sleep()
#include <iostream>
#include <conio.h>
#include <assert.h>
#include <vector>
#include <string>
#include "cMaze.h"
#include "cTimer.h"
#include "cVector2.h"
#include "Mouse.h"
#include "Console.h"
#include "SimulationController.h"

//TODO: Clean the main function to make it more readable.
//TODO: Port mouse movement logic to seperate area.
//TODO: Extend vector2 class with static directions.
//TODO: Add extended features.
//TODO: Possible implement advanced algorithm.

//const int ESC_KEY = 27;

int main()
{
	auto simulationController = SimulationController ();

#pragma region Old_Working_Code
	//// Create a console object for interfacing with the console window.
	//Console console = Console ();

	//// create a maze variable and create a new maze
	//cMaze maze;
	//maze.createRandomSize();

	//// print the maze
	//maze.print();

	//// Display timing updates
	//console.WriteLine ({ 0, (SHORT)maze.getHeight () + 2 }, "Limit =  " + std::to_string (maze.getTimeLimit_ms ()) + " ms");
	//console.WaitForInput ("Press a key to start the mouse.");
	//console.ClearLine ((SHORT)maze.getHeight () + 4);

	//// create a timer to keep track of elapsed time
	//cTimer timer;

	//// ensure the maze was created successfully with a start point
	//cVector2 startPos;

	//if (!maze.getStart (startPos))
	//	return 1;

	//// create the "mouse"
	//Mouse mouse = Mouse (startPos, maze.getStrings ());

	//do
	//{
	//	// start keeping time
	//	timer.start ();

	//	// make the mouse move - REPLACE WITH YOUR CODE

	//	// If moving left.
	//	if (mouse.GetDir () == cVector2 (-1, 0))
	//	{
	//		// Check down first (our immediate left from this position.)
	//		if (mouse.MoveTo (cVector2{ 0, 1 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ -1, 0 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 0, -1 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 1, 0 }))
	//			mouse.Draw (console);
	//	}
	//	// If moving down.
	//	else if (mouse.GetDir () == cVector2 (0, 1))
	//	{
	//		// Check right first (our immediate left from this position.)
	//		if (mouse.MoveTo (cVector2{ 1, 0 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 0, 1 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ -1, 0 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 0, -1 }))
	//			mouse.Draw (console);
	//	}
	//	// If moving right.
	//	else if (mouse.GetDir () == cVector2 (1, 0))
	//	{
	//		// Check up first, (our immediate left from this position.)
	//		if (mouse.MoveTo (cVector2{ 0, -1 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 1, 0 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 0, 1 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ -1, 0 }))
	//			mouse.Draw (console);
	//	}
	//	// If moving up.
	//	else if (mouse.GetDir () == cVector2 (0, -1))
	//	{
	//		// Cbeck left first, (our immediate left from this position.)
	//		if (mouse.MoveTo (cVector2{ -1, 0 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 0, -1 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 1, 0 }))
	//			mouse.Draw (console);
	//		else if (mouse.MoveTo (cVector2{ 0, 1 }))
	//			mouse.Draw (console);
	//	}

	//	mouse.Draw (console);

	//	// stop keeping time
	//	timer.stop ();

	//	// Display timing updates
	//	console.WriteLine ({ 0, (SHORT)maze.getHeight () + 2}, "Limit =  " + std::to_string (maze.getTimeLimit_ms ()) + " ms");
	//	console.WriteLine ("Elapsed =  " + std::to_string (timer.getElapsed_ms ()) + " ms");

	//	// short delay between moves to make them visible
	//	Sleep (200);

	//	// Quit if Escape is pressed.
	//	if (_kbhit ())
	//	{
	//		if (ESC_KEY == _getch ())
	//			return 0;
	//	}

	//} while (!mouse.FoundCheese ());

	//double elapsed = timer.getElapsed_ms ();
	//console.EndLine ();
	//console.WriteLine ({ 0, (SHORT)maze.getHeight () + 3 }, "Total Elapsed =  " + std::to_string (elapsed));
	//console.WaitForInput ("Press a key to exit");
#pragma endregion
}
