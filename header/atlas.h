#ifndef DEF_ATLAS

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#define DEF_ATLAS
using namespace std;

using namespace cv;

class atlas{
    protected:
		int hauteur_gene;///hauteur de l'image d'origine
		int largeur_gene;///largeur de l'image d'origine (entree)
		int nb_lignes;//nombre de ligne de l atlas (entree)
		vector <Rect> boundings;///les rectangles d'origine (entree)
		vector <int> ligne_proche;///pour chaque rectangle, la ligne à laquelle il app
		vector <Rect> boundings_sortie;///sortie avec les carrers qui correspondent aux uv
        vector <string> nom_rect;
        vector <int>nb_image;
        float average_width;
        int cpt_image=0;

	public:
        atlas(int ,int ,int );
        string get_text();
        atlas();
        virtual void add_image(vector <Rect> );
        void set_nom(string ,int );
        string get_nom(int );
		~atlas();
		vector <Rect> Get();
};
#endif
