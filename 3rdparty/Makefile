CXXFLAGS:= -fPIC 

all:x64

arm:TARGET=arm
arm:CXX=arm-linux-gnueabihf-g++
arm:lib3rdparty.a
	@echo "make arm"	

x64:TARGET=x64
x64:CXX=g++
x64:lib3rdparty.a
	@echo "make x64"	

CC=$(CXX)
CROSS_COMPILE=$(subst g++,,$(CXX))
AR=$(CROSS_COMPILE)ar

lib3rdparty.a:3rdparty.o
	$(AR) rs $@ $<
	cp -f $@ ../001/libs/$(TARGET)/


clean:
	rm -rf lib3rdparty.a 3rdparty.o
