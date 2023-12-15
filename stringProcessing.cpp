
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

inline string getSpecificLineDataset(int line)
{
    string fileAddress = "MNIST/train.csv";
    line++;
    int x = 0;
    string test;
    ifstream file;
    file.open(fileAddress);
    while (x < line)
    {

        getline(file, test);

        x++;
    }
    file.close();
    return test;
}

string getSpecificLineWeights(int line)
{

    string fileAddress = "Weights.csv";
    int x = 0;
    string test;
    ifstream file;
    file.open(fileAddress);
    while (x < line)
    {

        getline(file, test);

        x++;
    }
    file.close();
    return test;
}

vector<string> getSpecificLinesDataset(int startLine, int endLine)
{
    string fileAddress = "MNIST/train.csv";
    if (startLine == 0)
    {
        startLine++;
    }

    vector<string> lines;
    string test;
    ifstream file;
    file.open(fileAddress);
    int x = 0;

    while (x < startLine)
    {

        getline(file, test);

        x++;
    }

    while (x <= endLine)
    {
        getline(file, test);
        lines.push_back(test);
        x++;
    }

    return lines;
}

vector<double> normalizeVector(vector<int> input)
{
    vector<double> output;
    for (int x = 0; x < input.size(); x++)
    {
        output[x] = input[x] / 255;
    }

    return output;
}

string getWeightsGivenLayerNeuron(int Layer, int Neuron)
{

    if (Layer == 1)
    {
        return getSpecificLineWeights(Neuron);
    }
    else if (Layer == 2)
    {
        return getSpecificLineWeights(501 + Neuron);
    }
    else if (Layer == 3)
    {
        return getSpecificLineWeights(602 + Neuron);
    }
    else
    {
        return NULL;
    }
}

// This function allocates vector on stack and copies it to return it, must find fix for efficiency (allocate on heap and return pointer)
vector<int> processInputString(string input)
{
    vector<int> numbers;
    stringstream ss(input);
    string substr;
    // first char is label, not part of input
    getline(ss, substr, ',');

    while (ss.good())
    {
        getline(ss, substr, ',');
        numbers.push_back(stoi(substr));
    }
    return numbers;
}

int getLabel(string input)
{
    stringstream ss(input);
    string substr;
    getline(ss, substr, ',');
    return stoi(substr);
}

int getLabel(int line)
{
    string input = getSpecificLineDataset(line);
    stringstream ss(input);
    string substr;
    getline(ss, substr, ',');
    return stoi(substr);
}

// same inefficiency
vector<double> processWeightString(string input)
{
    vector<double> numbers;
    stringstream ss(input);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        numbers.push_back(stod(substr));
    }
    return numbers;
}

// same inefficiency here
vector<double> getNormalizedInput(int line)
{
    vector<int> input = processInputString(getSpecificLineDataset(line));
    vector<double> final;
    for (int i = 0; i < input.size(); i++)
    {
        final.push_back((input[i]) / (double)255);
    }
    return final;
}

vector<double> getNormalizedInput(string input)
{
    vector<int> NumInput = processInputString(input);
    vector<double> final;
    for (int i = 0; i < NumInput.size(); i++)
    {
        final.push_back((NumInput[i]) / (double)255);
    }
    return final;
}

vector<double> getBiases(int Layer)
{
    if (Layer == 1)
    {
        return processWeightString(getSpecificLineWeights(501));
    }
    else if (Layer == 2)
    {
        return processWeightString(getSpecificLineWeights(602));
    }
    else if (Layer == 3)
    {
        return processWeightString(getSpecificLineWeights(613));
    }
}
