QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fftreal/fftreal_wrapper.cpp \
    fftreal/stopwatch/ClockCycleCounter.cpp \
    fftreal/stopwatch/StopWatch.cpp \
    frequencyspectrum.cpp \
    main.cpp \
    mainwindow.cpp \
    spectrograph.cpp \
    tonegenerator_dialog.cpp \
    utils.cpp \
    waveform.cpp

HEADERS += \
    fftreal/Array.h \
    fftreal/Array.hpp \
    fftreal/DynArray.h \
    fftreal/DynArray.hpp \
    fftreal/FFTReal.h \
    fftreal/FFTReal.hpp \
    fftreal/FFTRealFixLen.h \
    fftreal/FFTRealFixLen.hpp \
    fftreal/FFTRealFixLenParam.h \
    fftreal/FFTRealPassDirect.h \
    fftreal/FFTRealPassDirect.hpp \
    fftreal/FFTRealPassInverse.h \
    fftreal/FFTRealPassInverse.hpp \
    fftreal/FFTRealSelect.h \
    fftreal/FFTRealSelect.hpp \
    fftreal/FFTRealUseTrigo.h \
    fftreal/FFTRealUseTrigo.hpp \
    fftreal/OscSinCos.h \
    fftreal/OscSinCos.hpp \
    fftreal/def.h \
    fftreal/fftreal_wrapper.h \
    fftreal/stopwatch/ClockCycleCounter.h \
    fftreal/stopwatch/ClockCycleCounter.hpp \
    fftreal/stopwatch/Int64.h \
    fftreal/stopwatch/StopWatch.h \
    fftreal/stopwatch/StopWatch.hpp \
    fftreal/stopwatch/def.h \
    fftreal/stopwatch/fnc.h \
    fftreal/stopwatch/fnc.hpp \
    frequencyspectrum.h \
    mainwindow.h \
    spectrograph.h \
    tonegenerator_dialog.h \
    utils.h \
    waveform.h

FORMS += \
    mainwindow.ui \
    tonegenerator_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    fftreal/fftreal.pro \
    fftreal/fftreal.pro

DISTFILES += \
    fftreal/FFTReal.dsp \
    fftreal/bwins/fftrealu.def \
    fftreal/eabi/fftrealu.def \
    fftreal/fftreal.pas \
    fftreal/license.txt \
    fftreal/readme.txt \
    fftreal/testapp.dpr
