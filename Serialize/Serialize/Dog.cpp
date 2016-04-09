#include <string.h>
#include "Unused.h"
#include "Dog.h"


Dog::Dog(int _x, char _a,float _y, int _z)
: x(_x), a(_a), y(_y), z(_z)
{
}

// Read from a buffer
void Dog::deserialize( const char * const buffer ) 
{
	// do your magic here
   UNUSED_VAR(buffer);
}

// Write object to a buffer
void Dog::serialize( char * const buffer ) const
{
	// do your magic here
   UNUSED_VAR(buffer);
}

int	Dog::getX() const
{
	return this->x;
}

char Dog::getA() const
{
	return this->a;
}

float Dog::getY() const
{
	return this->y;
}

int Dog::getZ() const
{
	return this->z;
}

