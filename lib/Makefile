all: libShaderProgramLoader.so


ShaderProgramLoader.o: ShaderProgramLoader.c++ ../include/ShaderProgramLoader.h
	g++ -std=c++17 -Wall -O3 -fPIC -I../include -c ShaderProgramLoader.c++

libShaderProgramLoader.so: ShaderProgramLoader.o
	g++ -std=c++17 -Wall -O3 -shared ShaderProgramLoader.o -lGLEW -o libShaderProgramLoader.so

clean:
	rm -v ShaderProgramLoader.o libShaderProgramLoader.so

.PHONY: clean
.SILENT: clean