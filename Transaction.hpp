#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using std::cout, std::cin, std::endl, std::string, std::setprecision, std::fixed, std::vector, std::ios, std::fstream;

class Transaction {
private:
    string cardUsed;
    string date;
    string store;
    string category;
    string itemDescription;
    double dollarAmount;
    static int numTransactions;

public:
    Transaction();
    Transaction(string, string, string, string, string, double);

    void setCard(string card);
    void setDate(string date);
    void setStore(string store);
    void setCategory(string category);
    void setDescription(string itemDescription);
    void setAmount(double dollarAmount);
    
    string getCard() const;
    string getDate() const;
    string getStore() const;
    string getCategory() const;
    string getDescription() const;
    double getAmount() const;
    static int getNumTransact();
    void printInfo();
};