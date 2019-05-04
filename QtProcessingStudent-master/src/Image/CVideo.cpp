/*
 * CVideo.cpp
 *
 *  Created on: 19 janv. 2009
 *      Author: legal
 */

#include "CVideo.h"

CVideo::CVideo(const char *filename) {
        fileOpen   = false;
        fileFinish = false;
        frameCnt   = 0;

        capture = cvCreateFileCapture( filename );
        if( !capture ){
                cout << "Erreur a l'ouverture du fichier video..." << endl;
                exit(0);
        }

        frame = cvQueryFrame( capture );
        if( !frame ){
                cout << "Erreur a l'ouverture du fichier video..." << endl;
                exit(0);
        }
        printf("+ Image characteristics:\n");
        printf("  -> nSize        = %d\n", frame->nSize);
        printf("  -> nChannels    = %d\n", frame->nChannels);
        printf("  -> alphaChannel = %d\n", frame->alphaChannel);
        printf("  -> depth        = %d\n", frame->depth);
        printf("  -> colorModel   = %s\n", frame->colorModel);
        printf("  -> channelSeq   = %s\n", frame->channelSeq);
        printf("  -> dataOrder    = %d\n", frame->dataOrder);
        printf("  -> width        = %d\n", frame->width);
        printf("  -> height       = %d\n", frame->height);
}


CVideo::~CVideo() {
    cvReleaseCapture( &capture );
}


int  CVideo::frameNumber() {
    return 0;
}


bool CVideo::isFinished() {
    return fileFinish;
}


bool CVideo::close() {
    return 0;
}


bool CVideo::open(const char *filename) {
printf(" ### THIS IS A PROBLEM ###\n");
        capture = cvCreateFileCapture( filename );
        if( !capture ){
                cout << "Erreur a l'ouverture du fichier video..." << endl;
                exit(0);
        }

        frame   = cvQueryFrame( capture );
        if( !frame ){
                cout << "Erreur a l'ouverture du fichier video..." << endl;
                exit(0);
        }
        printf("+ Image characteristics:\n");
        printf("  -> nSize        = %d\n", frame->nSize);
        printf("  -> nChannels    = %d\n", frame->nChannels);
        printf("  -> alphaChannel = %d\n", frame->alphaChannel);
        printf("  -> depth        = %d\n", frame->depth);
        printf("  -> colorModel   = %s\n", frame->colorModel);
        printf("  -> channelSeq   = %s\n", frame->channelSeq);
        printf("  -> dataOrder    = %d\n", frame->dataOrder);
        printf("  -> width        = %d\n", frame->width);
        printf("  -> height       = %d\n", frame->height);

        videoH = frame->height;
        videoW = frame->width;
        fileFinish = false;


        printf("##### FIRST PROCESSING RUN #####\n");

        run();

        return true;
}


bool CVideo::isOpen() {
        return true;
}


void CVideo::run() {
    mutex.lock();
    while( !decodeNextFrame() ){
        if( isFinished() == true ){
            printf("=> OUPS FILE FINISHED...\n");
            mutex.unlock();
                return;
        }
    }
    mutex.unlock();
}


bool CVideo::decodeNextFrame() {
    frame = cvQueryFrame( capture );
    if( !frame ){
        printf("=> Frame extration wrong => file finished...\n");
        fileFinish = true;
        return false;
    }
    return true;
}


void CVideo::jumpFrame(int count) {
    while( count-- )
        decodeNextFrame();
}

int CVideo::getVideoWidth(){
    return videoW;
}

int CVideo::getVideoHeight(){
    return videoH;
}

FastImage* CVideo::getNextVideoFrame(){
//    cout << "(II) CVideo::getNextVideoFrame()..." << endl;
    FastImage* img = new FastImage(videoH, videoW);
    getNextVideoFrame( img );
    return img;
}

void CVideo::getNextVideoFrame( FastImage* buffer ){
//    cout << "(II) CVideo::getNextVideoFrame( FastImage* buffer )..." << endl;
    mutex.lock();
    // SYNCRONISATION DU MOTEUR D'EXTRACTION...
    mutex.unlock();

    if( isFinished() == true ){
        cout << "(EE) The video file reading is finish..." << endl;
        return;
    }

//    frame = cvQueryFrame( capture ); // POUR TESTER
    buffer->resize(frame->height, frame->width);
    buffer->FastImageFill( frame );
/*
    cvNamedWindow  ( "Video", CV_WINDOW_AUTOSIZE );
    cvNamedWindow  ( "Video",      1 );
    cvShowImage    ( "Macrobloc view", frame );
    cvWaitKey(500);

    cvDestroyWindow( "Video" );
*/
    start();
}
