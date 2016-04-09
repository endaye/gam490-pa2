#include <string.h>
#include "Unused.h"
#include "Cat.h"


Cat::Cat(float _x, char _a, char _b, float _y, int _z, char _c, double _d)
: x(_x), a(_a), b(_b), y(_y), z(_z), c(_c), d(_d)
{

}

// Read from a buffer
void Cat::deserialize( const char * const buffer ) 
{	
	// do your magic here
	memcpy(this, buffer, sizeof(Cat));
}

// Write object to a buffer
void Cat::serialize( char * const buffer ) const
{
	// do your magic here
	memcpy(buffer, this, sizeof(Cat));
}

float Cat::getX() const
{
	return this->x;
}

char Cat::getA() const
{
	return this->a;
}

char Cat::getB() const
{
	return this->b;
}

float Cat::getY() const
{
	return this->y;
}

int Cat::getZ() const
{
	return this->z;
}

char Cat::getC() const
{
	return this->c;
}

double Cat::getD() const
{
	return this->d;
}
