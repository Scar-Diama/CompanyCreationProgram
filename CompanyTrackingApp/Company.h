#pragma once		//This protects your classes etc from being defined more than once.

#include <string>	//access string libary 

class Company {
public:
	Company();		//Default constructor. Think of the cookie cutter. it lets the complier know that there isnt any information in it right now. It's just your standard constructor that avoids any issues if the user created an object with nothing in it.
	Company(std::string companyName, std::string owner, std::string address, std::string postcode); //and this is the dough to cut ingredients in it. This will hold information about the object.
																									//to pass into the private variables
																									
	//These are getters, these let you get details on a class, their functionaility is determined in the cpp file. They're bascially functions
	std::string getName() const;	
	std::string getOwner() const;
	std::string getAddress() const;
	std::string getPostcode() const;

	//Setters, these allow the user to change these protected values.
	void setCompanyName(const std::string& newCompanyName);	//Void = returns nothing, const = wont be modified or altered (even during passing), ="& newName" (reference) passing info to the private variable. better than copying as it's quicker and saves memory.
	void setOwnerName(const std::string& newOwnerName);
	void setAddress(const std::string& newAddress);
	void setPostcode(const std::string& newPostcode);

private:
	//These will be where the details are actually stored, we make them private so they're protected from any accidental change.
	std::string companyName;
	std::string owner;
	std::string address;
	std::string postcode;

};