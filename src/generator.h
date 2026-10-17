#ifndef GENERATOR_H
#define GENERATOR_H

#include"reader.h"

class Generator 
{
   private:
    const Reader& reader;
    double alpha;
    int output_chars;


    public:
    Generator(const Reader& reader, double alpha, int output_chars);
    void generate();
};






#endif