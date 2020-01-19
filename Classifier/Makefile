classifier: main.o Data.o Sample.o FeatureVector.o KnnCosine.o ClassificationReport.o
	g++ -o classifier main.o Data.o Sample.o FeatureVector.o KnnCosine.o ClassificationReport.o

main.o : main.cpp
	g++ -c -Wall main.cpp

Data.o : Data.cpp
	g++ -c -Wall Data.cpp

Sample.o : Sample.cpp
	g++ -c -Wall Sample.cpp

FeatureVector.o : FeatureVector.cpp
	g++ -c -Wall FeatureVector.cpp

KnnCosine.o : KnnCosine.cpp
	g++ -c -Wall KnnCosine.cpp

ClassificationReport.o : ClassificationReport.cpp
	g++ -c -Wall ClassificationReport.cpp

clean:
	rm -f *.o

mrproper : clean
	rm -f
