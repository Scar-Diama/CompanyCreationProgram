#pragma once
#include "Company.h"		//including the header file so we can write the logic for the getters etc
#include <string>

Company::Company() {		//This is the default constructor, this will run when a company has been given no information. It lets users make a standard object first, then details can come in later
	companyName = "";
	owner = "";
	address = "";
	postcode = "";
}

//Parameterized constructor
Company::Company(std::string companyName, std::string owner, std::string address, std::string postcode) {

	this->companyName = companyName;
	this->owner = owner;
	this->address = address;
	this->postcode = postcode;
}

//Getter functions with logic, this gets the values of the objects private variables

std::string Company::getName() const {			//Const means it will not modify the info thats pulled at all, its an extra layer of protection.
	return companyName;
}

std::string Company::getOwner() const {
	return owner;
}

std::string Company::getAddress() const {
	return address;
}

std::string Company::getPostcode() const {
	return postcode;
}

//Setter function logic, these will updatge the private variables of a class safely and securely.
void Company::setCompanyName(const std::string& newCompanyName) {
	companyName = newCompanyName;		//Setting the new company name to the private variable.
}

void Company::setOwnerName(const std::string& newOwnerName) {
	owner = newOwnerName;
}

void Company::setAddress(const std::string& newAddress) {
	address = newAddress;
}

void Company::setPostcode(const std::string& newPostcode) {
	postcode = newPostcode;
}