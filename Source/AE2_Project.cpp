#include "SimulationController.h"

//TODO: Make maze variable in Mouse a reference or Pointer type to save memory.
//TODO: Add extended features.
//TODO: Possible implement advanced algorithm.
//TODO: Implement stack to store path of mouse AI and then draw it back on screen.
//TODO: Implement check for dead ends and then display mouse errors as final stat tracking.

int main()
{
	auto simulationController = SimulationController ();
	simulationController.StartSimulation ();
}
