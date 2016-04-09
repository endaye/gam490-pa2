//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "UnitTest.h"
#include "Dog.h"


//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------
TEST( DogClass, Serialize_tests )
{
	// initial data
	Dog  data(2,3,4,5);

	// Check the data before the save
	CHECK( data.getX() == 2 );
	CHECK( data.getA() == 3 );
	CHECK( data.getY() == 4 );
	CHECK( data.getZ() == 5 );

	// create a local buffer
	char buff[ 1024 ];

	// serialize the data
	data.serialize( buff );

	// Create a new
	Dog newData;

	// deserialize the data
	newData.deserialize( buff );

	// validate that data is the same
	CHECK( newData.getX() == 2 );
	CHECK( newData.getA() == 3 );
	CHECK( newData.getY() == 4 );
	CHECK( newData.getZ() == 5 );

	// check the size of the data structure
	CHECK( sizeof(Dog) == 16 );
}
