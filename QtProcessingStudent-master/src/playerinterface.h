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

// Complex filters
#include "./Image/Filters/ComplexFiltes/doublecubicdownsample.h"
#include "./Image/Filters/ComplexFiltes/blurlinearupsample.h"

#define POSITION_RESOLUTION 10000


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

    Filter* filters;

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
