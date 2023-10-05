#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
string fileAddress = "MNIST/train.csv";

string getLine(string fileAddress, int i)
{
    i++;
    int x = 0;
    string test;
    ifstream file;
    file.open(fileAddress);
    while (x < i)
    {

        getline(file, test);

        x++;
    }
    file.close();
    return test;
}

void getTrainingData(int &Label, int *Results, int Row)
{
    string temp = getLine(fileAddress, 1);
}

int main()
{
    /*
        int Results[784];
        int Label;
        getTrainingData(Label, Results,1);
        cout << Label << "\n";
        int i;
        for (i = 0; i <= 783; i++)
        {
            cout << Results[i];
        }
        */
    string temp = getLine(fileAddress, 1);
    // cout << temp;
    char a = 's';
    char b = 't';
    auto c = a + b;
    cout << c;
}
