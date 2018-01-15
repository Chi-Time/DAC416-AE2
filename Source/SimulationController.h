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
	void UpdateSimulationUI ();
	bool EndSimulation ();
	void DisplaySimulationResults ();
	void DrawMousePath ();

// Members
private:
	cMaze m_Maze;
	cTimer m_Timer;
	Console m_Console;
	int m_Speed{ 200 };
	Mouse* m_Mouse{ nullptr };

};

#endif // !INCLUDE_H_SIMULATION_CONTROLLER
