//
//  Knn.h
//  Classifier
//
//  Created by Lou Denjean-Massia on 12/01/2020.
//

#ifndef Knn_h
#define Knn_h

#include <stdio.h>

class Knn {
public:
    Knn();
        
protected:
    virtual float getKnn() = 0;
    virtual void similarity() = 0;
    virtual long double knnCosine() = 0;
};

#endif /* Knn_h */
