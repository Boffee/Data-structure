#Variable declaration
COMPILER = g++
COMPILER_FLAG = -c -g -O0 -Wall -Werror
LINKER = g++

#Compile
rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(COMPILER) $(COMPILER_FLAG) rgbapixel.cpp

png.o : png.cpp png.h
	$(COMPILER) $(COMPILER_FLAG) png.cpp
    
image.o : image.cpp image.h
	$(COMPILER) $(COMPILER_FLAG) image.cpp


testimage.o : testimage.cpp image.h png.h rgbapixel.h
	$(COMPILER) $(COMPILER_FLAG) testimage.cpp

#Link
testimage : rgbapixel.o png.o image.o testimage.o
	$(LINKER) -o testimage rgbapixel.o png.o image.o testimage.o -lpng

#clean
clean:
	-rm -f *.o testimage

