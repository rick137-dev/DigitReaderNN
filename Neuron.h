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
    double calculateNeuronActivation(vector<double> input, int Layer, int Neuron) {}

    vector<double> getFirstLayerOutput(vector<double> normalized_input)
    {
    }
    vector<double> getSecondLayerOutput(vector<double> input) {}

    int getThirdLayerOutput(vector<int> input) {}

    double calculateLastLayerActivations() {}
};