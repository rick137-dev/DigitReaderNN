
#include <bits/stdc++.h>
#include "Neuron.h"
#include "cuda_runtime.h"

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
