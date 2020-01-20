//
//  KnnNorme.hpp
//  Classifier
//
//  Created by Lou Denjean-Massia on 20/01/2020.
//

#ifndef KnnNorme_h
#define KnnNorme_h

#include "Knn.h"

class KnnNorme : public Knn {

public:
    KnnNorme();
    
    vector<int> similarity(int k, string apprFile, string testFile);
    int getTag(vector<int> tag);
    
    void norme(FeatureVector featureA, FeatureVector featureB);
    vector<float> getMins(vector<float> min, vector<long double> norme);
    
private:
    long double _norme;
    Data _appr;
    Data _test;
};

#endif /* KnnNorme_h */
