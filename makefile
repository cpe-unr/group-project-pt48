<<<<<<< HEAD
audioprocessor: main.cpp Wav.o normalization.o echo.o noisegate.o CSVWriter.o waveManager.so
	g++ -std=c++11 main.cpp Wav.o normalization.o echo.o noisegate.o CSVWriter.o -o audioprocessor 
=======
audioprocessor: Wav.o normalization.o main.cpp
	g++ -std=c++11 -o audioprocessor Wav.o normalization.o main.cpp

main.o: main.cpp
	g++ -c -std=c++11 main.cpp
>>>>>>> a5073a72968c2d579995224a10d095642f4afa08

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

waveManager.so: Wav.o
	ar suvr waveManager.so Wav.o 

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

<<<<<<< HEAD
echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c -std=c++11 noisegate.cpp

CSVWriter.o: CSVWriter.cpp CSVWriter.h
	g++ -c -std=c++11 CSVWriter.cpp
=======
csvfilewriter.o: csvfilewriter.cpp csvfilewriter.h
	g++ -c -std=c++11 csvfilewriter.cpp

wavlibrary: main,o mylib.o
	g++ -o app mulib.o main.o


>>>>>>> a5073a72968c2d579995224a10d095642f4afa08

clean:
	rm *.o

