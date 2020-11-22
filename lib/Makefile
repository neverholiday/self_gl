all: libShaderProgramLoader.so libSimpleCheckerboardGenerator.so


SimpleCheckerboardGenerator.o: SimpleCheckerboardGenerator.c++ ../include/SimpleCheckerboardGenerator.h
	g++ -std=c++17 -Wall -O3 -fPIC -I../include -c SimpleCheckerboardGenerator.c++

libSimpleCheckerboardGenerator.so: SimpleCheckerboardGenerator.o
	g++ -std=c++17 -Wall -O3 -shared SimpleCheckerboardGenerator.o -o libSimpleCheckerboardGenerator.so

ShaderProgramLoader.o: ShaderProgramLoader.c++ ../include/ShaderProgramLoader.h
	g++ -std=c++17 -Wall -O3 -fPIC -I../include -c ShaderProgramLoader.c++

libShaderProgramLoader.so: ShaderProgramLoader.o
	g++ -std=c++17 -Wall -O3 -shared ShaderProgramLoader.o -lGLEW -o libShaderProgramLoader.so

clean:
	rm -v ShaderProgramLoader.o libShaderProgramLoader.so SimpleCheckerboardGenerator.o libSimpleCheckerboardGenerator.so 

.PHONY: clean
.SILENT: clean