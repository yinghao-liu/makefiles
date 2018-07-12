INCLUDE_DIR=include
MODULE_DIR=moduleA moduleB

CXXFLAGS:= -g -std=c++11 -MMD
LDFLAGS=-Llibs/$(TARGET)

SRC:=$(foreach mod,$(MODULE_DIR),$(wildcard $(mod)/*.cpp))
OBJ:=$(patsubst %.cpp,%.o,$(SRC))
DEP:=$(patsubst %.cpp,%.d,$(SRC))
CXXFLAGS+=$(addprefix -I,$(INCLUDE_DIR) $(MODULE_DIR))

#main.o:CXXFLAGS+=`pkg-config --cflags opencv`
#LDLIBS=`pkg-config --libs opencv` -l3rdparty
LDLIBS=-l3rdparty

all:x64

arm:TARGET=arm
arm:CXX=arm-linux-gnueabihf-g++
arm:main
	@echo "make arm"	

x64:TARGET=x64
x64:CXX=g++
x64:main
	@echo "make x64"	

CC=$(CXX)
CROSS_COMPILE=$(subst g++,,$(CXX))
AR=$(CROSS_COMPILE)ar

main:main.o $(OBJ)

-include $(DEP)

distclean:clean
	rm -rf $(OBJ) $(DEP)
clean:
	rm -rf main *.o *.d

