// Ben Hawk
#include <iostream>
#include <fstream>
#include "JSON.hpp"

int main()
{
    Value* val1 = new Number{4};
    Value* val2 = new String {"I went to the store"};

    val1->print();
    std::cout << std::endl;
    val2->print();

    std::ofstream out ("JSON.txt");

    if (out.is_open())
    {
        out << val1 << std::endl << val2 << std::endl;
        out.close();
    }
    else
        throw std::logic_error("File did not open");

    delete val1;
    delete val2;

    return 0;
}
