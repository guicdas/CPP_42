#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "Zombie " << this->name << " has been created and named." << std::endl;
}

Zombie::Zombie(void){
	std::cout << "Zombie " << this->name << " has been created." << std::endl;}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name, int index)
{
	char *str;

	str = index.data();
	itoa(index, str, 10);

	this->name = name + str ;
}