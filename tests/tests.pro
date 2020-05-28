include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES += main.cpp \
    ../app/save.cpp \
    ../app/load.cpp \
    ../app/showreveven.cpp \
    ../app/set_cursor.cpp \
    ../app/create_text.cpp \
    ../app/process_forward.cpp \
    ../app/process_backward.cpp \
    ../app/remove_all.cpp \
    ../app/append_line.cpp \
    ../app/m.cpp \
    ../app/move_next_line_begin.cpp \
    ../app/add_line_after.cpp

HEADERS += \
    ../app/common.h \
    ../app/text.h \
    ../app/_text.h \
    save.h \
    showreveven.h \
    m.h \
    move_next_line_begin.h \
    p.h

INCLUDEPATH += ../app
 
