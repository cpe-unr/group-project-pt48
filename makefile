audioprocessor: main.cpp Wav.o
	g++ -std=c++11 main.cpp Wav.o -o audioprocessor 

Wav.o: Wav.cpp Wav.h 
	g++ -c -std=c++11 Wav.cpp 

clean:
	rm *.o