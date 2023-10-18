
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

double Neuron::activationSoftMax(int Neuron, vector<double> input)
{
    double sum = 0;
    for (int x = 0; x <= 9; x++)
    {
        sum = sum + exp(input[x]);
    }
    return (exp(input[Neuron]) / sum);
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

double Neuron::calculateLastLayerActivations(vector<double> input, int Layer, int Neuron)
{
    vector<double> weights = processWeightString(getWeightsGivenLayerNeuron(Layer, Neuron));
    double bias = getBias(Layer, Neuron);
    double total = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        total = total + weights[i] * input[i];
    }
    return bias + total;
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

int Neuron::getThirdLayerOutput(vector<double> secondLayerActivations)
{
    vector<double> activations;
    vector<double> finalOutput;
    for (int i = 1; i <= 10; i++)
    {
        activations.push_back(calculateLastLayerActivations(secondLayerActivations, 3, i));
    }

    for (int i = 1; i <= 10; i++)
    {
        finalOutput.push_back(activationSoftMax(i, activations));
    }

    double max = -2;
    int current;
    for (int i = 1; i <= 10; i++)
    {
        if (finalOutput[i] > max)
        {
            max = finalOutput[i];
            current = i;
        }
    }
    return current;
}