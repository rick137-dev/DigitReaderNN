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
    vector<int> outputs = n.getOutputForRange(3, 50);
    for (int i = 0; i < outputs.size(); i++)
    {
        cout << outputs[i] << endl;
    }
}
