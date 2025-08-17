#include <fstream> //Allows you to read / write files e.g. std::ifstream = input from file.
#include <iostream> //This allows for std::cout and std::cin
#include <limits>   //deals wits with broken user input
#include <string>
#include <map>
#include <vector>
#include <chrono> //time units
#include <thread> // for sleep
#include "Company.h"
#include "FileWriting.h"
#include "FileRead.h"

int userMenuChoice;
std::string userCompanyEditChoice;
bool systemOn = true;
bool foundCompany = false;

    
int main()
{
    std::cout << "Greetings! Welcome to the SSCMS (Super Earth Company Management System)!\n";

    while (systemOn) {
        foundCompany = false;
        std::cout << "What would you like to do?\n";
        std::cout << "1.Make a new company? \n2.Edit the details of an exisiting company?\n3.See all Companies\n4.Quit \n\n";

        std::cin >> userMenuChoice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please pick a valid option.\n\n";
        }

        switch (userMenuChoice) {
        case 1: {
            std::cout << "Certianly!\n";
            std::string companyName, owner, address, postcode;  //We declare the temp variables used to then parse into the object

            std::cin.ignore();          //Ignores any previous input so nothing is messed up
            std::cout << "Enter the Company's name: \n";
            std::getline(std::cin, companyName);           //we use getline so the user can include spaces etc, this puts the user input into companyName
            std::cout << "\n";

            std::cout << "Enter the Owner's name of the Company: \n";
            std::getline(std::cin, owner);
            std::cout << "\n";

            std::cout << "Enter the Company's Address: \n";
            std::getline(std::cin, address);
            std::cout << "\n";

            std::cout << "Enter the Comapany's postcode: \n";
            std::getline(std::cin, postcode);
            std::cout << "\n";

            Company newCompany(companyName, owner, address, postcode);  //actually making the instance/object with the user inputs.
            std::cout << newCompany.getName() << " was created! \n";        //using thew getName function to display its info 
            writeCompanyToCSV(newCompany);
            break;
        }

        case 2: {
            std::cout << "Certianly! Loading all Company Entries now...\n";
            std::cin.clear();

            std::vector<Company> companies = readCompaniesFromCSV();
            std::cout << "Comapnies Loaded!\n\n";

            for (const auto& c : companies) {                               //A for loop to loop through all the companies. "auto& c" is a reference to each company object
                std::cout << "Company Name: " << c.getName() << "\n"
                    << "Owner: " << c.getOwner() << "\n"
                    << "Address: " << c.getAddress() << "\n"
                    << "Postcode: " << c.getPostcode() << "\n"
                    << "\n\n";
            }

            std::cout << "Please type in the Company you wish to edit: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, userCompanyEditChoice);
            for (Company& company : companies) {                      //Company& company = reference to each element (no copying)  ":" in. so x in y "companies" being the vector you're looping through
                if (company.getName() == userCompanyEditChoice) {
                    std::cout << "Company Found!\n\n";
                    foundCompany = true;                                    //Check to see if we find it.
                    std::string newName, newOwner, newAddress, newPostcode;

                    std::cout << "Change Company Name: \n";
                    std::getline(std::cin, newName);
                    company.setCompanyName(newName);

                    std::cout << "Change Owner Name: \n";
                    std::getline(std::cin, newOwner);
                    company.setOwnerName(newOwner);

                    std::cout << "Change Address: \n";
                    std::getline(std::cin, newAddress);
                    company.setAddress(newAddress);

                    std::cout << "Change Postcode: \n";
                    std::getline(std::cin, newPostcode);
                    company.setPostcode(newPostcode);        
                    writeCompaniesToCSV(companies);
                    std::cout << "The Company has been successfully edited! \n\n";
                    break;
                }
                else {
                    continue;
                }
            }

            if (!foundCompany) {
                std::cerr << "NOPE!\n";
            }
            break;
        }

        case 3: {
            std::cout << "Certianly! Loading all Company Entries now...\n";
            std::vector<Company> companies = readCompaniesFromCSV();            //This calls the read function i made, which reads all the company data from the csv, it returns a vector full of companies and then puts it into a variable (vector type)
            std::cout << "Companies loaded! " << companies.size() << "\n\n";    //Companies.size tells the number of elements stored in the Company vector 

            if (companies.size() < 0) {
                std::cout << "There are currently no Companies on the Data base!\n\n";
                break;
            }

            else {
                for (const auto& c : companies) {                               //A for loop to loop through all the companies. "auto& c" is a reference to each company object
                    std::cout << "Company Name: " << c.getName() << "\n"
                        << "Owner: " << c.getOwner() << "\n"
                        << "Address: " << c.getAddress() << "\n"
                        << "Postcode: " << c.getPostcode() << "\n"
                        << "\n\n\n";
                } break;
            }
        }

        case 4:{
 
        std::cout << "Thank you for using the SSCMS! Have a Democratic Day!";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        systemOn = false;
        break;
            }
        }
    }

}

