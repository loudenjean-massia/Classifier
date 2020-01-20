//
//  Data.hpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#ifndef Data_h
#define Data_h

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class Data
{
public:
    
    Data();
    
    //void add();
    void load(string filename); //recovers test file datas
    int getNbSamples();
        
private:
    vector<string> _data;
    int _nbFeatures;
    int _nbSamples;
    char *fileName;
    
    friend class Sample;
    friend class FeatureVector;
};
#endif /* Data_h */
