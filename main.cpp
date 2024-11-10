#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Transaction.hpp"
#include "menuFunctions.hpp"

int main()
{
    vector<Transaction> transactions;
    char choice;

    Transaction trans;

    fstream outFile;
    string fileNameTrans = "transactions.csv";

    system("clear");
    
    cout << endl << "Welcome to Kaveh's Budget Tracker Application!" << endl;
    cout << "----------------------------------------------" << endl << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    do
    {
        system("clear");

        cout << "Budget Tracker Application:" << endl;
        cout << "===========================" << endl << endl;
        cout << "Would you like to add a transaction? ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        if (tolower(choice) != 'n')
        {
            displayMenu(trans, transactions);
        }
    } while (tolower(choice) != 'n');

    writeToFile(transactions, outFile, fileNameTrans);

    return 0;
}   // end of main()