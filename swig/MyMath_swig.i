%module MyMath
%{
#include "Matrix4.h"
%}


%extend myMath::Matrix4 {
    %pythoncode %{
    def __repr__(self):
        reprString = ''
        for i in range( self.getNumRow() ):
            for j in range( self.getNumColumn() ):
                idx = self.getNumColumn() * i + j;
                reprString += '{} '.format( self.getValue(idx) )
            reprString += '\n'
        return reprString
    %}
};


%include "Matrix4.h"