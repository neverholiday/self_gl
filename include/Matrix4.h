#ifndef Matrix4_H
#define Matrix4_H

#include <array>

namespace myMath
{
	class Matrix4
	{
		public:
			Matrix4();
			~Matrix4();
		
		public:
			void setValue( int rowIdx, int colIdx, double value );
			void setValue( int idx, double value );
			double getValue( int rowIdx, int colIdx );
			double getValue( int idx );

			double* getData();

		public:
			void setZero();
			void identity();
		
		public:
			Matrix4 add( Matrix4 &other );

		public:
			void printMatrix();

		protected:
			std::array<double, 16> values;

			int numRow;
			int numColumn;


		protected:
			int getFlatIndex( int rowIdx, int colIdx );
		
	};
};

#endif