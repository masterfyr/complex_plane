CONFIG += console
#CONFIG+=staticlib

HEADERS += \
    comp.h \
    test.h \
    impl_graph.h \
    impl_console.h \
    comp_set.h

SOURCES += \
    main.cpp

#adding additional lib
#LIBS += -L$$PWD/ -ldiscpp

OTHER_FILES += \
    note.txt

