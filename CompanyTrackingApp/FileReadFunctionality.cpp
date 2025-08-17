#include "Company.h"
#include "FileRead.h"
#include <fstream>		//file input and output
#include <sstream>		//String based input output, allows you to split strings with diriverter thing like a comma
#include <vector>		//Dynamic array that can change in size etc, needed for this as we dont know how many lines we'll need
#include <iostream>		//Input and output to the console


std::vector<Company> readCompaniesFromCSV() {   //This is a fucntion definition, where it will return a vector / list of company objects declared at the start of the function
	std::vector<Company> companies;				//creating a vector that stores Company objects, companies being the name of the vector /variable. so companies is a variable that is a vector. We use a vector here as we don't know how many lines there are in companies
	std::ifstream file("companies.csv");		//Variable for CSV for reading. ifstream is to read dat

	if (!file.is_open()) {						//This is a file open check. if it DID NOT open, this will trigger. Easy error handling.
		std::cerr << "Error: Could not open the file.\n";		//std::cerr is just like cout but for errors, they look different, thats all.
			return companies;
	}

	std::string line;							//This variable will hold each line of the file as it reads though said file
	while (std::getline(file, line)) {			//While the file is open, it will read one line at a time from the file till the end of the file.
		std::stringstream ss(line);				//A string stream allows you to break apart the line into bits by commas. Here we give string stream a variable name of ss, then put the string from (line) into it.
		std::string companyName, owner, address, postcode;		//Delcaring the variables, the same as the class to keep it more understandable

		std::getline(ss, companyName, ',');
		std::getline(ss, owner, ',');
		std::getline(ss, address, ',');
		std::getline(ss, postcode, ',');

		companies.emplace_back(companyName, owner, address, postcode);		//This constructs the object directly into the vector (its made with the variables we delcared here. once again the same as the class to keep it understandable)
	}

	file.close();
	return companies;
}