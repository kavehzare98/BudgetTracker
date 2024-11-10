#pragma once

#include "Transaction.hpp"
#include <fstream>

void displayMenu(Transaction&, vector<Transaction>&);
string chooseItem(fstream&, string&, string);
string addItemToFile(fstream& file, string& file_name);
void writeToFile(vector<Transaction>&, fstream&, string);