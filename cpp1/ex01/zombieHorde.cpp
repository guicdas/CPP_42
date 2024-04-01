#include "Zombie.hpp"

Zombie* zombieHorde( int zNumber, std::string name ){
	Zombie *z = new Zombie[zNumber];
	for ( int i =0 ; i < zNumber; i++)
		z[i].setName(name, i);
	return (z);
}