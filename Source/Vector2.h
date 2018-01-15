#ifndef INCLUDE_H_VECTOR2
#define INCLUDE_H_VECTOR2

#include "cVector2.h"

/* Description: Extension helper class for base cVector2*/
class Vector2
{
// Getters/Setters
public:
	/* Description: Shorthand for returning a cVector2 of type: {-1, 0}*/
	static cVector2 Left () { return cVector2 (-1, 0); }
	/* Description: Shorthand for returning a cVector2 of type: {1, 0}*/
	static cVector2 Right () { return cVector2 (1, 0); }
	/* Description: Shorthand for returning a cVector2 of type: {0, -1}*/
	static cVector2 Up () { return cVector2 (0, -1); }
	/* Description: Shorthand for returning a cVector2 of type: {0, 1}*/
	static cVector2 Down () { return cVector2 (0, 1); }
};

#endif // !INCLUDE_H_VECTOR2
