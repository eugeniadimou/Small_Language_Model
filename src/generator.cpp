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

    int characters_printed = current_w.length();


    const auto& alphabet = reader.get_alphabet();
    vector<char> alphabet_vec(alphabet.begin(), alphabet.end());

    while (characters_printed < output_chars)
    {
        vector<double> char_probs;
        double probability_sum = 0.0;

        for (char next_char_c : alphabet_vec) 
        {
            double char_prob = reader.conditional_probability(current_w, next_char_c, alpha);
            char_probs.push_back(char_prob);
            probability_sum += char_prob;
        }


        if (alpha == 0.0 && probability_sum == 0.0)  // If alpha=0 and w has no transitions, stop
        {
            break;
        }

        discrete_distribution<int> next_char_c_dist(char_probs.begin(), char_probs.end());
        char next_char = alphabet_vec[next_char_c_dist(gen)]; // Sample the next character c

        cout << next_char; // Output c

        current_w = current_w.substr(1) + next_char; // Set new w with the sampled character c

        characters_printed++;
    }


}