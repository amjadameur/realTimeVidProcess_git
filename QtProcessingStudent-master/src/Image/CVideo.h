/*
 * CVideo.h
 *
 *  Created on: 19 janv. 2009
 *      Author: legal
 */

#ifndef CVIDEO_H_
#define CVIDEO_H_

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "FImage.h"
#include <QThread>
#include <QMutex>
using namespace std;


class CVideo : public QThread {
private:
    bool fileOpen;
    bool fileFinish;

    CvCapture* capture;
    IplImage*  frame;

    int videoH;
    int videoW;

    int frameCnt;

public:
    QMutex mutex;

    CVideo(const char *filename);
    virtual ~CVideo();
    void run();
    int  frameNumber();
    bool isFinished();
    bool close();
    bool open(const char *filename);
    bool isOpen();
    bool decodeNextFrame();
    void jumpFrame(int count);
    //void copyToFastImage();

    int getVideoWidth();
    int getVideoHeight();

        FastImage* getNextVideoFrame();
        void getNextVideoFrame( FastImage* buffer );
};

#endif /* CVIDEO_H_ */
