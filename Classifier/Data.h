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

using std::string;
using std::ifstream;
using std::vector;

class Data
{
public:
    
    Data();
    ~Data();
    
    void add();
    void load(char *fileName); //recovers test file datas
    //void operator[]();
    //void scale(); //permet de ramener chacune des variables entre 0 et 1. on regarde le max, le min, on recale vers 0 et on divise par le max
    //string toString();

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
