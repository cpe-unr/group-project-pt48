audioprocessor: main.cpp Wav.o normalization.o
	g++ -std=c++11 main.cpp Wav.o normalization.o -o audioprocessor 

Wav.o: Wav.cpp Wav.h 
	g++ -c -std=c++11 Wav.cpp 

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

clean:
	rm *.o