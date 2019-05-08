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
    src/Image/Filters/LinearFilters/redchannel.h \
    src/Image/Filters/LinearFilters/greenchannel.h \
    src/Image/Filters/LinearFilters/bluechannel.h \
    src/Image/Filters/LinearFilters/greychannel.h \
    src/Image/Filters/LinearFilters/reliablegreychannel.h \
    src/Image/Filters/OtherFilters/blur.h \
    src/Image/Filters/OtherFilters/autoadapt.h \
    src/Image/Filters/ComplexFilters/complex1.h \
    src/Image/Filters/ComplexFilters/complex3.h \
    src/Image/Filters/OtherFilters/inverse.h \
    src/Image/Filters/ConvFilters/B0.h \
    src/Image/Filters/ConvFilters/B1.h \
    src/Image/Filters/ConvFilters/B2.h \
    src/Image/Filters/ConvFilters/B3.h \
    src/Image/Filters/ConvFilters/Convfilter.h \
    src/Image/Filters/ConvFilters/M0.h \
    src/Image/Filters/ConvFilters/M1.h \
    src/Image/Filters/ConvFilters/M2.h \
    src/Image/Filters/ConvFilters/M3.h \
    src/Image/Filters/ConvFilters/M4.h \
    src/Image/Filters/ConvFilters/M5.h \
    src/Image/Filters/ConvFilters/M6.h \
    src/Image/Filters/ConvFilters/M7.h \
    src/Image/Filters/ConvFilters/M8.h \
    src/Image/Filters/ConvFilters/M9.h \
    src/Image/Filters/ComplexFilters/complex4.h \
    src/Image/Filters/ComplexFilters/complex2.h \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/cubicdownsample.h \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/downsample.h \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/downsamplingfilter.h \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/lineardownsample.h \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/cubicupsample.h \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/linearupsample.h \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/upsample.h \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/upsamplingfilter.h


SOURCES += src/playerinterface.cpp \
    src/openglwidget.cpp \
    src/main.cpp \
    src/Image/FImage.cpp \
    src/Image/CVideo.cpp \
    src/Image/Filters/filter.cpp \
    src/Image/Filters/LinearFilters/linearfilter.cpp \
    src/Image/Filters/LinearFilters/redchannel.cpp \
    src/Image/Filters/LinearFilters/greenchannel.cpp \
    src/Image/Filters/LinearFilters/bluechannel.cpp \
    src/Image/Filters/LinearFilters/greychannel.cpp \
    src/Image/Filters/LinearFilters/reliablegreychannel.cpp \
    src/Image/Filters/OtherFilters/blur.cpp \
    src/Image/Filters/OtherFilters/autoadapt.cpp \
    src/Image/Filters/ComplexFilters/complex1.cpp \
    src/Image/Filters/ComplexFilters/complex3.cpp \
    src/Image/Filters/OtherFilters/inverse.cpp \
    src/Image/Filters/ConvFilters/B0.cpp \
    src/Image/Filters/ConvFilters/B1.cpp \
    src/Image/Filters/ConvFilters/B2.cpp \
    src/Image/Filters/ConvFilters/B3.cpp \
    src/Image/Filters/ConvFilters/Convfilter.cpp \
    src/Image/Filters/ConvFilters/M0.cpp \
    src/Image/Filters/ConvFilters/M1.cpp \
    src/Image/Filters/ConvFilters/M2.cpp \
    src/Image/Filters/ConvFilters/M3.cpp \
    src/Image/Filters/ConvFilters/M4.cpp \
    src/Image/Filters/ConvFilters/M5.cpp \
    src/Image/Filters/ConvFilters/M6.cpp \
    src/Image/Filters/ConvFilters/M7.cpp \
    src/Image/Filters/ConvFilters/M8.cpp \
    src/Image/Filters/ConvFilters/M9.cpp \
    src/Image/Filters/ComplexFilters/complex4.cpp \
    src/Image/Filters/ComplexFilters/complex2.cpp \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/cubicdownsample.cpp \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/downsample.cpp \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/downsamplingfilter.cpp \
    src/Image/Filters/SamplingFilters/DownSamplingFilters/lineardownsample.cpp \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/cubicupsample.cpp \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/linearupsample.cpp \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/upsample.cpp \
    src/Image/Filters/SamplingFilters/UpSamplingFilters/upsamplingfilter.cpp



RESOURCES +=
FORMS +=
