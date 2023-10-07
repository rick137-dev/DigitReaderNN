

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <random>

using namespace std;

double HeInit(int numberOfInputs)
{
    double standardDeviation = sqrt(2 / numberOfInputs);
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, standardDeviation);
    return distribution(generator);
}

void initializeWeights(string fileAddress, int Width, int Length)
{
}

int main()
{

    initializeWeights("Weights.csv", 1, 1);
}