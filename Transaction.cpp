#include "Transaction.hpp"

Transaction::Transaction()
{
    cardUsed = "";
    date = "";
    store = "";
    category = "";
    itemDescription = "";
    dollarAmount = 0.00;
    numTransactions++;
}

Transaction::Transaction(string cardUsed, string date, string store, string category, string itemDescription, double dollarAmount)
{
    this->cardUsed = cardUsed;
    this->date = date;
    this->store = store;
    this->category = category;
    this->itemDescription = itemDescription;
    this->dollarAmount = dollarAmount;
    numTransactions++;
}

void Transaction::setCard(string card)
{
    cardUsed = card;
}

void Transaction::setDate(string date)
{
    this->date = date;
}

void Transaction::setStore(string store)
{
    this->store = store;
}

void Transaction::setCategory(string category)
{
    this->category = category;
}

void Transaction::setDescription(string itemDescription)
{
    this->itemDescription = itemDescription;
}

void Transaction::setAmount(double dollarAmount)
{
    this->dollarAmount = dollarAmount;
}

string Transaction::getCard() const
{
    return cardUsed;
}

string Transaction::getDate() const
{
    return date;
}

string Transaction::getStore() const
{
    return store;
}

string Transaction::getCategory() const
{
    return category;
}

string Transaction::getDescription() const
{
    return itemDescription;
}

double Transaction::getAmount() const
{
    return dollarAmount;
}

int Transaction::getNumTransact()
{
    return Transaction::numTransactions;
}

void Transaction::printInfo()
{
    cout << "Item Description:\t" << itemDescription << endl
         << "Category:\t\t" << category << endl
         << setprecision(2) << fixed
         << "Dollar Amount:\t\t$ " << dollarAmount << endl
         << "Date:\t\t\t" << date << endl
         << "Store:\t\t\t" << store << endl
         << "Card Used:\t\t" << cardUsed << endl << endl;
}

int Transaction::numTransactions = 0;
