//
//  Sample.cpp
//  Classifier
//
//  Created by Léa Gand on 28/11/2019.
//

#include "Sample.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//using namespace std;

using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::stringstream;
using std::endl;

Sample::Sample()
{
    _tag = 0;
}

Sample::~Sample()
{
    
}

void Sample::splitLine(const string &chaine, char delimiteur, vector<string> &elements){
    
    stringstream ss(chaine);
    string sousChaine;
    
    while(getline(ss,sousChaine, delimiteur)){
        elements.push_back(sousChaine);
    }
    
}

/**
    Recover only the vector
 */
void Sample::features(Data& data, int lineNb)
{
   if (lineNb < data.getNbSamples())
   {   
        vector<string> features;
        splitLine(data._data[lineNb], ' ', features);

        for(int i = 0; i < features.size(); i++)
        {
            cout << "This the feature " << i << " of the line " << lineNb << ": " << features[i] << endl;
        }
   }
   else
   {
        cout << "This sample doesn't exit" << endl;   
   }
}

int Sample::tag()
{
    return _tag;
}
