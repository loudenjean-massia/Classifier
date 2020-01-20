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
#include "KnnNorme.h"
#include "ClassificationReport.h"

int main(int argc, char * argv[]) {
    
    //Argv[0] : path du fichier
    //Argv[1] : fichier d'apprentissage
    //Argv[2] : fichier de test
    //Argv[3] : k nmbre de voisin que l'on fait voter pour la prédiction d'étiquettes

    KnnNorme knnNorme;
    Data test;
    vector<int> resultTag;
    vector<int> realTag;
    int testSize;
    ClassificationReport cr;
    vector<vector<int> > matrix;
    
    resultTag = knnNorme.similarity(stoi(argv[3]), argv[1], argv[2]);
    
    test.load(argv[2]);
    
    testSize = test.getNbSamples();
    
    Sample *sampleVerif[testSize];
    for(int i = 0; i < testSize; i++)
    {
        sampleVerif[i] = new Sample();
        sampleVerif[i]->setFeatureVector(test, i);
        
        sampleVerif[i]->tag(test, i);
        
        realTag.push_back(sampleVerif[i]->getTag());
    }
    
    for(int i = 0; i < resultTag.size(); i++)
    {
        cout << "Le chiffre n°" << i << " est : " << resultTag[i] << endl;
        cout << "   (Le vrai tag est : " << sampleVerif[i]->getTag() << ")" << endl << endl;
    }

    cout << "Le pourcentage de bonnes réponses est : " << cr.computePercentage(realTag, resultTag) << " %" << endl;
    
    cout << endl << "Voici la matrice de confusion : " << endl << endl << endl;    
    
    matrix = cr.confusionMatrix(realTag, resultTag);
    cr.displayMatrix(matrix);
    
    return 0;
}
