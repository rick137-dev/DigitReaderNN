
#include <bits/stdc++.h>
#include "stringProcessing.cpp"

class NeuralNetwork
{

public:
    NeuralNetwork()
    {
    }
    string fileAddress = "Weights.csv";

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
        int size2 = input2.size();
        if (size != size2)
        {
            cout << "ERROR WITH dotProduct!";
            return -1;
        }
        double total = 0;
        for (int i = 0; i < size; i++)
        {
            total = total + input1[i] * input2[i];
        }
        return total;
    }

    vector<double> getFirstLayerActivations(vector<double> normalized_input)
    {
        vector<double> activations;
        vector<double> biases = getBiases(1);
        vector<double> weights;
        string between;

        ifstream file;
        file.open(fileAddress);

        for (int i = 0; i < 500; i++)
        {

            getline(file, between);
            weights = processWeightString(between);

            activations.push_back(activationReLU(dotProduct(normalized_input, weights) + biases[i]));
        }
        file.close();
        return activations;
    }

    vector<double> getSecondLayerActivations(vector<double> firstLayerActivations)
    {
        vector<double> secondActivations;
        vector<double> biases = getBiases(2);
        vector<double> weights;
        string between;

        ifstream file;
        file.open(fileAddress);
        // skip to line 502
        for (int i = 0; i < 501; i++)
        {
            getline(file, between);
        }

        for (int i = 0; i < 100; i++)
        {

            getline(file, between);
            weights = processWeightString(between);

            secondActivations.push_back(activationReLU(dotProduct(firstLayerActivations, weights) + biases[i]));
        }
        file.close();
        return secondActivations;
    }

    // calculates vector sums before softmax
    vector<double> getThirdLayerSum(vector<double> secondActivations)
    {

        vector<double> thirdSums;
        vector<double> biases = getBiases(3);
        vector<double> weights;
        string between;

        ifstream file;
        file.open(fileAddress);
        // skip to line 502
        for (int i = 0; i < 602; i++)
        {
            getline(file, between);
        }

        for (int i = 0; i < 10; i++)
        {

            getline(file, between);
            weights = processWeightString(between);

            thirdSums.push_back(activationReLU(dotProduct(secondActivations, weights) + biases[i]));
        }
        file.close();
        return thirdSums;
    }

    int NeuralNetworkOutput(vector<double> thirdSums)
    {
        vector<double> activations;
        int i;
        for (i = 0; i < 10; i++)
        {
            activations.push_back(activationSoftMax(i, thirdSums));
        }

        int current;
        double max = 0;
        for (i = 0; i < 10; i++)
        {
            if (activations[i] > max)
            {
                max = activations[i];
                current = i;
            }
        }

        return current;
    }

    int getNNOutput(int line)
    {
        return NeuralNetworkOutput(getThirdLayerSum(getSecondLayerActivations(getFirstLayerActivations(getNormalizedInput(line)))));
    }

    vector<double> getCorrectActivationsVector(int line)
    {
        int Label = getLabel(line);
        vector<double> results;
        for (int i = 0; i < 10; i++)
        {
            results.push_back(0);
        }
        results[Label] = 1;
        return results;
    }

    vector<double> getErrorVector(int line)
    {
        vector<double> sums = getThirdLayerSum(getSecondLayerActivations(getFirstLayerActivations(getNormalizedInput(line))));
        vector<double> activations;
        for (int i = 0; i < 10; i++)
        {
            activations.push_back(activationSoftMax(i, sums));
        }

        vector<double> errors;
        double error;
        for (int i = 0; i < 10; i++)
        {
            error = (activations[i] - getCorrectActivationsVector(line)[i]) * (activations[i] - getCorrectActivationsVector(line)[i]) / (double)2;
            errors.push_back(error);
        }
    }

    // faster output calculation due to less memory interaction, still too slow for stochastic gradient descent
    vector<int> getOutputForRange(int startLine, int endLine)
    {
        vector<int> outputs;
        vector<string> lines = getSpecificLinesDataset(startLine, endLine);
        vector<double> normalizedInput;

        for (int i = 0; i < lines.size(); i++)
        {
            normalizedInput = getNormalizedInput(lines[i]);
            outputs.push_back(NeuralNetworkOutput(getThirdLayerSum(getSecondLayerActivations(getFirstLayerActivations(normalizedInput)))));
        }

        return outputs;
    }

    // function for backpropagation, used for stochastic gradient descent
    void backPropagate(int startLine, int endLine, double learningRate)
    {
    }

    // divides the training set into batches then backpropagates through each one
    void trainNeuralNetwork(int batchsize)
    {
    }
};