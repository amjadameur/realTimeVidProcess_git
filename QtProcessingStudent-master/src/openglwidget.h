#ifndef OPENGLWIDGETX_H
#define OPENGLWIDGETX_H

#include <QMutex>
#include <QThread>
#include "./Image/CVideo.h"
#include <QtOpenGL/QGLWidget>

//#include "GL/gl.h"
//#include "GL/glext.h"
//#include "GL/glu.h"

class OpenglWidget : public QGLWidget, public QThread
{
    public:
        OpenglWidget(/*const QString & filename, */QWidget* parent = 0);
        void paintGL();
        void resizeGL(int w, int h);

        void CreateBuffer(int w, int h);
        void DrawImage(FastImage *pImage);

        void run();

    protected:
        QImage *data;
        QImage gldata;
        QMutex clef;
};

#endif // OPENGLWIDGETX_H
