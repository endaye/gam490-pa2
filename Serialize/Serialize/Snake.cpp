#include <stdio.h>
#include <string.h>
#include "Unused.h"
#include "Snake.h"


Medusa::Medusa()
: head(0)
{
}

Medusa::~Medusa()
{
	Snake *pSnake = (Snake *)this->head;

	// delete every snake associated with Medusa
	while( pSnake != 0 )
	{
		// squirrel away for delete
		Snake *pTmp = pSnake;

		// advanced to next snake
		pSnake = (Snake *)pSnake->next;

		// goodbye old snake
		delete(pTmp);
	}
}

void Medusa::insertSnake( Snake &inSnake )
{
	// fix pointers
	if( this->head != 0 )
	{
		this->head->prev = &inSnake;
		inSnake.next = this->head;
	}
	// push to the front of head
	this->head = &inSnake;
}

Egg::Egg( char inA, double inB, int inC )
: a(inA),b(inB),c(inC)
{
}

SnakeLink::SnakeLink()
: next(0), prev(0)
{
}

Snake::Snake(int _key, char inA, double inB, int inC)
: key(_key)
{
	this->pEgg = new Egg( inA, inB, inC);
}

Snake::~Snake()
{
	delete pEgg;
}

// Accessors
const SnakeLink *Medusa::getHeadSnake( ) const
{
	return head;
}

const int Snake::getKey() const
{
	return this->key;
}

const Egg &Snake::getEgg() const
{
	return *this->pEgg;
}


// Read from a buffer
void Snake::deserialize( const char * const buffer )
{
	// do your magic here
    UNUSED_VAR(buffer);
}

// Write object to a buffer
void Snake::serialize( char * const buffer ) const
{
	// do your magic here
    UNUSED_VAR(buffer);
}

// Read from a buffer
void Medusa::deserialize( const char * const buffer )
{
	// do your magic here
    UNUSED_VAR(buffer);
}

// Write object to a buffer
void Medusa::serialize( char * const buffer ) const
{
	// do your magic here
    UNUSED_VAR(buffer);
}
