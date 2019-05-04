#include "openglwidget.h"

OpenglWidget::OpenglWidget(/*const QString & filename, */QWidget* parent) : QGLWidget(QGLFormat(QGL::HasOverlay), parent)
{
    cout << "Starting OpenglWidget::OpenglWidget(iQWidget* parent)" << endl;
    data   = new QImage(640, 480, QImage::Format_RGB32);
    gldata = QGLWidget::convertToGLFormat(*data);
    setMinimumSize(320, 240);
    setMaximumSize(1280,1024);
    resize(data->size());

    glShadeModel(GL_FLAT);
    //this->updateMapImage();
    glDisable(GL_DEPTH_TEST);
}

void OpenglWidget::CreateBuffer(int w, int h){
    //cout << "Starting OpenglWidget::CreateBuffer(int w, int h)" << endl;
    delete data;
    data   = new QImage(w, h, QImage::Format_RGB32);
    gldata = QGLWidget::convertToGLFormat(*data);
    resize(data->size());
}

#define GL_BGRA_EXT                       0x80E1
void OpenglWidget::DrawImage(FastImage *pImage){
        clef.lock();
    //cout << "Starting OpenglWidget::DrawImage(FastImage *pImage)" << endl;

    /* On compare les dimensions de l'image au cas ou... */
    if( pImage->width() != data->width() || pImage->height() != data->height() ){
        delete data;
        data   = new QImage(pImage->width(), pImage->height(), QImage::Format_RGB32);
        setMinimumHeight(pImage->height());
        setMaximumHeight(pImage->height());
        setMinimumWidth (pImage->width());
        setMaximumWidth (pImage->width());
        resize( data->size() );
        updateGeometry();
        cout << "(II) OpenglWidget::DrawImage : Adaptation au contenu (" << pImage->width() << "x" << pImage->height() << ")" << endl;
    }

    // ON RECOPIE NOS DONNEES DANS LE BUFFER OPENGL
    //pImage->FastImageFill( data->bits() );

    glLoadIdentity();
    glRasterPos2i(0, pImage->height());
    glPixelZoom(1.0, -1.0);
    glDrawPixels(pImage->width(), pImage->height(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, pImage->image);
    updateGL();

    //.this->start();
        clef.unlock();
    }

void OpenglWidget::run(){
        //clef.lock();
        //clef.unlock();
}
void OpenglWidget::paintGL()
{
    //cout << "Starting OpenglWidget::paintGL()" << endl;
    //glDrawPixels(data->width(), data->height(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, data->bits());
    //cout << "Finishing OpenglWidget::paintGL()" << endl;
}

void OpenglWidget::resizeGL(int w, int h)
{
    //cout << "(II) Starting OpenglWidget::resizeGL(" << w << "x" << h << ")" << endl;
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w,0,h,-1,1);
    glMatrixMode (GL_MODELVIEW);
}

