#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

class Contact {

	private :
		std::string FirstName;
		std::string LastName;
		std::string Nick;
		std::string PhoneNum;
		std::string Secret;
	public :
		Contact(void);
		~Contact(void);
		std::string GetFirstName(void);
		std::string GetLastName(void);
		std::string GetNick(void);
		std::string GetPhoneNum(void);
		std::string GetSecret(void);
		void SetFirstName(std::string str);
		void SetLastName(std::string str);
		void SetNick(std::string str);
		void SetSecret(std::string str);
		void SetPhoneNum(std::string str);
};
