//
//  FeatureVector.hpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#ifndef FeatureVector_h
#define FeatureVector_h

#include "Data.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

//using std::vector;
//using std::string;
//using std::ifstream;
using namespace std;

class FeatureVector
{
public:
    FeatureVector();
    ~FeatureVector();

    void vector(Data& data, int lineNb);
    void splitLine(const string &chaine, char delimiteur, std::vector<string> &elements);
    
    int getSize();
    void scale();
    void norme();

    float getNorme();
    std::vector<double> getVector();

private:
    float _norme;
    std::vector<double> _vector;
};

#endif /* FeatureVector_hpp */
