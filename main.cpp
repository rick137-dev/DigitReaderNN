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
    vector<double> input = getNormalizedInput(1);
    vector<double> activations = neuron.getFirstLayerActivations(input);
    vector<double> secondAct = neuron.getSecondLayerActivations(activations);
    vector<double> thirdSum = neuron.getThirdLayerSum(secondAct);
    for (int i = 0; i < 10; i++)
    {
        cout << thirdSum[i] << endl;
    }
}
