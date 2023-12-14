#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "NeuralNetwork.cpp"

// This program utillizes 3 layers, 500-100-10, it uses the ReLu activation function and softmax at the output layer

// Training is done with Stochastic Gradient Descent, with mini-batches of 100 inputs

using namespace std;

int main()
{
    NeuralNetwork n;
    vector<string> lines = getSpecificLinesDataset(100, 500);

    cout << n.getNNOutput(3);
}
