all: libSubdir test_gl

libSubdir:
	make -C lib

test_gl: test_gl.c++
	g++ test_gl.c++ --std=c++17 -Wall -O3 -Llib -lShaderProgramLoader -lSimpleCheckerboardGenerator -lGL -lGLEW -lglfw -o test_gl

clean:
	make -C lib clean
	rm -v test_gl

.PHONY: clean
.SILENT: clean