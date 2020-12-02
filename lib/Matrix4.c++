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

//	THROW :: std::out_of_range
void myMath::Matrix4::setValue( int rowIdx, int colIdx, double value )
{
	int idx = this->getFlatIndex( rowIdx, colIdx );
	this->values.at( idx ) = value;
}

void myMath::Matrix4::setValue( int idx, double value )
{
	this->values.at( idx ) = value;
}

//	THROW :: std::out_of_range
double myMath::Matrix4::getValue( int rowIdx, int colIdx )
{
	int idx = this->getFlatIndex( rowIdx, colIdx );
	return this->values.at( idx );
}

//	THROW :: std::out_of_range
double myMath::Matrix4::getValue( int idx )
{
	return this->values.at( idx );
}

double* myMath::Matrix4::getData()
{
	return this->values.data();
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

void myMath::Matrix4::setZero()
{
	std::fill( this->values.begin(), this->values.end(), 0.0 );
}

myMath::Matrix4 myMath::Matrix4::add( Matrix4 &other )
{

	Matrix4 answer;

	for( int i = 0; i < this->numColumn * this->numRow; i++ )
	{
		double v_idx = this->getValue(i) + other.getValue(i);
		answer.setValue( i, v_idx );
	}
	return answer;
}

void myMath::Matrix4::printMatrix()
{
	std::cout.precision(5);
	for( int i = 0; i < this->numRow; ++ i )
	{
		for( int j = 0; j < this->numColumn; ++j )
		{
			int idx = this->getFlatIndex( i, j );
			std::cout << " " << std::fixed << this->values.at( idx );
		}
		std::cout << std::endl;
	}
}

int myMath::Matrix4::getFlatIndex( int rowIdx, int colIdx )
{
	return this->numColumn * rowIdx + colIdx;
}