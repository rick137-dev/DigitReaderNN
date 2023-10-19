
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

       double calculateNeuronActivation(vector<double> normalized_input, int Layer, int Neuron)
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

    double calculateLastLayerActivations(vector<double> input, int Layer, int Neuron)
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

    vector<double> getFirstLayerOutput(vector<double> normalized_input)
    {

        vector<double> activations;
        for (int i = 1; i <= 500; i++)
        {
            activations.push_back(calculateNeuronActivation(normalized_input, 1, i));
        }
        return activations;
    }

    vector<double> getSecondLayerOutput(vector<double> firstLayerActivations)
    {
        vector<double> activations;
        for (int i = 1; i <= 100; i++)
        {
            activations.push_back(calculateNeuronActivation(firstLayerActivations, 2, i));
        }
        return activations;
    }

    int getThirdLayerOutput(vector<double> secondLayerActivations)
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
        int current = 1;
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

    int getNeuralNetworkOutput(int line)
    {
        if (line > 0)
        {
            vector<double> normal_input = getNormalizedInput(line);
            return getThirdLayerOutput(getSecondLayerOutput(getFirstLayerOutput(normal_input)));
        }
        else
        {
            cout << "Non Positive Line input!";
        }
    }
};