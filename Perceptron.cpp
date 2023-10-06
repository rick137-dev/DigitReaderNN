#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Perceptron
{
public:
    double learningRate;
    vector<int> Weights;

    Perceptron()
    {
    }
    // These are the 3 activation functions for the hidden layers of the NN
    // The name with a D prefix represents the derivatives of these functions
    double activationReLU(double x)
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

    double D_activationReLU(double x)
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

    double activationSigmoid(double x)
    {

        return (1 / (1 + exp(-x)));
    }

    double D_activationSigmoid(double x)
    {
        return activationSigmoid(x) * (1 - activationSigmoid(x));
    }

    double activationTanh(double x)
    {
        return ((exp(2 * x) - 1) / (exp(2 * x) + 1));
    }

    double D_activationTanh(double x)
    {
        return 1 - (activationTanh(x)) * (activationTanh(x));
    }
};