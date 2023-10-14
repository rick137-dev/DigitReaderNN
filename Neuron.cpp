
#include <bits/stdc++.h>
#include "Neuron.h"

Neuron::Neuron(string weightsData, int dataPosition)
{
    this->weightsData = weightsData;
    this->dataPosition = dataPosition;
}

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
