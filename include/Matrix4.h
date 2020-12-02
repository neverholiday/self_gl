#ifndef Matrix4_H
#define Matrix4_H


namespace myMath
{
	class Matrix4
	{
		public:
			Matrix4();
			~Matrix4();
		
		public:
			void setValue( int rowIdx, int colIdx, double value );
			double getValue( int rowIdx, int colIdx );

		public:
			void identity();

		public:
			void printMatrix();

		protected:
			double values[16];

			int numRow;
			int numColumn;


		protected:
			int getFlatIndex( int rowIdx, int colIdx );
		
	};
};

#endif