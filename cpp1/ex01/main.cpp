#include "Zombie.hpp"

int main(void){
	std::string name;
	std::string num;
	int ZombieNumber;
	const char *str;

    std::cout << "Testing zombieHorde.cpp\n";
    std::cout << "ZombieHorde name:\t";
    std::cin >> name;
	std::cout << "How much zombies:\t";
    std::cin >> num;

	str = num.data();

	ZombieNumber = std::atoi(str);

    Zombie *firstZombie = zombieHorde(ZombieNumber, name);
    for(int i=0; i < ZombieNumber ; i++)
		firstZombie[i].announce();
	delete [] firstZombie;

    return 0;
}