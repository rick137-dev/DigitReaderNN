#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string getLine(string fileAddress)
{
    ifstream file;
    file.open(fileAddress);
    string test;
    getline(file, test);
    file.close();
    return test;
}

int main()
{
}
