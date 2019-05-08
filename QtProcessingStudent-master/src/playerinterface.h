#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QProcess>
#include <QVBoxLayout>
#include <QWidget>
#include <QSizePolicy>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QCloseEvent>
#include <QTimer>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QScrollArea>
#include <QShortcut>
#include <QGroupBox>
#include <QLabel>
#include <unistd.h>


#include "./Image/CVideo.h"
#include "openglwidget.h"

// Include filters
#include "./Image/Filters/filter.h"

// Linear filters
#include "./Image/Filters/LinearFilters/redchannel.h"
#include "./Image/Filters/LinearFilters/greenchannel.h"
#include "./Image/Filters/LinearFilters/bluechannel.h"
#include "./Image/Filters/LinearFilters/greychannel.h"
#include "./Image/Filters/LinearFilters/reliablegreychannel.h"

// Sampling filters
#include "./Image/Filters/SamplingFilters/downsample.h"
#include "./Image/Filters/SamplingFilters/lineardownsample.h"
#include "./Image/Filters/SamplingFilters/cubicdownsample.h"
#include "./Image/Filters/SamplingFilters/upsample.h"
#include "./Image/Filters/SamplingFilters/linearupsample.h"
#include "./Image/Filters/SamplingFilters/cubicupsample.h"

// Other Filters
#include "./Image/Filters/OtherFilters/blur.h"
#include "./Image/Filters/OtherFilters/autoadapt.h"
#include "./Image/Filters/OtherFilters/inverse.h"

// Conv Filters
#include "./Image/Filters/ConvFilters/Convfilter.h"
#include "./Image/Filters/ConvFilters/B0.h"
#include "./Image/Filters/ConvFilters/B1.h"
#include "./Image/Filters/ConvFilters/B2.h"
#include "./Image/Filters/ConvFilters/B3.h"
#include "./Image/Filters/ConvFilters/M0.h"
#include "./Image/Filters/ConvFilters/M1.h"
#include "./Image/Filters/ConvFilters/M2.h"
#include "./Image/Filters/ConvFilters/M3.h"
#include "./Image/Filters/ConvFilters/M4.h"
#include "./Image/Filters/ConvFilters/M5.h"
#include "./Image/Filters/ConvFilters/M6.h"
#include "./Image/Filters/ConvFilters/M7.h"
#include "./Image/Filters/ConvFilters/M8.h"
#include "./Image/Filters/ConvFilters/M9.h"

// Complex filters
#include "./Image/Filters/ComplexFilters/complex1.h"
#include "./Image/Filters/ComplexFilters/complex2.h"
#include "./Image/Filters/ComplexFilters/complex3.h"
#include "./Image/Filters/ComplexFilters/complex4.h"

#define POSITION_RESOLUTION 10000

#define  RED                   1
#define  GREEN                 2
#define  BLUE                  3
#define  GREY                  4
#define  RELIABLEGREY          5
#define  DWSAMPLE              6
#define  LINEARDWSAMPLE        7
#define  CUBICDWSAMPLE         8
#define  UPSAMPLE              9
#define  LINEARUPSAMPLE       10
#define  CUBICUPSAMPLE        11
#define  BLUR                 12
#define  AUTOADAPT            13
#define  INVERSE              14

#define  CONVB0               15
#define  CONVB1               16
#define  CONVB2               17
#define  CONVB3               18
#define  CONVM0               19
#define  CONVM1               20
#define  CONVM2               21
#define  CONVM3               22
#define  CONVM4               23
#define  CONVM5               24
#define  CONVM6               25
#define  CONVM7               26
#define  CONVM8               27
#define  CONVM9               28

#define  C1                   29
#define  C2                   30
#define  C3                   31
#define  C4                   32

class PlayerInterface : public QWidget
{
    Q_OBJECT
    QComboBox *_listeFiltres;

    QPushButton *start;
    QPushButton *pause;
    QPushButton *nextFrame;
    QPushButton *filterFrame;

    // LABELS UTILISES DANS L'INTERFACE AFIN DE FOURNIR DES INFORMATIONS
    // SUR LES FLUX VIDEO MANIPULES
    QLabel *inWidth;
    QLabel *inHeight;
    QLabel *ouWidth;
    QLabel *ouHeight;

    // LABLES UTILISES DANS L'INTERFACE AFIN DE FOURNIR UNE MESURE DU TEMPS
    // DES DIFFERENTS TRAITEMENTS (DECODAGE, PROCESSING, AFFICHAGE)
    QLabel *dTime;
    QLabel *pTime;
    QLabel *sTime;

    ////////////////////// to be discarded
    QLabel *filter1;
    QLabel *filter2;

    vector<Filter*> filters;

    int* fifo;
    //////////////////////////////////////

    // VARIABLE UTILISEE AFIN DE MINIMISER LE NOMBRE DE MISES A JOUR DE
    // L'INTERFACE GRAPHIQUE.
    int _inWidth;
    int _inHeight;
    int _ouWidth;
    int _ouHeight;

    //
    // VARIABLE UTILISEE AFIN DE MINIMISER LE NOMBRE DE MISES A JOUR DE
    // L'INTERFACE GRAPHIQUE.
    //
    int _avgDecoding;
    int _avgProcessing;
    int _avgDrawing;

    // MUTEX POUR GERER LE TRAITEMENT DE L'INFORMATION
    bool processing;

    bool isWebCam; // GESTION DU PASSAGE FLUX VIDEO / WebCam

    OpenglWidget *_videoWidget;
    QTimer *poller;

    int decodedFrames;
    int frameAverage;
    int seconds;
    QTimer *timerFPS;

    bool _isPlaying;
    CVideo *c;

    QString fileName;

    FastImage *bufferIn;
    FastImage *bufferTmp1;
    FastImage *bufferTmp2;
    FastImage *bufferOut;


public:
    PlayerInterface();
    ~PlayerInterface();

public slots:
    //void playFile();
    void openFile(QString* name);
    //void updateInterface();
    //void changeVolume(int newVolume);

    // METHODE SERVANT A GERER LE FILTRE EN MODE PAUSE
    void changePosition(int newPosition);

    void drawNextFrame();
    void frameCounterMethod();

    void startButton();
    void switchToWebCam();

    void unlockFrameRate();

    void stepOneFrame();
    void resetFilters();
};

#endif // PLAYERINTERFACE_H
