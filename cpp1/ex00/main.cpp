#include "Zombie.hpp"

int main(void){
	std::string name;

    std::cout << "Testing Zombie.cpp constructor (stack)\n";
    std::cout << "Zombie name:\t";
    std::cin >> name;

    Zombie Z1(name);
    
    std::cout << "\nTesting newZombie.cpp on the (heap)\n";
    std::cout << "Zombie name:\t";
    std::cin >> name;

    Zombie *Z2 = newZombie(name);
    Z2->announce();
    delete Z2;

    std::cout << "\nTesting randomChump()...\n";
	std::cout << "Zombie name:\t";
	std::cin >> name;
    randomChump(name);
    return 0;
}