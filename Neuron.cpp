
#include <bits/stdc++.h>
#include "stringProcessing.cpp"

class Neuron
{

public:
    Neuron()
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

    double activationSoftMax(int Neuron, vector<double> input)
    {
        double sum = 0;
        for (int x = 0; x <= 9; x++)
        {
            sum = sum + exp(input[x]);
        }
        return (exp(input[Neuron]) / sum);
    }

    double dotProduct(vector<double> input1, vector<double> input2)
    {
        int size = input1.size();
        double total = 0;
        for (int i = 0; i < size; i++)
        {
            total = total + input1[i] * input2[i];
        }
        return total;
    }

    vector<double> getFirstLayerActivations(vector<double> normalized_input)
    {
    }
};