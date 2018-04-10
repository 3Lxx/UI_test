INCLUDES := -I../../I2C/src -I../../PCA9685/src -I../../PCA9555/src
LIBRARIES := -L../../I2C/src -L../../PCA9685/src -L../../PCA9555/src
LIBS := -lI2C -lPCA9685 -lPCA9555
CXXFLAGS := -O3 -fPIC -g -Wall -Werror $(INCLUDES) $(LIBRARIES) $(LIBS)
CXX := g++
#CXX := arm-unknown-linux-gnueabi-g++
MAJOR := 0
MINOR := 1
NAME := UI_test
VERSION := $(MAJOR).$(MINOR)
RM := rm -rf

UI_test: UI_test.cpp
	$(CXX) UI_test.cpp $(INCLUDES) $(LIBRARIES) $(LIBS)
#all: lib copy
#lib: lib$(NAME).so.$(VERSION) lib$(NAME).so

#lib$(NAME).so: lib$(NAME).so.$(VERSION)
#	ldconfig -v -n .
#	ln -s lib$(NAME).so.$(MAJOR) lib$(NAME).so
#
#lib$(NAME).so.$(VERSION): $(NAME).o
#	$(CXX) -pg -shared -Wl,-soname,lib$(NAME).so.$(MAJOR) $^ -o $@
#	
clean:
	$(RM) *.o *.so*
#	
#copy:
#ifdef DISTPATH
#	cp lib$(NAME)* $(DISTPATH)
#endif
