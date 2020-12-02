all: _MyMath.so

MyMath_swig.c++: MyMath_swig.i
	swig -python -c++ -I../include -o MyMath_swig.c++ MyMath_swig.i

MyMath_swig.o: MyMath_swig.c++
	g++ -fPIC -c -I/usr/include/python3.6 -I../include MyMath_swig.c++

_MyMath.so: MyMath_swig.o
	g++ -shared MyMath_swig.o -L../lib -lMyMath -o _MyMath.so

clean:
	rm MyMath_swig.c++ MyMath_swig.o _MyMath.so MyMath.py