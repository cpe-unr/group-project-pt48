audioprocessor: Wav.o normalization.o main.cpp
	g++ -std=c++11 -o audioprocessor Wav.o normalization.o main.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

Wav.o: Wav.cpp Wav.h 
	g++ -c -std=c++11 Wav.cpp 

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

csvfilewriter.o: csvfilewriter.cpp csvfilewriter.h
	g++ -c -std=c++11 csvfilewriter.cpp

wavlibrary: main,o mylib.o
	g++ -o app mulib.o main.o



clean:
	rm *.o

