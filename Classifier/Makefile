classifier: main.o Data.o Sample.o FeatureVector.o KnnCosine.o
	gcc -o classifier main.o Data.o Sample.o FeatureVector.o KnnCosine.o

main.o : main.cpp
	gcc -c -Wall main.cpp

Data.o : Data.cpp
	gcc -c -Wall Data.cpp

Sample.o : Sample.cpp
	gcc -c -Wall Sample.cpp

FeatureVector.o : FeatureVector.cpp
	gcc -c -Wall FeatureVector.cpp

KnnCosine.o : KnnCosine.cpp
	gcc -c -Wall KnnCosine.cpp

clean:
	rm -f *.o

mrproper : clean
	rm -f
