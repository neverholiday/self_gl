all: test_gl

test_gl: test_gl.c++
	g++ test_gl.c++ -std=c++17 -O3 -lGL -lGLU -lGLEW -lglfw -o test_gl

clean:
	rm test_gl