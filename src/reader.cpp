#include "reader.h"
#include <stdexcept>
#include <fstream>
#include<stdexcept>

using namespace std;


Reader::Reader(int k) : k(k) // k > 0
{
 if (k <= 0 ) 
 {
    throw invalid_argument("k must be a positive integer!");
 }
}



void Reader::read_the_file(const std::string& filename) // read filename, copy constructor
{
    ifstream file(filename);

    if(!file.is_open()) 
    {
        throw runtime_error("Could not open file: " + filename);
    }

    string line;
    text = "";

    while(getline(file, line)) 
    {
        text += line;
    }

    process_text();
}



void Reader::process_text() 
{

    if (text.length() < static_cast<size_t>(k)) 
    {
        throw runtime_error("k is too big for this file!");
    }


    for (int i = 0; i <= text.length() - k; i++)  
    {
        string kgram = text.substr(i, k); //extract the k-grams


        for (char text_character : kgram) //create the alphabet Sigma
        {
            alphabet.insert(text_character);
        }

        total_kgrams++;  // total number of kgrams
        kgram_counts[kgram]++; // each kgram and its number of appeareances

        if (i + k < text.length()) 
        {
            char c = text[i + k];
            alphabet.insert(c);
            c_follows_kgram[kgram][c]++;  // n(w, c)
        }
    }
}



double Reader::kgram_frequency(const string& kgram) const  //1st Component
{
    auto number_of_counts = kgram_counts.find(kgram);

    if (number_of_counts == kgram_counts.end() || total_kgrams == 0) 
    {
        return 0.0;
    }

    return static_cast<double>(number_of_counts->second) / total_kgrams;
}



double Reader::conditional_probability(const string& kgram, char c, double alpha) const // 2nd Component
{
    int n_kgrams = 0;

    auto it_n_kgrams = kgram_counts.find(kgram);
    if (it_n_kgrams != kgram_counts.end())   // n(w) 
    {
        n_kgrams = it_n_kgrams->second;
    }

    int n_kgrams_c = 0;

    auto it_n_kgrams_c = c_follows_kgram.find(kgram);  //n(w,c)
    if (it_n_kgrams_c != c_follows_kgram.end()) //prwto map
    {
        auto it_char = it_n_kgrams_c->second.find(c); //deutero map
        if (it_char != it_n_kgrams_c->second.end()) 
        {
            n_kgrams_c = it_char->second;
        }
    }

    int abs_sigma = alphabet.size(); //absolut value of sigma

    if (it_n_kgrams == kgram_counts.end() && alpha == 0) 
    {
        throw runtime_error("Cannot divide with 0!");
    }

    return (static_cast<double>(n_kgrams_c) + alpha) / (static_cast<double>(n_kgrams) + alpha * abs_sigma); // P(c|w)
} 