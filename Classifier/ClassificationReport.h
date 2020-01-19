//
//  ClassificationReport.hpp
//  Classifier
//
//  Created by Léa Gand on 19/01/2020.
//

#ifndef ClassificationReport_h
#define ClassificationReport_h

#include <stdio.h>

using namespace std;

class ClassificationReport{
    
public:
    
    ClassificationReport();
    int computePercentage();
    
    
private:
    
    int _confusion;
    int _nbTags;
    int _nok;
    int _ok;
    
    
  
    
};


#endif /* ClassificationReport_h */
