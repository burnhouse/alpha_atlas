#include "atlas.h"

#include <iostream>
#include <cmath>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;



atlas::atlas(int hg,int lg,int nbl){
		hauteur_gene=hg;
		largeur_gene=lg;
		nb_lignes=nbl;



			
}

void atlas::add_image(vector <Rect> bb){
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
    //boundings=bb;
    cout<<"hg"<<boundings.size();
    ///on trouve les ordonnées des lignes en float
        vector <float> yligne;
        for(int i=0;i<nb_lignes;i++){
            yligne.push_back(i*(float)hauteur_gene/((float)nb_lignes));
            cout<<" yl "<<i <<" "<<i*(float)hauteur_gene/((float)nb_lignes)<<" ";
        }
    ///pour chaque rectangle on trouve sa ligne et on met dans ligne_proche et sa distance à la ligne dans dist_ligne_bas
        int lproche;
        float dist_bas;
        float dist_haut;
        vector <float> dist_ligne_bas;
        vector <float> dist_ligne_haut;
        int it;
        for(int it=0 ; it < boundings.size(); it++ ) {
            lproche=0;
            dist_bas=hauteur_gene;
            dist_haut=0.0;
            for(int i=0;i<nb_lignes;i++){
                if(abs(yligne[i]-(boundings[it].y+boundings[it].height))<abs(dist_bas)){
                    lproche=i;
                    dist_bas=(yligne[i]-(boundings[it].y+boundings[it].height));
                    dist_haut=yligne[i]-boundings[it].y;
                }

            }
            ligne_proche.push_back(lproche);cout<<" bas rect"<<boundings[it].y+boundings[it].height<<" distance" <<dist_bas<<" "<<" ligne proche"<<lproche<<"\n";
            dist_ligne_bas.push_back(dist_bas);
            dist_ligne_haut.push_back(dist_haut);
        }
    ///on trouve le maximum des distances à la ligne haut
        int max_height=0;
        for(int it=0 ; it < dist_ligne_haut.size(); it++ ) {
            if(dist_ligne_haut[it]>max_height){
                max_height=dist_ligne_haut[it];
            }

        }
    ///on trouve le maximum des distances à la ligne bas
        vector<float>::iterator v2 = dist_ligne_bas.begin();
        float dlmin=0.0;
        for(it=0 ; it < dist_ligne_bas.size(); it++ ) {
            if(dist_ligne_bas[it]<dlmin){

                dlmin=dist_ligne_bas[it];
            }
            cout<<dist_ligne_bas[it]<<"\n";
        }
        cout <<"dlmin"<<dlmin;



    ///pour chaque rect on baisse y
        for(int i=0;i<boundings.size();i++){
            //Point pt1 =  Point(boundings[i].x, boundings[i].y+dist_ligne_bas[i]-dlmax+boundings[i].height);
            //Point pt2 =  Point(boundings[i].x+boundings[i].width, boundings[i].y+dist_ligne_bas[i]-dlmax);
            boundings_sortie.push_back(Rect(boundings[i].x ,  boundings[i].y+dist_ligne_haut[i]-max_height , boundings[i].width ,max_height+abs(dlmin)));
            nom_rect.push_back("\\");
            nb_image.push_back(cpt_image);
        }
}

atlas::atlas(){

}


atlas::~atlas(void){
	boundings.clear();
	boundings_sortie.clear();
}

void atlas::set_nom(string s,int index){
    nom_rect[index]=s;
}

string atlas::get_nom(int index){
    return nom_rect[index];

}

string atlas::get_text(){
    string txt="";
    for(int i=0;i<boundings_sortie.size();i++){
        txt+=nom_rect[i];
        txt+="\t";
        txt+=to_string((float)(boundings_sortie[i].y+boundings_sortie[i].height)/((float)hauteur_gene));
        txt+="\t";
        txt+=to_string(((float)boundings_sortie[i].y)/((float)largeur_gene));
        txt+="\t";
        txt+=to_string(((float)boundings_sortie[i].x)/((float)hauteur_gene));
        txt+="\t";
        txt+=to_string(((float)(boundings_sortie[i].x+boundings_sortie[i].width))/((float)largeur_gene));
        txt+="\t";
        txt+=to_string(nb_image[i]);
        txt+="\n";

    }
    return txt;

}

vector <Rect> atlas::Get(){
	return boundings_sortie;
}
