#include "atlas_i.h"
#include <iostream>
#include <cmath>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
atlas_i::atlas_i()
{

}
atlas_i::atlas_i(int a,int b,int c):atlas(a,b,c)
{

}


void atlas_i::add_image(vector <Rect> bb){
    cpt_image+=1;
    vector<Rect> boundings;
    cout<<"ok";
    ///recherche les rectangles imbriqués pour les eliminer
    bool b=true;
    //Rect *a;
    for(int it=1 ; it < bb.size(); it++ ) {
        b=true;
        for(int it2=1 ; it2 < bb.size(); it2++ ) {

            if(((bb[it2] & bb[it])==bb[it])&it!=it2){
                b=false;
            }
        }
        if(b){cout<<"ok";
            boundings.push_back(bb[it]);
        }
    }
    boundings_sortie=boundings;


    ///pour chaque rect on baisse y
        for(int i=0;i<boundings.size();i++){
            nom_rect.push_back("\\");
            nb_image.push_back(cpt_image);
        }
}
