
#include <bits/stdc++.h>
#include "Neuron.h"

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

Neuron::Neuron(int layer, int specificNeuron)
{
    this->layer = layer;
    this->specificNeuron = specificNeuron;
}
