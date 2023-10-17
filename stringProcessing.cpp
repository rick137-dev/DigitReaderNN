
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Neuron.h"

using namespace std;
string fileAddress = "MNIST/train.csv";
double divisor = 255;

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

string getWeights(int Layer, int Neuron)
{
}

int *processWeights(string weights, int (&array)[2])
{
}

int main()
{
}