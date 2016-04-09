//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "UnitTest.h"
#include "Snake.h"


//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------
TEST( SnakeClass_0, Serialize_tests )
{
	// Create and load a Medusa with several snakes

		Medusa Gorgon;

		// check medusa
		CHECK( Gorgon.getHeadSnake() == 0 );

		// Create several snakes
		Snake *s0 = new Snake(0xBACDBACD, 'r', 33.44, 55);
		Snake *s1 = new Snake(0x1234FEC1, '#', 66.77, 10201010);
		Snake *s2 = new Snake(0xCFFE0220, '2', -23456.99, 0xab);
		Snake *s3 = new Snake(0xF57C4313, '?', 1234.88, 94);

		Gorgon.insertSnake( *s0 );
		Gorgon.insertSnake( *s1 );
		Gorgon.insertSnake( *s2 );
		Gorgon.insertSnake( *s3 );

	// validate the data in the medusa

		Egg tmpEgg;
		Snake *pSnake = (Snake *)Gorgon.getHeadSnake();
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();
	
		CHECK( pSnake->getKey() == 0xF57C4313);
		CHECK( tmpEgg.a == '?');
		CHECK( tmpEgg.b == 1234.88);
		CHECK( tmpEgg.c ==  94);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();

		CHECK( pSnake->getKey() == 0xCFFE0220);
		CHECK( tmpEgg.a == '2');
		CHECK( tmpEgg.b == -23456.99);
		CHECK( tmpEgg.c ==   0xab);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();

		CHECK( pSnake->getKey() == 0x1234FEC1);
		CHECK( tmpEgg.a == '#');
		CHECK( tmpEgg.b ==  66.77);
		CHECK( tmpEgg.c == 10201010);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();

		CHECK( pSnake->getKey() == 0xBACDBACD);
		CHECK( tmpEgg.a == 'r');
		CHECK( tmpEgg.b == 33.44);
		CHECK( tmpEgg.c == 55);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake == 0);
	
		// ensure that structure is small and efficient
		CHECK( sizeof(Egg) == 16 );

	// Serialize the medusa

		// create a local buffer
		char buff[ 1024 ];

		// serialize the data
		Gorgon.serialize( buff );

	// Recreate a medusa from the serialized data

		// Create a new
		Medusa newGorgon;

		// deserialize the data
		newGorgon.deserialize( buff );

	// validate the data in the new_medusa

		pSnake = (Snake *)newGorgon.getHeadSnake();
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();
	
		CHECK( pSnake->getKey() == 0xF57C4313);
		CHECK( tmpEgg.a == '?');
		CHECK( tmpEgg.b == 1234.88);
		CHECK( tmpEgg.c ==  94);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();

		CHECK( pSnake->getKey() == 0xCFFE0220);
		CHECK( tmpEgg.a == '2');
		CHECK( tmpEgg.b == -23456.99);
		CHECK( tmpEgg.c ==   0xab);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();

		CHECK( pSnake->getKey() == 0x1234FEC1);
		CHECK( tmpEgg.a == '#');
		CHECK( tmpEgg.b ==  66.77);
		CHECK( tmpEgg.c == 10201010);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake != 0);

		tmpEgg = pSnake->getEgg();

		CHECK( pSnake->getKey() == 0xBACDBACD);
		CHECK( tmpEgg.a == 'r');
		CHECK( tmpEgg.b == 33.44);
		CHECK( tmpEgg.c == 55);

		pSnake = (Snake *)pSnake->next;
		CHECK( pSnake == 0);

}
