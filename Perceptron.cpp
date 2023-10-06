#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Perceptron
{
public:
    int learningRate;
    vector<int> Weights;

    Perceptron()
    {
    }

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

    double activationSigmoid(double x)
    {

        return (1 / (1 + exp(-x)));
    }

    double activationTanh(double x)
    {
        return ((exp(2 * x) - 1) / (exp(2 * x) + 1));
    }
};