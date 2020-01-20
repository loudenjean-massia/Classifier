//
//  Sample.hpp
//  Classifier
//
//  Created by Léa Gand on 28/11/2019.
//

#ifndef Sample_hpp
#define Sample_hpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Data.h"
#include "FeatureVector.h"

using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::stringstream;
using std::endl;

class Sample
{
public:
    Sample();
    
    void tag(Data& data, int lineNb);
    void splitLine(const string &chaine, char delimiteur, vector<string> &elements);
    void setFeatureVector(Data data, int lineNb);
    void setTag(int tag);
    
    //getters
    int getTag();
    FeatureVector getFeatures();
    
private:
    int _tag;
    FeatureVector _features;
    
    friend class FeatureVector;
};
#endif /* Sample_hpp */
