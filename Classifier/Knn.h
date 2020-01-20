//
//  Knn.h
//  Classifier
//
//  Created by Lou Denjean-Massia on 12/01/2020.
//

#ifndef Knn_h
#define Knn_h

#include <stdio.h>
#include <vector>
#include <string>
#include "Sample.h"
#include "Data.h"
#include "FeatureVector.h"

using namespace std;

class Knn {

public:
    virtual vector<int> similarity(int k, string apprFile, string testFile) = 0;
    virtual int getTag(vector<int> tag) = 0;
};

#endif /* Knn_h */
