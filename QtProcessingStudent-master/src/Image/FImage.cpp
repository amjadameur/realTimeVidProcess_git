/*
 *  CImage.cpp
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>

#include "FImage.h"


FastImage::FastImage(int _hauteur, int _largeur){
    //cout << "(II) Construction d'une image FastImage::FastImage(int _hauteur, int _largeur)" << endl;
    image = NULL;
    resize(_hauteur, _largeur);
}


FastImage::FastImage(FastImage *f){
   // cout << "(II) Construction d'une image FastImage::FastImage(FastImage *f)" << endl;
    image = NULL;
    resize(f->height(), f->width());
    int size = line_width * height();
    //cout << "(II) Taille origine : " << f->width() << "x" << f->height() << endl;
    //cout << "(II) Taille destina : " << width()    << "x" << height()    << endl;
    //cout << "(II) Fin de construction d'une image FastImage::FastImage(FastImage *f)" << endl;
    memcpy((void*)image, (void*)f->image, size * sizeof(unsigned char));
    //cout << "(II) Fin de construction d'une image FastImage::FastImage(FastImage *f)" << endl;
}


FastImage::~FastImage(){
    //cout << "(II) Destruction d'une image FastImage::~FastImage()" << endl;
    _mm_free( image );
}

#define LimitMAX(a) (a>255)?255:a
#define LimitMIN(a) (a<0)?0:a
#define Limit(a)    LimitMAX(LimitMIN(a))

int FastImage::height(){
    return hauteur;
}

int FastImage::width(){
    return largeur;
}

void FastImage::resize(int _height, int _width){
    //
    // ON VERIFIE LE BESOIN DE REDIMENSIONNEMENT DE L'IMAGE
    //
    if( (_height == hauteur) && (largeur == _width)){
        return;
    }

    //cout << "(II) FastImage::resize(" << largeur << "x" << hauteur << ") => (" << _width << "x" << _height << ")" << endl;
    if( image != NULL ) _mm_free( image );
    largeur    = _width;
    hauteur    = _height;
    line_width = 4 * width();
    image = (unsigned char*)_mm_malloc ( line_width * height(), 16);
}


int FastImage::Red (int y, int x){
        if( y > hauteur || y < 0 ) return 0;
        if( x > largeur || x < 0 ) return 0;
        return image[4*x + line_width * y + 2];
}

void FastImage::Red(int y, int x, int v){
        if( y > hauteur || y < 0 ) return;
        if( x > largeur || x < 0 ) return;
        image[4*x + line_width * y + 2] = Limit(v);
}

int FastImage::Green (int y, int x){
        if( y > hauteur || y < 0 ) return 0;
        if( x > largeur || x < 0 ) return 0;
        return image[4*x + line_width * y + 1];
}

void FastImage::Green(int y, int x, int v){
        if( y > hauteur || y < 0 ) return;
        if( x > largeur || x < 0 ) return;
        image[4*x + line_width * y + 1] = Limit(v);
}

void FastImage::Blue(int y, int x, int v){
        if( y > hauteur || y < 0 ) return;
        if( x > largeur || x < 0 ) return;
        image[4*x + line_width * y] = Limit(v);
}


int FastImage::Blue (int y, int x){
        if( y > hauteur || y < 0 ) return 0;
        if( x > largeur || x < 0 ) return 0;
        return image[4*x + line_width * y];
}

int FastImage::Alpha(int y, int x){
        return image[4*x + line_width * y + 4];
}

void FastImage::Alpha(int y, int x, int v){
        if(x > width() -1 ){
      //      cout << "(EE) Alpha(int,int) X(" << x << ") is bigger than image (" << width() << "x" << height() << ")" << endl;
            exit(0);
        }
        image[4*x + line_width * y + 4] = Limit(v);
}

void FastImage::FastImageFill(IplImage* frame){
    // LORSQUE L'ON RECUPERE UNE NOUVELLE IMAGE DU FLUX VIDEO, ON REPASSE LA TAILLE DE
    // L'IMAGE A LA TAILLE ALLOUEE EN MEMOIRE.
    //cout << "(II) Appel de la methode FastImage::FastImageFill(AVFrame *pFrameRGB)" << endl;

    if( frame->nChannels == 4 ){
        int size = line_width * height();
        memcpy((void*)image, (void*)frame->imageData, size * sizeof(unsigned char));
    }else{
        int size = width() * height();
        unsigned char* p = (unsigned char*)frame->imageData;
        unsigned char* q = image;
        while( size-- ){
            *q++ = *p++;
            *q++ = *p++;
            *q++ = *p++;
            *q++ = 0;
        }
    }

    //cout << "(II) Valeur du pixel (10x10)( = B=" << Blue(10,10) << " / G=" << Green(10,10) << " / R=" << Red(10,10) << endl;
}


//
//  REMPLIE
//
void FastImage::FastImageFill(unsigned char *out){
    int size = 4 * width() * height();
                // P   => Blue
            // P+1 => Green
            // P+2 => Red
    /*unsigned char *in = image;
    while( size-- ){
        int r = *in++;
        int g = *in++;
        int b = *in++;
        int a = *in++;
        *out++ = r; // RED
        *out++ = 0; // GREEN
        *out++ = 0; // BLUE
        *out++ = 0; // ALPHA
    }*/
    memcpy((void*)out, (void*)image, size * sizeof(unsigned char));
    //cout << "(II) Valeur du pixel (10x10)( = B=" << Blue(10,10) << " / G=" << Green(10,10) << " / R=" << Red(10,10) << endl;
}


void FastImage::FastCopyTo( FastImage *f ){
    //cout << "(II) Appel de la methode FastImage::FastCopyTo( FastImage *f )" << endl;
    int size = line_width * height();
    //for(int y=0; y<f->height(); y++){
    //    for(int x=0; x<f->width(); x++){
    //        RGB(y, x, f->Red(y,x), f->Green(y,x), f->Blue(y,x));
    //        // P   => Blue
    //        // P+1 => Green
    //        // P+2 => Red
    //    }
    //}
    memcpy((void*)image, (void*)f->image, size * sizeof(unsigned char));
    //cout << "(II) Valeur du pixel (10x10)( = B=" << Blue(10,10) << " / G=" << Green(10,10) << " / R=" << Red(10,10) << endl;


}


void FastImage::RGB(int y, int x, int r, int g, int b){
        Red  (y,x,r);
        Green(y,x,g);
        Blue (y,x,b);
}



void FastImage::FastImageCpy(FastImage *f){
    if (!((f->height() == hauteur) && (f->width() == largeur))){
        if( image != NULL ) _mm_free( image );

        largeur    = f->width();
        hauteur    = f->height();
        line_width = 4 * width();

        image = (unsigned char*)_mm_malloc ( line_width * height(), 16);
    }

    int size = line_width * height();

    memcpy((void*)image, (void*)f->image, size * sizeof(unsigned char));
}


void FastImage::FastImagePointer(FastImage *src) {
    largeur    = src->width();
    hauteur    = src->height();
    line_width = 4 * width();

    _mm_free( image );
    image = src->image;
}
