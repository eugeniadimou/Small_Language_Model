#include"generator.h"
#include<random>
#include<vector>
#include<iostream>


using namespace  std;

Generator::Generator (const Reader& reader, double alpha, int output_chars) : reader(reader), alpha(alpha), output_chars(output_chars)  
{

};

void Generator::generate() 
{
    const auto w_counts = reader.get_kgram_counts(); // Get the kgrams from Reader

    if (w_counts.empty()) 
    {
        throw runtime_error("The kgrams were not found!");
    }

    vector<string> kgrams;
    vector<double> weights;

    for (const auto pair : w_counts)  // make pairs of kgrams and their weight
    {
        kgrams.push_back(pair.first);
        weights.push_back(static_cast<double>(pair.second));
    }

    random_device rd;  // Random number generator
    mt19937 gen(rd());
    discrete_distribution<int> distribution(weights.begin(), weights.end());
    
    int generated_index = distribution(gen); // Choose a starting kgram w according to the kgram frequencies.
    string current_w = kgrams[generated_index]; 

    cout << current_w; // Output w

}