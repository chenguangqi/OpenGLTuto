CC=g++
LDLIBS=-lglut -lGLEW -lGL -lm

all: cube
cube: ../common/shader_utils.o
cube.o: res_texture.c

clean:
	rm -f *.o cube *~
.PHONY: all clean
