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

using namespace std;

int main(int argc, char * argv[]) {
    
    //Argv[0] : path du fichier
    //Argv[1] : fichier d'apprentissage
    //Argv[2] : fichier de test
    //Argv[3] : k nmbre de voisin que l'on fait voter pour la prédiction d'étiquettes
    
    //le nom du fichier doit être passé en paramètre de argv[1]
    //Formation k-nn : voir onenote

        
    Data d;
    

    d.load(argv[1]); //Recovers a data file from the user terminal

    d.getNbSamples();

   
    return 0;
}
