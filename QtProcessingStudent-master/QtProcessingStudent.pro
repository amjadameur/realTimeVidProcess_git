TEMPLATE = app
TARGET = QtProcessing

QMAKE_CXXFLAGS= -O2 \
       -march=native -mtune=native -pipe -fomit-frame-pointer \
       -fprefetch-loop-arrays -I/opt/local/include

LIBS += -lz -lm -L/opt/local/lib -lopencv_contrib -lopencv_core \
        -lopencv_features2d -lopencv_flann -lopencv_highgui \
        -lopencv_imgproc -lopencv_legacy -lopencv_ml  \
        -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres \
        -lopencv_ts -lopencv_video -lopencv_videostab -I/opt/local/lib

QT       += core gui opengl network

HEADERS += src/playerinterface.h \
    src/openglwidget.h \
    src/Image/FImage.h \
    src/Image/CVideo.h \
    src/Image/Filters/filter.h \
    src/Image/Filters/LinearFilters/linearfilter.h \
    src/Image/Filters/SamplingFilters/samplingfilter.h \
    src/Image/Filters/LinearFilters/redchannel.h \
    src/Image/Filters/LinearFilters/greenchannel.h \
    src/Image/Filters/LinearFilters/bluechannel.h \
    src/Image/Filters/LinearFilters/greychannel.h \
    src/Image/Filters/LinearFilters/reliablegreychannel.h \
    src/Image/Filters/SamplingFilters/downsample.h \
    src/Image/Filters/SamplingFilters/lineardownsample.h \
    src/Image/Filters/SamplingFilters/cubicdownsample.h \
    src/Image/Filters/SamplingFilters/upsample.h \
    src/Image/Filters/SamplingFilters/linearupsample.h \
    src/Image/Filters/SamplingFilters/cubicupsample.h \
    src/Image/Filters/OtherFilters/blur.h \
    src/Image/Filters/OtherFilters/autoadapt.h \
    src/Image/Filters/ComplexFiltes/doublecubicdownsample.h \
    src/Image/Filters/ComplexFiltes/blurlinearupsample.h \
    src/Image/Filters/defines.h \
    src/Image/Filters/OtherFilters/inverse.h

SOURCES += src/playerinterface.cpp \
    src/openglwidget.cpp \
    src/main.cpp \
    src/Image/FImage.cpp \
    src/Image/CVideo.cpp \
    src/Image/Filters/filter.cpp \
    src/Image/Filters/LinearFilters/linearfilter.cpp \
    src/Image/Filters/SamplingFilters/samplingfilter.cpp \
    src/Image/Filters/LinearFilters/redchannel.cpp \
    src/Image/Filters/LinearFilters/greenchannel.cpp \
    src/Image/Filters/LinearFilters/bluechannel.cpp \
    src/Image/Filters/LinearFilters/greychannel.cpp \
    src/Image/Filters/LinearFilters/reliablegreychannel.cpp \
    src/Image/Filters/SamplingFilters/downsample.cpp \
    src/Image/Filters/SamplingFilters/lineardownsample.cpp \
    src/Image/Filters/SamplingFilters/cubicdownsample.cpp \
    src/Image/Filters/SamplingFilters/upsample.cpp \
    src/Image/Filters/SamplingFilters/linearupsample.cpp \
    src/Image/Filters/SamplingFilters/cubicupsample.cpp \
    src/Image/Filters/OtherFilters/blur.cpp \
    src/Image/Filters/OtherFilters/autoadapt.cpp \
    src/Image/Filters/ComplexFiltes/doublecubicdownsample.cpp \
    src/Image/Filters/ComplexFiltes/blurlinearupsample.cpp \
    src/Image/Filters/OtherFilters/inverse.cpp
RESOURCES +=
FORMS +=
