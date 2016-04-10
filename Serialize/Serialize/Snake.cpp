#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	memcpy(this, buffer, sizeof(Snake));
	this->pEgg = new Egg();
	memcpy(this->pEgg, buffer + sizeof(Snake), sizeof(Egg));
}

// Write object to a buffer
void Snake::serialize( char * const buffer ) const
{
	// do your magic here
	memcpy(buffer, this, sizeof(Snake));
	memcpy(buffer + sizeof(Snake), this->pEgg, sizeof(Egg));
}

// Read from a buffer
void Medusa::deserialize(const char * const buffer)
{
	// deserialize Medusa
	memcpy(this, buffer, sizeof(Medusa));

	// get the number of Snake
	int numSnake = 0;
	memcpy(&numSnake, (buffer + sizeof(Medusa)), sizeof(int));

	// deserialize the Snakes
	if (numSnake != 0)
	{
		const char * tmpBuffer = buffer + sizeof(Medusa) + sizeof(int);
		Snake ** s = (Snake **)calloc(numSnake, sizeof(Snake*));
		for (int i = 0; i < numSnake; i++) 
		{
			s[i] = new Snake();
			s[i]->deserialize(tmpBuffer);
			tmpBuffer += sizeof(Snake) + sizeof(Egg);
		}

		// relink
		
		s[0]->next = s[1];
		s[1]->next = s[2];
		s[2]->next = s[3];
		s[3]->next = 0;
		s[0]->prev = 0;
		s[1]->prev = s[0];
		s[2]->prev = s[1];
		s[3]->prev = s[2];
		this->head = s[0];
	}
}

// Write object to a buffer
void Medusa::serialize( char * const buffer ) const
{
	// serialize Medusa
	memcpy(buffer, this, sizeof(Medusa));
	if (this->head != 0)
	{
		// the number of snake
		int numSnake = 0;
		Snake * pSnake = (Snake *)this->getHeadSnake();
		while (pSnake != 0) {
			numSnake++;
			pSnake = (Snake*)pSnake->next;
		}

		// serialize Snakes
		pSnake = (Snake *)this->getHeadSnake();
		char * tmpBuffer = buffer + sizeof(Medusa);
		memcpy(tmpBuffer, &numSnake, sizeof(int));

		tmpBuffer += sizeof(int);
		for (int i = 0; i < numSnake; i++) 
		{
			pSnake->serialize(tmpBuffer);
			pSnake = (Snake *)pSnake->next;
			tmpBuffer += sizeof(Snake) + sizeof(Egg);
		}
		
	}
}
