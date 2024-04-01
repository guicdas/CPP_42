#pragma once

#include <iostream>
#include <string>	
#include <stdlib.h>

class Zombie{
	private :
		std::string name;
	public :
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string name, int index);

};

Zombie* zombieHorde( int N, std::string name );
