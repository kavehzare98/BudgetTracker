#include "menuFunctions.hpp"

void displayMenu(Transaction &trans, vector<Transaction> &trans_array)
{
    string stringInput;
    double double_input;
    string card;
    string category;
    fstream file;
    string fileNameCategories = "categories.txt";
    string fileNameCards = "cards.txt";

    stringInput = chooseItem(file, fileNameCards, "Card");
    trans.setCard(stringInput);
    cout << endl;

    cout << "When did you make the transaction? " << endl << endl
         << "Format: YYYY-MM-DD" << endl
         << "e.g. 2024-10-08" << endl << endl
         << "Date: ";
    getline(cin, stringInput);
    trans.setDate(stringInput);
    cout << endl;

    cout << "At what store did you make the transaction? ";
    getline(cin, stringInput);
    trans.setStore(stringInput);
    cout << endl;

    stringInput = chooseItem(file, fileNameCategories, "Category");
    trans.setCategory(stringInput);
    cout << endl;

    cout << "Description? ";
    getline(cin, stringInput);
    trans.setDescription(stringInput);
    cout << endl;

    cout << "Transaction Amount: ";
    cin >> double_input;
    cin.ignore();
    trans.setAmount(double_input);
    cout << endl;

    trans_array.push_back(trans);
}   // end of displayMenu()

string addItemToFile(fstream& file, string& file_name)
{
    string input;

    cout << "Please enter item: ";
    getline(cin, input);

    file.open(file_name, ios::app);

    file << input << "\n";

    file.close();

    return input;
}   // end of addItemToFile

string chooseItem(fstream& file, string& file_name, string item)
{
    vector<string> array;
    string line;
    int num_input;

    file.open(file_name, ios::in);

    while (getline(file, line))
    {
        array.push_back(line);
    }

    file.close();

    // Display Current Cards in File
    cout << "Please choose a " << item << ":" << endl << endl
         << "0. Other" << endl;

    for (int i = 0; i < array.size(); i++)
    {
        cout << i + 1 << ". " << array.at(i) << endl;
    }

    cout << endl << item << ": ";
    cin >> num_input;
    cin.ignore();

    if (num_input <= array.size() && num_input != 0)
    {
        // zero index it
        return array.at(num_input - 1);
    }
    else
    {
        return addItemToFile(file, file_name);
    }
}   // end of chooseItem() function




void writeToFile(vector<Transaction>& transactions, fstream& file, string file_name)
{
        // Open outFile
    file.open(file_name, ios::app);

    for (auto transaction : transactions)
    {
        file    << transaction.getDate() << ","
                << transaction.getCard() << ","
                << transaction.getAmount() << ","
                << transaction.getCategory() << ","
                << transaction.getStore() << ","
                << transaction.getDescription() << "\n";
    }
    file.close();
}