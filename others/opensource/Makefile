CXXFLAGS:= -fPIC 

all:x64

arm:TARGET=arm
arm:CXX=arm-linux-gnueabihf-g++
arm:libopensource.a
	@echo "make arm"	

x64:TARGET=x64
x64:CXX=g++
x64:libopensource.a
	@echo "make x64"	

CC=$(CXX)
CROSS_COMPILE=$(subst g++,,$(CXX))
AR=$(CROSS_COMPILE)ar

libopensource.a:opensource.o
	$(AR) rs $@ $<
	cp -f $@ ../../001/libs/$(TARGET)/


clean:
	rm -rf *.a *.o
