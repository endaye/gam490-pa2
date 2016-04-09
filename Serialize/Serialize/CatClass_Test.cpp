//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "UnitTest.h"
#include "Cat.h"


//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------
TEST( CatClass, Serialize_tests )
{
	// initial data
	Cat  data(2,3,4,5,6,7,8);

	// Check the data before the save
	CHECK( data.getX() == 2 );
	CHECK( data.getA() == 3 );
	CHECK( data.getB() == 4 );
	CHECK( data.getY() == 5 );
	CHECK( data.getZ() == 6 );
	CHECK( data.getC() == 7 );
	CHECK( data.getD() == 8 );

	// create a local buffer
	char buff[ 1024 ];

	// serialize the data
	data.serialize( buff );

	// Create a new
	Cat newData;

	// deserialize the data
	newData.deserialize( buff );

	// validate that data is the same
	CHECK( newData.getX() == 2 );
	CHECK( newData.getA() == 3 );
	CHECK( newData.getB() == 4 );
	CHECK( newData.getY() == 5 );
	CHECK( newData.getZ() == 6 );
	CHECK( newData.getC() == 7 );
	CHECK( newData.getD() == 8 );

	// check the size of the data structure
	CHECK( sizeof(Cat) == 24 );
}
