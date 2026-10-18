# Small Language Model

## 1. Description
In this project we built a **Small Language Model**. The program takes a text file, analyzes the $k$-gram frequencies and conditional probabilities ("learns" how to use letters and words), and generates its own text based on the statistical properties of the input data. The user can adjust the $k$-gram length, the number of output characters from the program, and the pseudocount '-$a$'.

- 'src/': Contains the source files ('main.cpp', 'reader.cpp', 'reader.h', 'generator.cpp', 'generator.h')
- 'Makefile': Describes how files depend on each other and how to build them.
- '.gitignore': Specifies intetionally untracked files (such as '*.o', '*.txt', 'slm') that Git should ignore.


## 2. How to Compile
To compile the code, open a terminal in the project root directory and run:

```
make
```

To clean the compiled object files and executables, run:
```
make clean
```

## 3. How to Use
Once compiled, run the executable ./slm using one of the following formats:

a. Standard Text Generation
```
./slm k filename.txt output_characters
```

b. Text Generation with Added Pseudocount alpha
```
./slm -a 0.01 k filename.txt output_characters