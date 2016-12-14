#include "atlas.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;



atlas::atlas(int hg,int lg,int nbl){
		hauteur_gene=hg;
		largeur_gene=lg;
		nb_lignes=nbl;
        cpt_image=0;



			
}

void atlas::add_image(vector <Rect> bb){
    cpt_image+=1;
    //

    ///get rif of inner rectangles which are useless
    bool b=true;
    for(int it=1 ; it < bb.size(); it++ ) {
        b=true;
        for(int it2=1 ; it2 < bb.size(); it2++ ) {

            if(((bb[it2] & bb[it])==bb[it])&(it!=it2)){
                b=false;
            }
        }
        //if the rectangle is not inside another one then keep
        if(b){
            boundings.push_back(bb[it]);
            nb_image.push_back(cpt_image);
        }
    }


    ///find the lines
        vector <float> yligne;
        for(int i=0;i<nb_lignes;i++){
            yligne.push_back(i*(float)hauteur_gene/((float)nb_lignes));
            cout<<" yl "<<i <<" "<<i*(float)hauteur_gene/((float)nb_lignes)<<" ";
        }
    ///for each rectangle set the nearest line on ligne_bas
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
    ///max offset up from the line
        int max_height=0;
        for(int it=0 ; it < dist_ligne_haut.size(); it++ ) {
            if(dist_ligne_haut[it]>max_height){
                max_height=dist_ligne_haut[it];
            }

        }

    ///max offset down from the line
        float dlmin=0.0;
        for(it=0 ; it < dist_ligne_bas.size(); it++ ) {
            if(dist_ligne_bas[it]<dlmin){

                dlmin=dist_ligne_bas[it];

            }
        }


     boundings_sortie.clear();
    ///reset the coordinates of the rectangles
        float wit=0;
        for(int i=0;i<boundings.size();i++){
            boundings_sortie.push_back(Rect(boundings[i].x ,  boundings[i].y+dist_ligne_haut[i]-max_height , boundings[i].width ,max_height+abs(dlmin)));
            nom_rect.push_back("\\");

        }

    ///find the average width
        for(int i=0;i<boundings_sortie.size();i++){
           wit+=boundings_sortie[i].width;
        }
        average_width=wit/((float)boundings_sortie.size());
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


int atlas::Get_image(int index){

    return nb_image[index];

}

string atlas::get_text(){
    QString txt="";
    for(int i=0;i<boundings_sortie.size();i++){
     ///name of the char
        txt+=QString::fromStdString(nom_rect[i]);
        txt+=QString::fromStdString("\t");
     ///bottom
        txt+=QString::number((float)(boundings_sortie[i].y+boundings_sortie[i].height)/((float)hauteur_gene));
        txt+=QString::fromStdString("\t");
     ///up
        txt+=QString::number(((float)boundings_sortie[i].y)/((float)largeur_gene));
        txt+=QString::fromStdString("\t");
     ///left
        txt+=QString::number(((float)boundings_sortie[i].x)/((float)hauteur_gene));
        txt+="\t";
     ///right
        txt+=QString::number(((float)(boundings_sortie[i].x+boundings_sortie[i].width))/((float)largeur_gene));
        txt+=QString::fromStdString("\t");
    ///number of the image
        txt+=QString::number(nb_image[i]);
        txt+=QString::fromStdString("\n");
    ///relative width (width/average_width)
        txt+=QString::number((float)boundings_sortie[i].width/(float)average_width);
        txt+=QString::fromStdString("\n");


    }
    return txt.toStdString();

}

vector <Rect> atlas::Get(){
	return boundings_sortie;
}
