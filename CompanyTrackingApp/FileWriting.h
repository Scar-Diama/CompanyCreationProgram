#pragma once
#include "Company.h"  //We need to include this as we will be referencing the functions in here.
#include <vector>

void writeCompanyToCSV(const Company& company); //This is pretty much passing the created company into a temp variable called "company" for it to then be put into the csv
void writeCompaniesToCSV(const std::vector<Company>& companies);