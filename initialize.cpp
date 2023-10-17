

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <limits>
typedef std::numeric_limits<double> dbl;

using namespace std;

void initializeWeights(string fileAddress = "Weights.csv")
{
    double standardDeviation = sqrt(2 / (double)784);
    std::default_random_engine generator;
    std::normal_distribution<double> distribution1(0.0, standardDeviation);

    ofstream file;
    file.open(fileAddress);

    // FIRST LAYER
    // 784*500 weights for first layer
    int i, j;
    for (i = 0; i < 500; i++)
    {
        for (j = 0; j < 784; j++)
        {
            file << distribution1(generator)
                 << ",";
        }
        file << "\n";
    }
    // 500 biases for first layer
    for (i = 0; i < 500; i++)
    {
        file << distribution1(generator)
             << ",";
    }
    file << "\n";
    // SECOND LAYER
    standardDeviation = sqrt(2 / (double)500);
    std::normal_distribution<double> distribution2(0.0, standardDeviation);
    // 500*100 weights for second layer
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 500; j++)
        {
            file << distribution2(generator)
                 << ",";
        }
        file << "\n";
    }
    // 100 biases for second layer
    for (j = 0; j < 100; j++)
    {
        file << distribution2(generator)
             << ",";
    }
    file << "\n";

    // SOFTMAX LAYER
    standardDeviation = sqrt(2 / (double)100);
    std::normal_distribution<double> distribution3(0.0, standardDeviation);
    // 100*10 weights for softmax layer
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 100; j++)
        {
            file << distribution3(generator)
                 << ",";
        }
        file << "\n";
    }
    // 10 biases for softmax layer
    for (i = 0; i < 10; i++)
    {
        file << distribution3(generator)
             << ",";
    }

    file.close();
}

int main()
{
    initializeWeights();
}