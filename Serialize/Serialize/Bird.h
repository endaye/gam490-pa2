#ifndef BIRD_H
#define BIRD_H

class Bird
{
public:
	// constructors
	Bird();
	Bird( int _x);

	// destructor
	~Bird();

	// assignment
	Bird & operator = (const Bird &) = delete;

	// accessors
	int getX() const;
	const char *getS() const;

	// Read from a buffer
	void deserialize( const char * const buffer );

	// Write object to a buffer
	void serialize( char * const buffer ) const;

private:
	// data to serialize
	int     x;
	char	*s;

};

#endif