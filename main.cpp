#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Neuron.cpp"

// This program utillizes 3 layers, 500-100-10, it uses the ReLu activation function and softmax at the output layer

using namespace std;

int main()
{
    Neuron neuron;
    vector<double> test = getNormalizedInput(2);
}
