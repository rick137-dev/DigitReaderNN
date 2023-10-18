
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Neuron.h"

using namespace std;

string getSpecificLineDataset(int line)
{
    string fileAddress = "MNIST/train.csv";
    line++;
    int x = 0;
    string test;
    ifstream file;
    file.open(fileAddress);
    while (x < line)
    {

        getline(file, test);

        x++;
    }
    file.close();
    return test;
}

string getSpecificLineWeights(int line)
{
    string fileAddress = "Weights.csv";
    line++;
    int x = 0;
    string test;
    ifstream file;
    file.open(fileAddress);
    while (x < line)
    {

        getline(file, test);

        x++;
    }
    file.close();
    return test;
}

// This function allocates vector on stack and copies it to return it, must find fix for efficiency (allocate on heap and return pointer)
vector<int> processString(string input)
{
    vector<int> numbers;

    stringstream ss(input);
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        numbers.push_back(stoi(substr));
    }
    return numbers;
}
// same inefficiency here
vector<double> getNormalizedWeights(int line)
{
    vector<int> weightsI = processString(getSpecificLineWeights(line));
    vector<double> final;
    for (int i = 0; i < weightsI.size(); i++)
    {
        final.push_back((weightsI[i]) / (double)255);
    }
    return final;
}

int main()
{
}