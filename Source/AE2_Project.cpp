#include "SimulationController.h"

//TODO: Make maze variable in Mouse a reference or Pointer type to save memory.
//TODO: Add extended features: Changing colour of pathing for all dead ends re-drawn.
//TODO: Possible implement advanced algorithm.

int main()
{
	auto simulationController = SimulationController ();
	simulationController.StartSimulation ();
}
