all: libGraphicEngines.so libImageConstructor.so libMyMath.so


SimpleCheckerboardGenerator.o: SimpleCheckerboardGenerator.c++ ../include/SimpleCheckerboardGenerator.h
	g++ -std=c++17 -Wall -O3 -fPIC -I../include -c SimpleCheckerboardGenerator.c++

libImageConstructor.so: SimpleCheckerboardGenerator.o
	g++ -std=c++17 -Wall -O3 -shared SimpleCheckerboardGenerator.o -o libImageConstructor.so

ShaderProgramLoader.o: ShaderProgramLoader.c++ ../include/ShaderProgramLoader.h
	g++ -std=c++17 -Wall -O3 -fPIC -I../include -c ShaderProgramLoader.c++

libGraphicEngines.so: ShaderProgramLoader.o
	g++ -std=c++17 -Wall -O3 -shared ShaderProgramLoader.o -lGLEW -o libGraphicEngines.so

Matrix4.o: Matrix4.c++ ../include/Matrix4.h
	g++ -std=c++17 -Wall -O3 -fPIC -I../include -c Matrix4.c++

libMyMath.so: Matrix4.o
	g++ -std=c++17 -Wall -O3 -shared Matrix4.o -o libMyMath.so

clean:
	rm -v ShaderProgramLoader.o libGraphicEngines.so SimpleCheckerboardGenerator.o libImageConstructor.so Matrix4.o libMyMath.so 

.PHONY: clean
.SILENT: clean