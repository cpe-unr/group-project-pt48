audioprocessor: main.cpp Wav.o normalization.o echo.o noisegate.o CSVWriter.o waveManager.so
	g++ -std=c++11 main.cpp Wav.o normalization.o echo.o noisegate.o CSVWriter.o -o audioprocessor 

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

waveManager.so: Wav.o
	ar suvr waveManager.so Wav.o 

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c -std=c++11 noisegate.cpp

CSVWriter.o: CSVWriter.cpp CSVWriter.h
	g++ -c -std=c++11 CSVWriter.cpp

clean:
	rm *.o

