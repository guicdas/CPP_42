#include "Contact.hpp"

Contact::Contact(void){

}

Contact::~Contact(void){

}

std::string Contact::GetFirstName(void){
	return (this->FirstName);
}

std::string Contact::GetLastName(void){
	return (this->LastName);
}

std::string Contact::GetSecret(void){
	return (this->Secret);
}

std::string Contact::GetPhoneNum(void){
	return (this->PhoneNum);
}

std::string Contact::GetNick(void){
	return (this->Nick);
}

void	Contact::SetFirstName(std::string str){
	this->FirstName = str;
}

void	Contact::SetLastName(std::string str){
	this->LastName = str;
}

void	Contact::SetNick(std::string str){
	this->Nick = str;
}

void	Contact::SetPhoneNum(std::string str){
	this->PhoneNum = str;
}

void	Contact::SetSecret(std::string str){
	this->Secret = str;
}