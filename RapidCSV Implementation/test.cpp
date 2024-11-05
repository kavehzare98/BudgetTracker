#include <iostream>
#include <vector>
#include "rapidcsv.h"

int main()
{
    rapidcsv::Document doc("test.csv");
    std::vector<int> col = doc.GetColumn<int>("Num");
    std::cout << "Read " << col.size() << " values." << std::endl;

    for (auto c : col)
    {
        std::cout << c << std::endl;
    }

    return 0;
}