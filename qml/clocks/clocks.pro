TEMPLATE     = app

QT          += qml quick

SOURCES     += main.cpp \
    datasource.cpp \
    datasource.cpp
RESOURCES   += clocks.qrc

target.path  = $$[QT_INSTALL_EXAMPLES]/quick/demos/clocks
INSTALLS    += target

OTHER_FILES  += \
                clocks.qml \
                content/Clock.qml \
                content/*.png

HEADERS += \
    datasource.h \
    datasource.h
