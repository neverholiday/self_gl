#include <iostream>

#include "include/Matrix4.h"

int main(int argc, char const *argv[])
{
    myMath::Matrix4 matTest;


    std::cout << "Mat(4x4) = " << std::endl;
    matTest.printMatrix();

    double valTest = matTest.getValue( 0, 0 );
    std::cout << "get value from 0, 0" << std::endl;
    std::cout << "Mat(4x4)[ 0, 0 ]" << " = " << valTest << std::endl;
    
    matTest.setValue( 1, 2, 0.5 );

    double valTest_1 = matTest.getValue( 1, 2 );
    std::cout << "get value from 1, 2" << std::endl;
    std::cout << "Mat(4x4)[ 1, 2 ]" << " = " << valTest_1 << std::endl << std::endl;

    matTest.printMatrix();


    return 0;
}
