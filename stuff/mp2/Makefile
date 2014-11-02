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

scene.o : scene.cpp scene.h
	$(COMPILER) $(COMPILER_FLAG) scene.cpp

testimage.o : testimage.cpp image.h png.h rgbapixel.h
	$(COMPILER) $(COMPILER_FLAG) testimage.cpp

testscene.o : testscene.cpp image.h png.h rgbapixel.h scene.h
	$(COMPILER) $(COMPILER_FLAG) testscene.cpp


#Link
testimage : rgbapixel.o png.o image.o testimage.o
	$(LINKER) -o testimage rgbapixel.o png.o image.o testimage.o -lpng

testscene : rgbapixel.o png.o image.o scene.o testscene.o
	$(LINKER) -o testscene rgbapixel.o png.o image.o scene.o testscene.o -lpng

all : testimage testscene

#clean
clean:
	-rm -f *.o all

