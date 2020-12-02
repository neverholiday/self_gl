#include <iostream>
#include <cmath>

#include "Matrix4.h"


myMath::Matrix4::Matrix4() : values{0.0},
								numRow(4),
								numColumn(4) 
{
	this->identity();
}

myMath::Matrix4::~Matrix4()
{

}

void myMath::Matrix4::setValue( int rowIdx, int colIdx, double value )
{
	int idx = this->getFlatIndex( rowIdx, colIdx );
	this->values[idx] = value;
}

double myMath::Matrix4::getValue( int rowIdx, int colIdx )
{
	int idx = this->getFlatIndex( rowIdx, colIdx );
	return this->values[idx];
}


void myMath::Matrix4::identity()
{

	for( int i = 0; i < this->numRow; ++ i )
	{
		for( int j = 0; j < this->numColumn; ++ j )
		{
			if( i == j )
			{
				this->setValue( i, j, 1.0 );
			}
		}
	}
}

void myMath::Matrix4::printMatrix()
{
	std::cout.precision(5);
	for( int i = 0; i < this->numRow; ++ i )
	{
		for( int j = 0; j < this->numColumn; ++j )
		{
			int idx = this->getFlatIndex( i, j );
			std::cout << " " << std::fixed << this->values[idx];
		}
		std::cout << std::endl;
	}
}

int myMath::Matrix4::getFlatIndex( int rowIdx, int colIdx )
{
	return this->numColumn * rowIdx + colIdx;
}