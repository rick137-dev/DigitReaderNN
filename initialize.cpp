

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
    std::normal_distribution<double> distribution(0.0, standardDeviation);

    ofstream file;
    file.open(fileAddress);
    int i, j;
    for (i = 0; i <= 783; i++)
    {
        for (j = 0; j <= 499; j++)
        {
            file << distribution(generator)
                 << ",";
        }
        file << "\n";
    }

    standardDeviation = sqrt(2 / (double)500);
    std::normal_distribution<double> distribution1(0.0, standardDeviation);
    for (i = 0; i <= 499; i++)
    {
        for (j = 0; j <= 99; j++)
        {
            file << distribution1(generator)
                 << ",";
        }
        file << "\n";
    }

    for (i = 0; i <= 99; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            file << "1"
                 << ",";
        }
        file << "\n";
    }

    file.close();
}

int main()
{
    initializeWeights();
}