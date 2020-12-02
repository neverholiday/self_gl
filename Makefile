all: libSubdir test_gl test_math

libSubdir:
	make -C lib

test_gl: test_gl.c++
	g++ test_gl.c++ --std=c++17 -Wall -O3 -Llib -lGraphicEngines -lImageConstructor -lGL -lGLEW -lglfw -o test_gl

test_math: test_math.c++
	g++ test_math.c++ --std=c++17 -Wall -O3 -Llib -lMyMath -o test_math

clean:
	make -C lib clean
	rm -v test_gl test_math

.PHONY: clean
.SILENT: clean