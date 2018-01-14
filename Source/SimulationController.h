#ifndef INCLUDE_H_SIMULATION_CONTROLLER
#define INCLUDE_H_SIMULATION_CONTROLLER

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

class SimulationController
{
// Methods
public:
	SimulationController ();
	void StartSimulation ();
	~SimulationController ();

// Methods
private:
	bool MazeCreated ();
	void DisplayIntroMenu ();
	void LogCreationError ();
	void LoopSimulation ();
	void UpdateSimulation ();
	void UpdateTimer ();
	bool EndSimulation ();
	void DisplaySimulationResults ();

// Members
private:
	cMaze m_Maze;
	cTimer m_Timer;
	Console m_Console;
	Mouse* m_Mouse{ nullptr };

};

#endif // !INCLUDE_H_SIMULATION_CONTROLLER
