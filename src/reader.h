#ifndef READER_H
#define READER_H

#include<string>
#include<set>
#include<map>

class Reader {

    private:

    int k;
    std::string filename;
    std::string text;
    std::set<char> alphabet;
    int total_kgrams = 0;
    std::map<std::string, int> kgram_counts;
    std::map<std::string, std::map<char, int>> c_follows_kgram;  // n(w, c)
    

    public:

    Reader(int k); // k > 0
    void read_the_file(const std::string& filename); // read filename
    void process_text(); //
    double kgram_frequency(const std::string& kgram) const; // compute the kgram frequency, 1st component
    double conditional_probability (const std::string& kgram, char c, double alpha) const; //compute the conditional probability, 2nd Component
};

#endif