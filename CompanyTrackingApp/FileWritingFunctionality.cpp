#include "FileWriting.h"  //header file to include the function declaration 
#include <string>
#include <iostream>		//printing to terminal etc
#include <fstream>		//file input and output, allows us to deal with these csv files etc
#include <vector>


void writeCompanyToCSV(const Company& company) {		//the company instance is passed into this temp "company" variable for putting into the csv. the const means it cannot be altered
	std::ofstream file("companies.csv", std::ios::app);	//opens or creates the .csv with a name. "ofstream" is to write to a file, ios::app tells the program to append the data to the file. so in short this line is (write to file, the file ur writing to, and to add it in)
	if (file.is_open()) {								//Basic check to see if the file is open
		file << company.getName() << ","				//If it is open, we use our getters to get info and put in into the file
			<< company.getOwner() << ","
			<< company.getAddress() << ","
			<< company.getPostcode() << "\n";
		file.close();
		std::cout << "The company was saved successfully!\n\n";
	}
	else {
		std::cerr << "Could not open file.\n";
	}
}


void writeCompaniesToCSV(const std::vector<Company>& companies) {
	std::ofstream outFile("companies.csv"); // Overwrites file

	for (const auto& company : companies) {
		outFile << company.getName() << ","
			<< company.getOwner() << ","
			<< company.getAddress() << ","
			<< company.getPostcode() << "\n";
	}

	outFile.close();
}