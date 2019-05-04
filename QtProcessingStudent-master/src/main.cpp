#include "playerinterface.h"

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#include <QString>

#include "./Image/FImage.h"
#include "./Image/CVideo.h"
#include "./Image/Filters/filter.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    cout << "(II) int main(int argc,char **argv) :: Creation de l'interface graphique" << endl;
    PlayerInterface p;
    cout << "(II) int main(int argc,char **argv)  :: redimensionnement de l'interface graphique" << endl;
    p.resize(640, 480);

    QString *name = NULL;
    if(argc == 2){
        name = new QString( argv[1] );
        cout << "(II) int main(int argc,char **argv)  :: parametre trouve (" << argv[1] << ")" << endl;
    }

    cout << "(II) int main(int argc,char **argv)  :: ouverture d'un fichier video" << endl;
    p.openFile( name );

    cout << "(II) int main(int argc,char **argv)  :: affichage de l'interface graphique" << endl;
    p.show();


    return app.exec();

}
