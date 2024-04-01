#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook(void){
	this->index = 0;
}

Phonebook::~Phonebook(void){
	std::cout << "\nGoodbye!\n\n";
}

void	Phonebook::Menu(void){
	std::cout << "\n------------\tMy Awesome Phonebook\t-----------\n\n";
	std::cout << "ADD    :\tsave a new contact.\n";
	std::cout << "SEARCH :\tdisplay a specific contact.\n";
	std::cout << "EXIT   :\tquit program.\n\n";
	std::cout << "Select option:\t";
}

std::string Phonebook::UserInput(std::string name, std::string prompt){
	std::string str = "";

	std::cout << "Enter " << name << prompt << std::endl;
	while (!std::cin.eof() && str == "")
	{
		if (std::getline(std::cin, str) && str != "")
			return (str);
		std::cout << "Can't be empty!\n";
	}
	return (NULL);
}

void	Phonebook::Add(void)
{
	std::string FName;
	std::string LName;
	std::string Nick;
	std::string PNum;
	std::string Sec;

	if (this->index > 7)
		std::cout << "Warning: overwriting info about " << this->Contacts[this->index % 8].GetFirstName() << std::endl;
	
	std::cout << std::endl;

	FName = UserInput("", "a First Name:	\t");
	LName = UserInput(FName, "'s Last name: ");
	Nick = UserInput(FName, "'s nickname: ");
	PNum = UserInput(FName, "'s phone number: ");
	Sec = UserInput(FName,"'s darkest secret: ");
	
	this->Contacts[this->index % 8].SetFirstName(FName);
	this->Contacts[this->index % 8].SetLastName(LName);
	this->Contacts[this->index % 8].SetNick(Nick);
	this->Contacts[this->index % 8].SetPhoneNum(PNum);
	this->Contacts[this->index % 8].SetSecret(Sec);

	std::cout << this->Contacts[this->index % 8].GetFirstName() << " " \
	<< this->Contacts[this->index % 8].GetLastName() \
	<< " successfully added to phonebook [" << this->index % 8 + 1 << "/8]" << std::endl;
	
	this->index++;
}

std::string	Phonebook::AddSpaces(int n)
{
	std::string	str;

	while (n >= 0 && n--)
		str.append(" ");
	return (str);
}

void	Phonebook::DisplayContact(int to_display, std::string word)
{
	std::cout << "|" << AddSpaces(10 - to_display);
	for (int i = 0; word[i] && i < 9; i++)
	{
		std::cout << word[i];
	}
	if (to_display > 10)
		std::cout << '.';
	else if (word[9])
		std::cout << word[9];
	else
		std::cout << " ";
}

void	Phonebook::DisplayBook(void)
{
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	
	for (int i = 0; !Contacts[i].GetFirstName().empty() && i < 8; i++)
	{
		std::cout << "|" << AddSpaces(9) << i + 1;
		DisplayContact(Contacts[i].GetFirstName().size(), Contacts[i].GetFirstName());
		DisplayContact(Contacts[i].GetLastName().size(), Contacts[i].GetLastName());
		DisplayContact(Contacts[i].GetNick().size(), Contacts[i].GetNick());
		std::cout << "|" << std::endl;
	}
	std::cout << " ------------------------------------------- " << std::endl;
}

int	Phonebook::DisplayIndex(std::string index)
{
	const char *str = index.data();
	int index_int = std::atoi(str);

	if (!Contacts[index_int - 1].GetFirstName().empty())
	{
		std::cout << "Info about contact nº" << index << std::endl;
		std::cout << "First Name: " << Contacts[index_int - 1].GetFirstName() << std::endl;
		std::cout << "Last Name: " << Contacts[index_int - 1].GetLastName() << std::endl;
		std::cout << "Nick: " << Contacts[index_int - 1].GetNick() << std::endl;
		std::cout << "Secret: " << Contacts[index_int - 1].GetSecret() << std::endl;
		return (1);
	}
	else
		std::cout << "The PhoneBook only has " << this->index << " contacts.\n";
	return (0);
}

void	Phonebook::Search(void)
{
	std::string index;
	int valid = 0;

	if (Contacts[0].GetFirstName().empty())
		std::cout << "No Contacts exist!\n";
	else
	{
		DisplayBook();
		while (valid == 0)
		{
			std::cout << "\nQue contacto pretende ver?:	\t";
			std::getline(std::cin, index);
			std::cout << std::endl;
			if (index >= "1" && index <= "8" && index.size() == 1)
				valid = DisplayIndex(index);
			else
				std::cout << "index inválido!\n";
		}
	}
}