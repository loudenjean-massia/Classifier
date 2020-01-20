//
//  ClassificationReport.cpp
//  Classifier
//
//  Created by Léa Gand on 19/01/2020.
//

#include "ClassificationReport.h"
#include <fstream>
#include <iostream>
#include <string>

ClassificationReport::ClassificationReport(): _confusion(0), _nbTags(0), _nok(0), _ok(0)
{

}

void ClassificationReport::tagValidation(vector<int> realTag, vector<int> resultTag){
    
       for (int i = 0; i < realTag.size(); i++)
       {
           if(resultTag[i] == realTag[i])
           {
               _ok++;
           }
           else
           {
               _nok++;
           }
       }
}

float ClassificationReport::computePercentage(vector<int> realTag, vector<int> resultTag)
{
    if (realTag.size() == resultTag.size())
    {
        float percentage = 0;
        
        tagValidation(realTag, resultTag);
        
        cout << "_ok = " << _ok << ", _nok = " << _nok << endl;
        percentage = ((float)_ok / realTag.size()) * 100;
            
        return percentage;
    }
    return -1;
}

vector<int> ClassificationReport::confusionMatrix(vector<int> realTag, vector<int> resultTag){
    
    vector<int> _matrix;
    
    
    
    return _matrix;
}
