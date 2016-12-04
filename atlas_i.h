#ifndef ATLAS_I_H
#define ATLAS_I_H
#include "atlas.h"

class atlas_i:public atlas
{
public:
    atlas_i();
    atlas_i(int,int,int );
    void add_image(vector <Rect> ) ;
};

#endif // ATLAS_I_H
