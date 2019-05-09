#include "playerinterface.h"

#define debug false
#include "time.h"

//
// CONSTRUCTEUR DE LA CLASSE EN CHARGE DE CREER L'INTERFACE GRAPHIQUE DU PLAYER
//
PlayerInterface::PlayerInterface()
: QWidget(0, Qt::Window)
{
    //
    //	INITIALISATION DES POINTEURS SUR LES "IMAGES"
    //
    bufferIn   = NULL;
    bufferOut  = NULL;
    bufferTmp1 = NULL;
    bufferTmp2 = NULL;

    frameAverage = 0;
    seconds      = 0;

    // ON INITIALISE LES VARIABLES AFIN DE PROVOQUER UNE MISE A JOUR LORS DU
    // PREMIER AFFICHAGE DE LA VIDEO A L'ECRAN
    _inWidth  = -1;
    _inHeight = -1;
    _ouWidth  = -1;
    _ouHeight = -1;

    //
    //	CREATION DES OBJETS VISUELS (INTERFACE GRAPHIQUE)
    //
    _videoWidget   = new OpenglWidget(this);
    _listeFiltres  = new QComboBox(this);

    //
    // ON REALISE LA MISE EN FORME A L'ECRAN
    //
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *l4     = new QVBoxLayout;
    setLayout(layout);

    //
    // DECLARATION DE TOUS LES PLUGINS DE TRAITEMENT VIDEO
    //
    _listeFiltres->addItem( "Red Channel" );
    _listeFiltres->addItem( "Green Channel" );
    _listeFiltres->addItem( "Blue Channel" );
    _listeFiltres->addItem( "Grey Scale" );
    _listeFiltres->addItem( "Reliable Grey Scale" );

    _listeFiltres->addItem( "Down Sample" );
    _listeFiltres->addItem( "Linear Down Sample" );
    _listeFiltres->addItem( "Cubic Down Sample" );
    _listeFiltres->addItem( "Up Sample" );
    _listeFiltres->addItem( "Linear Up Sample" );
    _listeFiltres->addItem( "Cubic Up Sample"); 

    _listeFiltres->addItem( "Blur");
    _listeFiltres->addItem( "Auto Adapt");
    _listeFiltres->addItem( "Inverse");

    _listeFiltres->addItem("B0");
    _listeFiltres->addItem("B1");
    _listeFiltres->addItem("B2");
    _listeFiltres->addItem("B3");
    _listeFiltres->addItem("M0");
    _listeFiltres->addItem("M1");
    _listeFiltres->addItem("M2");
    _listeFiltres->addItem("M3");
    _listeFiltres->addItem("M4");
    _listeFiltres->addItem("M5");
    _listeFiltres->addItem("M6");
    _listeFiltres->addItem("M7");
    _listeFiltres->addItem("M8");
    _listeFiltres->addItem("M9");


    _listeFiltres->addItem( "Complex 1");
    _listeFiltres->addItem( "Complex 2");
    _listeFiltres->addItem( "Complex 3");
    _listeFiltres->addItem( "Complex 4");






    _isPlaying = false;

    //
    // LE MODE WEBCAM EST DESACTIVE DANS CETTE VERSION DE L'OUTIL
    //
    isWebCam         = false;


    //
    // DECLARATION ET INSTANCIATION DES BOUTTONS
    //
    start       = new QPushButton( "Stop video", this );
    nextFrame   = new QPushButton( "Next Frame", this );
    pause       = new QPushButton( "Switch to camera", this );
    filterFrame = new QPushButton( "Limit 24fps", this );

    pause->setEnabled( false );
    start->setEnabled( false );
    nextFrame->setEnabled( false );
    filterFrame->setEnabled( false );

    // ON CREE UN REGROUPEMENT POUR L'ENSEMBLE DES ELEMENTS LIES AU FILTRAGE
    QGroupBox   *g1 = new QGroupBox(tr("Filter processing"));
    QVBoxLayout *fp = new QVBoxLayout;
    fp->addWidget(_listeFiltres);
    g1->setLayout(fp);

    QGroupBox   *g2 = new QGroupBox(tr("Action commands"));
    QVBoxLayout *ac = new QVBoxLayout;
    ac->addWidget(pause);
    ac->addWidget(start);
    ac->addWidget(nextFrame);
    ac->addWidget(filterFrame);
    g2->setLayout(ac);

    QGroupBox   *g3 = new QGroupBox(tr("Input video informations"));
    QVBoxLayout *vi = new QVBoxLayout;
    inWidth  = new QLabel(tr("Video width"));
    inHeight = new QLabel(tr("Video width"));
    vi->addWidget( inWidth  );
    vi->addWidget( inHeight );
    g3->setLayout(vi);

    QGroupBox   *g4 = new QGroupBox(tr("Output video informations"));
    QVBoxLayout *pd = new QVBoxLayout;
    ouWidth  = new QLabel(tr("Video width"));
    ouHeight = new QLabel(tr("Video width"));
    pd->addWidget( ouWidth  );
    pd->addWidget( ouHeight );
    g4->setLayout(pd);

    QGroupBox   *pp = new QGroupBox(tr("Processing informations"));
    QVBoxLayout *pt = new QVBoxLayout;
    dTime  = new QLabel(tr("Video width"));
    pTime  = new QLabel(tr("Video width"));
    sTime  = new QLabel(tr("Video width"));
    pt->addWidget( dTime  );
    pt->addWidget( pTime );
    pt->addWidget( sTime );
    pp->setLayout(pt);


    ////////////////////////////////////////////////////////////////
    /// Mine :
    QGroupBox   *myWidget = new QGroupBox(tr("My Group Box"));
    QVBoxLayout *myBox = new QVBoxLayout;
    filter1  = new QLabel(tr("filter 1"));
    filter2  = new QLabel(tr("filter 2"));
    myBox->addWidget( filter1  );
    myBox->addWidget( filter2  );
    myWidget->setLayout(myBox);

    filters.push_back(new RedChannel());
    filters.push_back(new GreenChannel());
    filters.push_back(new BlueChannel());
    filters.push_back(new GreyChannel());
    filters.push_back(new ReliableGreyChannel());

    filters.push_back(new DownSample());
    filters.push_back(new LinearDownSample());
    filters.push_back(new CubicDownSample());

    filters.push_back(new UpSample());
    filters.push_back(new LinearUpSample());
    filters.push_back(new CubicUpSample());

    filters.push_back(new Blur());
    filters.push_back(new AutoAdapt());
    filters.push_back(new Inverse());

    filters.push_back(new B0());
    filters.push_back(new B1());
    filters.push_back(new B2());
    filters.push_back(new B3());
    filters.push_back(new M0());
    filters.push_back(new M1());
    filters.push_back(new M2());
    filters.push_back(new M3());
    filters.push_back(new M4());
    filters.push_back(new M5());
    filters.push_back(new M6());
    filters.push_back(new M7());
    filters.push_back(new M8());
    filters.push_back(new M9());

    filters.push_back(new C1());
    filters.push_back(new C2());
    filters.push_back(new C3((Blur*)  filters[BLUR]));
    filters.push_back(new C4());




    /////////////////////////////////////////////////////////////////

    l4->addWidget(g1);
    l4->addWidget(g2);
    l4->addWidget(g3);
    l4->addWidget(g4);
    l4->addWidget(pp);
    l4->addWidget(myWidget);

    layout->addLayout(l4);

    //
    // GESTION DE L'AFFICHAGE DE L'IMAGE
    //
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(_videoWidget);
    layout->addWidget(scrollArea);


    //
    // ON GENERE UNE INTERUPTION TOUTES LES 5MS AFIN DE LANCER LE DECODAGE D'UNE IMAGE,
    // CELA NOUS PERMET EN THEORIE DE MONTER A 200Hz
    //
    poller = new QTimer(this);
    connect(poller, SIGNAL(timeout()), this, SLOT(drawNextFrame()));
    poller->setInterval(1000/200);
    processing = false;

    //
    // ON CREE UN PROGRAMME AUTONOME DONT LE ROLE EST DE METTRE A JOUR LA BARRE
    // DES TITRES AVEC LE NOMBRE D'IMAGES TRAITEES PAR SECONDE
    //
    timerFPS = new QTimer(this);
    connect(timerFPS, SIGNAL(timeout()), this, SLOT(frameCounterMethod()));
    timerFPS->start(1000);

    decodedFrames = 0;

    //
    // ON CONNECTE LES EVENEMENTS PRODUITS PAR LES OBJETS A UN GESTIONNAIRE D'INTERRUPTION
    // LOGICIEL EN CHARGE DE LEUR TRAITEMENT (CHAQUE EVENEMENT EST TRAITE PAR UNE METHODE)
    //
    connect(poller,         SIGNAL(timeout()),       this, SLOT(updateInterface())  );
    connect(start,          SIGNAL(clicked()),       this, SLOT(startButton())      );
    connect(pause,          SIGNAL(clicked()),       this, SLOT(openFile())         );
    connect(nextFrame,      SIGNAL(clicked()),       this, SLOT(stepOneFrame())     );
    connect(filterFrame,    SIGNAL(clicked()),       this, SLOT(unlockFrameRate())  );
    connect(_listeFiltres,  SIGNAL(activated(int)),  this, SLOT(changePosition(int)));

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    updateGeometry();


    //
    // DECLARATION DES RACOURCIS CLAVIER
    //
    new QShortcut(Qt::CTRL + Qt::Key_Q, this, SLOT(close()));
    new QShortcut(Qt::Key_Space,        this, SLOT(startButton()));
    new QShortcut(Qt::Key_Escape,       this, SLOT(resetFilters()));


}


//
// DESTRUCTEUR DE L'OBJET QUI NE DEVRAIS PAS ETRE VIDE...
//
PlayerInterface::~PlayerInterface()
{
    //free(previousFrames);
    //delete bufferTmp1;
    delete bufferTmp2;
    delete bufferIn;
    delete bufferOut;

    for(int i = 0; i < NB_FILTERS; i++) {
        delete filters[i];
        filters[i] = NULL;
    }
}


void PlayerInterface::drawNextFrame()
{
    //
    // SI ON EST DEJA EN TRAIN DE TRAITER UNE IMAGE LORSQUE LE TIMER SE REVEILLE CELA SIGNIFIE
    // QUE L'ON EST A LA BOURRE DONC ON REPART POUR UN TOUR D'ATTENTE
    //
    if( processing == true ){
        cout << "OUPS we must wait a bit more because a frame is currently processed !" << endl;
        return;
    } processing = true;

    //
    // MESURE DU TEMPS...
    //
    long startC = clock();

    //
    // ON INCREMENTE LE NOMBRE D'IMAGES TRAITES
    //
    decodedFrames += 1;

    //
    // ON REGARDE SI L'ON EST EN COURS DE LECTURE DU FICHIER VIDEO, SINON ON RAFRAICHI UNQIUEMENT LE TRAITEMENT
    //
    if( _isPlaying == true ){

        //
        // CREATION DES BUFFERS TEMPORAIRES SI NECESSAIRE
        //
        if( bufferIn == NULL ){
            bufferIn  = new FastImage( 2, 2 );
            bufferOut = new FastImage( bufferIn );
           // bufferTmp1 = new FastImage( bufferIn );
            bufferTmp2 = new FastImage( bufferIn );
        }

        c->getNextVideoFrame( bufferIn );

        //
        // ON GERE LE CAS OU LA VIDEO VIENT DE SE TERMINER... ON N'A PLUS RIEN A FAIRE
        // MAINTENANT !
        //
        if( c->isFinished() == true ){
            poller->stop();
            filterFrame->setEnabled( false );
            start->setEnabled( false );
            nextFrame->setEnabled( false );
            processing = false;
            return;
        }
    }

    bufferOut->resize(bufferIn->height(), bufferIn->width());



    //
    // AFFICHAGE DU TEMPS NECESSAIRE A L'EXTRATION DE l'IMAGE
    //
    _avgDecoding   += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;

    startC = clock(); // ON RELANCE LE COMPTEUR...

   ((Blur*) filters[BLUR])->refreshPrevIm(bufferIn);

   if(chosenFilters.size() == 0){
        bufferOut->FastImageCpy(bufferIn);

   } else {
        int fitlerIdx;
        bufferTmp1 = bufferIn;

        for(unsigned int i = 0; i<chosenFilters.size(); i++) {
            fitlerIdx = chosenFilters[i];
            filters[fitlerIdx]->filter(bufferTmp1, bufferOut);
            bufferTmp1 = bufferOut;
        }

        bufferTmp1 = NULL;
   }




    //
    // ON AFFICHE LE TEMPS NECESSAIRE A LA GESTION DU FILTRAGE
    //
    _avgProcessing += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;
    startC = clock(); // ON RELANCE LE COMPTEUR...

    //
    // ON REGARDE SI L'ON DOIT REDIMENSIONNER LA ZONE VISIBLE A L'ECRAN AFIN DE S'ADAPTER
    // AU RESULTAT DES DIFFERENTS FILTAGES
    //
    QSize cSize = _videoWidget->size();
    if( cSize.height() != bufferOut->height() || cSize.width() != bufferOut->width() ){
        //cout << "On a besoin d'un redimentionnement video (" << bufferOut->width() << "x" << bufferOut->height() << ")" << endl;
        cSize.setHeight( bufferOut->height() );
        cSize.setWidth ( bufferOut->width()  );
    }

    //
    // ON ENVOIE L'IMAGE VERS L'OBJET EN CHARGE DU TRAITEMENT OPENGL...
    //
    _videoWidget->DrawImage( bufferOut );
    _avgDrawing    += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;

    //
    // ON MET A JOURS LES DONNEES ISSUES DE L'INTERFACE GRAPHIQUE
    //
    if( bufferIn->width() != _inWidth || bufferIn->height() != _inHeight){
        _inWidth  = bufferIn->width();
        _inHeight = bufferIn->height();
        inWidth ->setText( tr("Video width  : ") + QVariant(_inWidth).toString()  + tr(" pixel(s)") );
        inHeight->setText( tr("Video height : ") + QVariant(_inHeight).toString() + tr(" pixel(s)") );
    }
    if( bufferOut->width() != _ouWidth || bufferOut->height() != _ouHeight){
        _ouWidth  = bufferOut->width();
        _ouHeight = bufferOut->height();
        ouWidth ->setText( tr("Video width  : ") + QVariant(_ouWidth).toString()  + tr(" pixel(s)") );
        ouHeight->setText( tr("Video height : ") + QVariant(_ouHeight).toString() + tr(" pixel(s)") );
    }

    // LE TRAITEMENT DE L'IMAGE EST TERMINE
    processing = false;
    if(debug) cout << "#################### FIN  PlayerInterface::drawNextFrame()  ####################" << endl;;
}



void PlayerInterface::openFile(QString* name)
{

    //
    // CREATION D'UNE BOITE DE DIALOGUE POUR L'OUVERTURE DU FICHIER VIDEO
    // UNIQUEMENT LORSQUE L'UTILISATEUR N'A PAS PRECISE DE FICHIER LORS
    // DU LANCEMENT DU PROGRAMME A L'AIDE DE LA LIGNE DE COMMANDE
    //
    if( name == NULL)
        fileName = QFileDialog::getOpenFileName(this,
            tr("Video files"), "",
            tr("Video files (*.avi *.mpg *.mkv *.mov);;All Files (*)"));
    else
        fileName = *name;

    // SI PAS DE NOM DE FICHIER ALORS ON QUITTE
    if(fileName.isEmpty()) exit( 0 );

    // ON CREE UN OBJET VIDEO ET ON PREFETCH LA PREMIERE IMAGE
    c = new CVideo( fileName.toStdString().c_str() );
    c->start();

    // ON ACTIVE LES BOUTONS EN CONSEQUENCE
    start->setEnabled( true );
    nextFrame->setEnabled( true );
    filterFrame->setEnabled( true );

    // ON AFFICHE LA PREMIERE IMAGE DE LA VIDEO
    _isPlaying = true;



    drawNextFrame();




    // ON DEMARRE LE PROCESSUS DE TRAITEMENT TEMPS REEL
    poller->start();
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR CHANGE UN FILTRE DANS LA LISTE. SI LA VIDEO
// EST EN COURS DE DECODAGE ALORS ON NE FAIT RIEN, SI ELLE EST ARRETEE ALORS ON CHOISI
//
void PlayerInterface::changePosition(int newPosition)
{
    cout << "(II) Un changement de filtre a ete enregistre... (" << newPosition << ")"  << endl;
    chosenFilters.push_back(newPosition);

    /* for(int i = 0; i<NB_FILTERS; i++) {
        if (fifo[i] == 0) {
            fifo[i] = newPosition;
            filter1->setText( tr("filter 1 : ") + QVariant(fifo[0]).toString() );
            filter2->setText( tr("filter 2 : ") + QVariant(fifo[1]).toString() );
            break;
        }
    }*/
    if( _isPlaying == true ) return;
    drawNextFrame();
}


//
// METHODE INVOQUEE PAR LE PROCESSUS PERIODIQUE (1 SECONDE) ET DONT LE ROLE EST DE
// RAFRAICHIR LE NOMBRE DE FPS INDIQUE DANS LA BARRE DES TITRES
//
void PlayerInterface::frameCounterMethod(){
    int nbre      = decodedFrames;

    if( decodedFrames != 0 ){
        double v0 = ((int)(100*((double)_avgDecoding  )/((double)decodedFrames)))/100.0;
        double v1 = ((int)(100*((double)_avgProcessing)/((double)decodedFrames)))/100.0;
        double v2 = ((int)(100*((double)_avgDrawing   )/((double)decodedFrames)))/100.0;

        dTime ->setText( tr("Avg decoding   time : ") + QVariant(v0).toString()  + tr(" ms") );
        pTime ->setText( tr("Avg processing time : ") + QVariant(v1).toString()  + tr(" ms") );
        sTime ->setText( tr("Avg drawing    time : ") + QVariant(v2).toString()  + tr(" ms") );
    }

    // ON REMET A ZERO LES COMPTEURS DE PERFORMANCE...
    _avgDecoding   = 0;
    _avgProcessing = 0;
    _avgDrawing    = 0;

    frameAverage += nbre;
    seconds      += 1;
    decodedFrames = 0;
    int nAvg = ((float)(floor(((float)frameAverage/(float)seconds)*10))/10);
    this->setWindowTitle("Processing speed : " + QVariant(nbre).toString()
     + " (Average : " + QVariant(nAvg).toString() + ")" );
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE LE PASSAGE EN MODE WEBCAM. ON
// VERIFIE SI UNE WEBCAM EST DISPONIBLE, SI OUI ALORS ON L'ACTIVE...
//
void PlayerInterface::startButton(){
    if( poller->isActive() ){
        poller->stop();						// ARRET DU TIMER VIDEO
        start->setText("Start video");
        nextFrame->setEnabled( true );
    }else{
        poller->start();					// DEMARRAGE DU TIMER VIDEO
        start->setText("Stop video");
        nextFrame->setEnabled( false );
    }

    // ON MEMORISE L'ETAT D'ACTIVITE DE L'APPLICATION
    _isPlaying = poller->isActive();
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE DE BRIDER OU DEBRIDER LE FRAME
// RATE DU TRAITEMENT VIDEO.
//
void PlayerInterface::unlockFrameRate(){
    if( poller->interval() == (1000/25) ){
        filterFrame->setText("Limit to 24 fps");
        poller->setInterval( 5 );
    }else{
        filterFrame->setText("Unlock framerate");
        poller->setInterval( 1000/25 );
    }
}

//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE LE PASSAGE EN MODE WEBCAM. ON
// VERIFIE SI UNE WEBCAM EST DISPONIBLE, SI OUI ALORS ON L'ACTIVE...
//
void PlayerInterface::switchToWebCam(){
    cout << "(II) Changement du comportement (1) : " << isWebCam << endl;
    isWebCam = ! isWebCam;
    if( isWebCam )
        pause       = new QPushButton( "Switch to file", this );
    else
        pause       = new QPushButton( "Switch to camera", this );
    cout << "(II) Changement du comportement (2) : " << isWebCam << endl;
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE L'AVANCEMENT MANUEL D'UNE IMAGE
//
void PlayerInterface::stepOneFrame(){
    cout << "(II) PlayerInterface::stepOneFrame()" << endl;
    if(_isPlaying == true){
        return;
    }
    _isPlaying = true;
    drawNextFrame();
    _isPlaying = false;
    cout << "(II) FIN PlayerInterface::stepOneFrame()" << endl;
}

//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE L'AVANCEMENT MANUEL D'UNE IMAGE
//
void PlayerInterface::resetFilters(){
    _listeFiltres->setCurrentIndex(0);
}
