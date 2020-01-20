//
//  KnnCosine.h
//  Classifier
//
//  Created by Lou Denjean-Massia on 12/01/2020.
//

#ifndef KnnCosine_h
#define KnnCosine_h

#include "Knn.h"

using namespace std;

class KnnCosine : public Knn {

public:
    KnnCosine();
    
    vector<int> similarity(int k, string apprFile, string testFile);
    int getTag(vector<int> tag);
    
    void cosine(FeatureVector featureA, FeatureVector featureB);
    vector<float> getMaxs(vector<float> max, vector<long double> cosine);
    
private:
    long double _cosine;
    Data _appr;
    Data _test;

};
#endif /* KnnCosine_h */
