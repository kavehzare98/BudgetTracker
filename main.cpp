#include <vector>
#include <fstream>
#include "Transaction.hpp"

int main()
{
    vector<Transaction> transactions;
    fstream outFile;
    string fileName = "transactions.txt";
    char choice;

    Transaction trans;
    string cardUsed;
    string date;
    string store;
    string category;
    string itemDescription;
    double dollarAmount;
    
    cout << "Welcome to Kaveh's Budget Tracker Application:" << endl;
    cout << "----------------------------------------------" << endl << endl;

    do
    {
        cout << "Would you like add a transaction? ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        if (tolower(choice) != 'n')
        {
            cout << "What card did you use? ";
            getline(cin, cardUsed);
            trans.setCard(cardUsed);

            cout << "When did you make the transaction? ";
            getline(cin, date);
            trans.setDate(date);

            cout << "At what store did you make the transaction? ";
            getline(cin, store);
            trans.setStore(store);

            cout << "What is the category? ";
            getline(cin, category);
            trans.setCategory(category);

            cout << "Description? ";
            getline(cin, itemDescription);
            trans.setDescription(itemDescription);

            cout << "Transaction Amount: ";
            cin >> dollarAmount;
            cin.ignore();
            trans.setAmount(dollarAmount);
            cout << endl << endl;

            transactions.push_back(trans);
        }
    } while (tolower(choice) != 'n');


    // Open outFile

    outFile.open(fileName, ios::app);

    // Write/ Append to 
    for (auto transaction : transactions)
    {
        outFile << transaction.getDate() << ";"
                << transaction.getCard() << ";"
                << transaction.getAmount() << ";"
                << transaction.getCategory() << ";"
                << transaction.getStore() << ";"
                << transaction.getDescription() << "\n";
    }

    return 0;
}


