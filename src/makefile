#CACHE SIM MADE BY APOORV KUMAR
#PLEASE DO NOT ALTER THE MAKEFILE
#UNTIL VERY NECESSARY.

WRKDIR = `pwd`


AS = as
CC = gcc
CPP = g++
F77 = f77
F9X = gfortran
LD = g++
AR = ar
RANLIB = ranlib
WINDRES = windres

INC =
CFLAGS = -Wall -fexceptions
RESINC = 
RCFLAGS = 
LIBDIR =
LIB =
LDFLAGS =

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/cache_sim

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/cache_sim

OBJ_DEBUG = $(OBJDIR_DEBUG)/cache.o $(OBJDIR_DEBUG)/cache_line.o $(OBJDIR_DEBUG)/cache_set.o $(OBJDIR_DEBUG)/config.o $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/trace.o
OBJ_RELEASE = $(OBJDIR_RELEASE)/cache.o $(OBJDIR_RELEASE)/cache_line.o $(OBJDIR_RELEASE)/cache_set.o $(OBJDIR_RELEASE)/config.o  $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/trace.o

all: debug release

clean: clean_debug clean_release

debug: $(OUT_DEBUG)

$(OUT_DEBUG): $(OBJ_DEBUG) $(DEP_DEBUG)
	test -d bin/Debug || mkdir -p bin/Debug
	$(LD) $(LDFLAGS_DEBUG) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/cache.o: cache.cpp
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	$(CPP) $(CFLAGS_DEBUG) $(INC_DEBUG) -c -o $(OBJDIR_DEBUG)/cache.o cache.cpp

$(OBJDIR_DEBUG)/cache_line.o: cache_line.cpp
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	$(CPP) $(CFLAGS_DEBUG) $(INC_DEBUG) -c -o $(OBJDIR_DEBUG)/cache_line.o cache_line.cpp

$(OBJDIR_DEBUG)/cache_set.o: cache_set.cpp
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	$(CPP) $(CFLAGS_DEBUG) $(INC_DEBUG) -c -o $(OBJDIR_DEBUG)/cache_set.o cache_set.cpp

$(OBJDIR_DEBUG)/config.o: config.cpp
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	$(CPP) $(CFLAGS_DEBUG) $(INC_DEBUG) -c -o $(OBJDIR_DEBUG)/config.o config.cpp


$(OBJDIR_DEBUG)/main.o: main.cpp
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	$(CPP) $(CFLAGS_DEBUG) $(INC_DEBUG) -c -o $(OBJDIR_DEBUG)/main.o main.cpp

$(OBJDIR_DEBUG)/trace.o: trace.cpp
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	$(CPP) $(CFLAGS_DEBUG) $(INC_DEBUG) -c -o $(OBJDIR_DEBUG)/trace.o trace.cpp


clean_debug:
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)

release: $(OUT_RELEASE)

$(OUT_RELEASE): $(OBJ_RELEASE) $(DEP_RELEASE)
	test -d bin/Release || mkdir -p bin/Release
	$(LD) $(LDFLAGS_RELEASE) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE) $(LIB_RELEASE)


$(OBJDIR_RELEASE)/cache.o: cache.cpp
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	$(CPP) $(CFLAGS_RELEASE) $(INC_RELEASE) -c -o $(OBJDIR_RELEASE)/cache.o cache.cpp

$(OBJDIR_RELEASE)/cache_line.o: cache_line.cpp
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	$(CPP) $(CFLAGS_RELEASE) $(INC_RELEASE) -c -o $(OBJDIR_RELEASE)/cache_line.o cache_line.cpp

$(OBJDIR_RELEASE)/cache_set.o: cache_set.cpp
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	$(CPP) $(CFLAGS_RELEASE) $(INC_RELEASE) -c -o $(OBJDIR_RELEASE)/cache_set.o cache_set.cpp

$(OBJDIR_RELEASE)/config.o: config.cpp
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	$(CPP) $(CFLAGS_RELEASE) $(INC_RELEASE) -c -o $(OBJDIR_RELEASE)/config.o config.cpp


$(OBJDIR_RELEASE)/main.o: main.cpp
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	$(CPP) $(CFLAGS_RELEASE) $(INC_RELEASE) -c -o $(OBJDIR_RELEASE)/main.o main.cpp

$(OBJDIR_RELEASE)/trace.o: trace.cpp
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	$(CPP) $(CFLAGS_RELEASE) $(INC_RELEASE) -c -o $(OBJDIR_RELEASE)/trace.o trace.cpp


clean_release:
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)

.PHONY: clean clean_debug clean_release

