//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include <string.h>
#include "UnitTest.h"
#include "Bird.h"

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------
TEST( BirdClass, Serialize_tests )
{
	// this string is only there for testing purposes
	const char *refText = "This is a test to have a long string to Serialize";

	// initial data
	Bird  data(0x5555AAAA);

	// Check the data before the save
	CHECK( data.getX() == 0x5555AAAA );
	CHECK( strcmp( data.getS(), refText ) == 0 );

	// create a local buffer
	char buff[ 1024 ];

	// serialize the data
	data.serialize( buff );

	// Create a new
	Bird newData;

	// deserialize the data
	newData.deserialize( buff );

	// validate that data is the same
	CHECK( newData.getX() == 0x5555AAAA );
	CHECK( strcmp( newData.getS(), refText ) == 0 );

	// check the size of the data structure
	CHECK( sizeof(Bird) == 8 );
}
