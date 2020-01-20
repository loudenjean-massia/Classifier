//
//  ClassificationReport.hpp
//  Classifier
//
//  Created by Léa Gand on 19/01/2020.
//

#ifndef ClassificationReport_h
#define ClassificationReport_h

#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;
using std::vector;

class ClassificationReport{
    
public:
    
    ClassificationReport();
    void tagValidation(vector<int> realTag, vector<int> resultTag);
    float computePercentage(vector<int> realTag, vector<int> resultTag);
    vector<int> confusionMatrix(vector<int> realTag, vector<int> resultTag);
    
private:
    int _confusion;
    int _nbTags;
    int _nok;
    int _ok;
};


#endif /* ClassificationReport_h */
