
#include <bits/stdc++.h>
#include "Neuron.h"
#include "stringProcessing.h"

double Neuron::activationReLU(double x)
{
    if (x <= 0)
    {
        return 0;
    }
    else
    {
        return x;
    }
}

double Neuron::D_activationReLU(double x)
{
    if (x <= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

Neuron::Neuron(int layer, int specificNeuron)
{
    this->layer = layer;
    this->specificNeuron = specificNeuron;
}

double Neuron::activationSoftMax(int i, double array[10])
{
    double sum = 0;
    for (int x = 0; x <= 9; x++)
    {
        sum = sum + exp(array[x]);
    }
    return (exp(array[i]) / sum);
}

void Neuron::normalize(double *array)
{
    for (int i = 0; i <= sizeof(*array); i++)
    {
        array[i] = array[i] / (double)255;
    }
}

double Neuron::calculateNeuronActivation(vector<double> normalized_input, int Layer, int Neuron)
{
    vector<double> weights = processWeightString(getWeightsGivenLayerNeuron(Layer, Neuron));
    double bias = getBias(Layer, Neuron);
    double total = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        total = total + weights[i] * normalized_input[i];
    }
    return activationReLU(total + bias);
}

vector<double> Neuron::getFirstLayerOutput(vector<double> normalized_input)
{

    vector<double> activations;
    for (int i = 1; i <= 500; i++)
    {
        activations.push_back(calculateNeuronActivation(normalized_input, 1, i));
    }
    return activations;
}

vector<double> Neuron::getSecondLayerOutput(vector<double> firstLayerActivations)
{
    vector<double> activations;
    for (int i = 1; i <= 100; i++)
    {
        activations.push_back(calculateNeuronActivation(firstLayerActivations, 2, i));
    }
    return activations;
}
