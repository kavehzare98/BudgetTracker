#include <vector>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Transaction.hpp"

void displayMenu(Transaction&, vector<Transaction>&);
string chooseCard(fstream&, string&);

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
    this_thread::sleep_for(chrono::seconds(2));

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


    // Open outFile
    outFile.open(fileNameTrans, ios::app);

    for (auto transaction : transactions)
    {
        outFile << transaction.getDate() << ","
                << transaction.getCard() << ","
                << transaction.getAmount() << ","
                << transaction.getCategory() << ","
                << transaction.getStore() << ","
                << transaction.getDescription() << "\n";
    }

    outFile.close();

    return 0;
}


void displayMenu(Transaction &trans, vector<Transaction> &trans_array)
{
    string string_input;
    double double_input;
    string card;
    fstream file;
    string fileNameCategories = "categories.txt";
    string fileNameCards = "cards.txt";

    card = chooseCard(file, fileNameCards);
    trans.setCard(card);
    cout << endl;

    cout << "When did you make the transaction? ";
    getline(cin, string_input);
    trans.setDate(string_input);
    cout << endl;

    cout << "At what store did you make the transaction? ";
    getline(cin, string_input);
    trans.setStore(string_input);
    cout << endl;

    cout << "What is the category? ";
    getline(cin, string_input);
    trans.setCategory(string_input);
    cout << endl;

    cout << "Description? ";
    getline(cin, string_input);
    trans.setDescription(string_input);
    cout << endl;

    cout << "Transaction Amount: ";
    cin >> double_input;
    cin.ignore();
    trans.setAmount(double_input);
    cout << endl;

    trans_array.push_back(trans);
}


string chooseCard(fstream& file, string& file_name)
{
    vector<string> cards_array;
    string line;
    int num_input;

    file.open(file_name, ios::in);

    while (getline(file, line))
    {
        cards_array.push_back(line);
    }

    file.close();

    // Display Current Cards in File
    cout << "Cards: " << endl << endl;

    cout << "0. Other" << endl;

    for (int i = 0; i < cards_array.size(); i++)
    {
        cout << i + 1 << ". " << cards_array.at(i) << endl;
    }

    cout << endl << "What card did you use? ";
    cin >> num_input;
    cin.ignore();

    if (num_input <= cards_array.size() && num_input != 0)
    {
        // zero index it
        return cards_array.at(num_input - 1);
    }
    else
    {
        cout << "Please enter card name: ";
        getline(cin, line);

        file.open(file_name, ios::app);

        file << line << "\n";

        file.close();
    }

    return line;
}