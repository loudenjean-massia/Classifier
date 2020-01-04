//
//  Sample.hpp
//  Classifier
//
//  Created by Léa Gand on 28/11/2019.
//

#ifndef Sample_hpp
#define Sample_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "Data.h"

using std::string;
using std::ifstream;

class Sample
{
private:
    
    int _tag;
    FeatureVector _features;
    
public:
    Sample();
    ~Sample();
    
    void features(Data& data);
    
    //operator[];
    //int scale();
    int tag();
    //string toString();
    void splitLine(const string &chaine, char delimiteur, vector<string> &elements);
    
    
};


#endif /* Sample_hpp */
