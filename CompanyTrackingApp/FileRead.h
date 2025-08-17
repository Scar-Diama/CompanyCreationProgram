#pragma once

#include "Company.h"
#include <vector> //Vectors are basically lists that can be altered in size, great for files with small or big things to be added or removed

std::vector<Company> readCompaniesFromCSV();