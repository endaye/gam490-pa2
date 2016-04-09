#ifndef DOG_H
#define DOG_H

class Dog
{
public:
	// big four
	Dog(int _x, char _a, float _y, int _z);
	Dog() = default;
	Dog & operator = (const Dog &) = default;
	~Dog() = default;

	// Read from a buffer
	void deserialize( const char * const buffer );

	// Write object to a buffer
	void serialize( char * const buffer ) const;

	// accessors
	int		getX() const;
	char	getA() const;
	float	getY() const;
	int		getZ() const;

private:
	// data to serialize
	int		x;
	char	a;
	float	y;
	int		z;

};



#endif