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

float ClassificationReport::computePercentage(vector<int> realTag, vector<int> resultTag)
{
    float percentage = 0;
    if (realTag.size() == resultTag.size())
    {
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
        cout << "_ok = " << _ok << ", _nok = " << _nok << endl;
        percentage = ((float)_ok / realTag.size()) * 100;
        
        return percentage;
    }
    return -1;
}

