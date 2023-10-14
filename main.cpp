#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Neuron.h"

// The initialize.cpp file is to set the weights equal to random numbers
// This program utillizes 3 layers, 500-100-10, it uses the ReLu activation function and softmax at the output layer

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

void processLine(int &pixelValues, int Line)
{
}

int main()
{
    int trainingData[784];
    Neuron neuron;
    double LearningRate = 0.09;
}
