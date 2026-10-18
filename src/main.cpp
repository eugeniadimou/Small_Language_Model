#include<iostream>
#include<string>
#include "reader.h"
#include"generator.h"


using namespace std;

int main (int argc, char* argv[]) 
{
    double alpha = 0.0;

    int k = 0;
    string filename = "";
    int output_chars = 0;

    if (argc == 4) 
    {
        k = stoi(argv[1]);
        filename = argv[2];
        output_chars = stoi(argv[3]);
    }
    else if (argc == 6 ) 
    {
        if (string(argv[1]) != "-a")
        {
            cerr << "Unknown option'" << argv[1] << "'!" << endl;

            return 1;
        }

        alpha = stod(argv[2]);

        if (alpha < 0.0)
        {
            cerr << "Alpha cannot be negative!" << endl;

            return 1;
        }
        
        k = stoi(argv[3]);
        filename = argv[4];
        output_chars = stoi(argv[5]);
    }
    else  
    {
        cerr << "Wrong number of arguments!" << endl;

        return 1;
    }


    if (k > output_chars) 
    {
        cerr << "k cannot be grater than the number of output characters!" << endl;
        return 1;
    }

    Reader reader(k);
    reader.read_the_file(filename);

    Generator generator(reader, alpha, output_chars);
    generator.generate();

    cout << "\n";

    return 0;
}