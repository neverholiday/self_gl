#include "SimpleCheckerboardGenerator.h"


/*static*/ 
void SimpleCheckerboardGenerator::generateSquarecheckerboard( int dim, float* checkerBoard_ret, 
																int numChecker /* = 8*/ )
{

	//
	//	IMPROVE ME : Able to define num block and try to understand how to compute value
	//

	//
	//	IMPROVE ME : Currently, I support dim only power of two
	//

	//	We generate only 8 blocks
	int divider = dim/numChecker;

	float value = 0.0f;
	for (int row = 0; row < dim; row++) {
		for (int col = 0; col < dim; col++) {
			// Each cell is 8x8, value is 0 or 255 (black or white)
			value = (((row & divider) == 0) ^ ((col & divider) == 0)) * 1.0;

			for( int c = 0; c < 3 ; c++ )
			{
				int idx = c +  3 * ( col + dim * row );
				checkerBoard_ret[idx] = value;
			}
		}
	}

}