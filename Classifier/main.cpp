//
//  main.cpp
//  Classifier
//
//  Created by Léa Gand on 17/11/2019.
//

#include <fstream>
#include <iostream>
#include "Data.h"
#include "FeatureVector.h"
#include "Sample.h"
#include "Knn.h"
#include "KnnCosine.h"
#include "ClassificationReport.h"

//using namespace std;

int main(int argc, char * argv[]) {
    
    //Argv[0] : path du fichier
    //Argv[1] : fichier d'apprentissage
    //Argv[2] : fichier de test
    //Argv[3] : k nmbre de voisin que l'on fait voter pour la prédiction d'étiquettes
    
    //le nom du fichier doit être passé en paramètre de argv[1]
    //Formation k-nn : voir onenote

    KnnCosine knnCosine;
    Data test;
    vector<int> resultTag;
    vector<int> realTag;
    int testSize;
    ClassificationReport cr;
    
    resultTag = knnCosine.similarity(stoi(argv[3]), argv[1], argv[2]);
    
    test.load(argv[2]);
    
    testSize = test.getNbSamples();
    
    Sample *sampleVerif[testSize];
    for(int i = 0; i < testSize; i++)
    {
        sampleVerif[i] = new Sample();
        sampleVerif[i]->setFeatureVector(test, i);
        
        sampleVerif[i]->tag(test, i);
    }
    for (int i = 0; i < testSize; i++)
    {
        realTag.push_back(sampleVerif[i]->getTag());
    }
    
    for(int i = 0; i < resultTag.size(); i++)
    {
        cout << "Le chiffre n°" << i << " est : " << resultTag[i] << endl;
        cout << "Le vrai tag de " << i << " est : " << sampleVerif[i]->getTag() << endl;
    }

    cout << "le pourcentage de bonnes réponses est :" << cr.computePercentage(realTag, resultTag) << endl;
    
    return 0;
}
