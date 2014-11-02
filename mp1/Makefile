#Variables
COMPILER = g++
COMPILER_FLAG = -c -g -O0 -Wall -Werror
LINKER = g++

#Compiling
main.o: main.cpp rgbapixel.h png.h
	$(COMPILER) $(COMPILER_FLAG) main.cpp

rgbapixel.o: rgbapixel.cpp rgbapixel.h
	$(COMPILER) $(COMPILER_FLAG) rgbapixel.cpp

png.o: png.cpp png.h
	$(COMPILER) $(COMPILER_FLAG) png.cpp

#Linking
mp1: main.o rgbapixel.o png.o
	$(LINKER) -o main.o rgbapixel.o png.o mp1 -lpng

#Clean rebuild
clean:
	-rm -f *.o mp1

