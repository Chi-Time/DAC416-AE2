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
public:
	SimulationController ();
	void LoopSimulation ();
	~SimulationController ();

private:
	cMaze m_Maze;
	Mouse* m_Mouse{ nullptr };
	cTimer m_Timer;
	Console m_Console;

};

#endif // !INCLUDE_H_SIMULATION_CONTROLLER
