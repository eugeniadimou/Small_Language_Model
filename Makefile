CXX = g++
CXXFLAGS = -Wall -std=c++17



slm: src/assignment5.o src/reader.o src/generator.o
	$(CXX) $(CXXFLAGS) $^ -o $@


src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


src/assignment5.o: src/assignment5.cpp src/generator.h src/reader.h
src/generator.o: src/generator.cpp src/generator.h src/reader.h
src/reader.o: src/reader.cpp src/reader.h



.PHONY: clean
clean:
	rm -f src/*.o slm
