#include "std_lib_facilities.h"

void reading_numbers(string name_file, vector<int>numbers);


int main()
{
    setlocale(LC_ALL, "Rus");
    vector<int>numbers;
    cout << "\n";
    return 0;
}

void reading_numbers(string name_file, vector<int>numbers)
{
    ifstream ist(name_file);
    if(!ist) error("Unable to open input file ", name_file);
    ist.exceptions(ist.exceptions() | ios_base::badbit);
    while(true)
    {
        int num;
        char ch;
        ist >> ch;
        if(ist.eof())
            break;
        if(isdigit(ch)
        {
            ist.unget();
            ist >> num;
            numbers.push_back(num);
        }
        else
            continue;
    }
}