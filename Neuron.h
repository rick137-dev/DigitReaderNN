#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Neuron
{
    string weightsData;
    int dataPosition;

public:
    vector<int> Weights;

    Neuron()
    {
    }

    Neuron(string weightsData, int dataPosition)
    {
    }

    static double activationReLU(double x)
    {
    }
    static double D_activationReLU(double x)
    {
    }
};