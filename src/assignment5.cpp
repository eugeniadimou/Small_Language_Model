#include<iostream>
#include<string>

using namespace std;

int main (int argc, char* argv[]) 
{
    double alpha = 0.0;

    int k;
    string filename;
    int output_chars;

    if (argc == 4) 
    {
        k = stoi(argv[1]);
        filename = argv[2];
        output_chars = stoi(argv[3]);
    }
    else if (argc == 6 && string(argv[1]) == "-a") 
    {
        alpha = stod(argv[2]);

        k = stoi(argv[3]);
        filename = argv[4];
        output_chars = stoi(argv[5]);
    }
    else if (argc != 4 && argc != 6) 
    {
        cerr << "Wrong number of arguments!" << endl;

        return 1;
    }

}