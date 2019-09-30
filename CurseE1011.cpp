#include "std_lib_facilities.h"

void reading_numbers(string& name_file, vector<int>& numbers);
int sum(vector<int>& numbers);


int main()
{
    setlocale(LC_ALL, "Rus");
    vector<int>numbers;
    string name_file;
    cout << "Enter a file name for reading numbers:\n";
    cin >> name_file;
    reading_numbers(name_file, numbers);
    cout << "The sum of all integers stored in a text file " << name_file << " is equal to -- " << sum(numbers) << '\n'; 
    return 0;
}

void reading_numbers(string& name_file, vector<int>& numbers)
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
        if(isdigit(ch))
        {
            ist.unget();
            ist >> num;
            numbers.push_back(num);
        }
        else
            continue;
    }
}

int sum(vector<int>& numbers)
{
    int s = 0;
    for(int x: numbers)
        s += x;
    return s;
}