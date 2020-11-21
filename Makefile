all: test_gl

test_gl: test_gl.c++
	g++ test_gl.c++ --std=c++17 -Wall -O3 -Llib -lShaderProgramLoader -lGL -lGLEW -lglfw -o test_gl

clean:
	rm -v test_gl