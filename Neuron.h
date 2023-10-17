#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Neuron
{

public:
    int layer;
    int specificNeuron;

    Neuron()
    {
    }
    Neuron(int layer, int specificNeuron) {}

    static double activationReLU(double x)
    {
    }
    static double D_activationReLU(double x)
    {
    }
    static double activationSoftMax(int i, double array[10])
    {
    }
    void normalize(double *array)
    {
    }
    int testInput() {}

    void backPropagate()
    {
    }
};