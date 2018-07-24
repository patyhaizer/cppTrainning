#include<iostream>
#include<cassert>
#include<vector>
using namespace std;
#include<cassert>
class Solution {
public:
void sumMatrixIndex(int& row, int& column, int matrixOrder) {
        int maxValue = matrixOrder - 1;
        for (int toSum = maxValue; toSum > 0; --toSum) {
            if (row == column) {
                if (row == maxValue) {
                    --column;
                } else if (row == 0) {
                    ++column;
                } else {
                    assert(0);
                }
            } else if (row < column) {
                if (column == maxValue) {
                    ++row;
                } else {
                    assert(column < maxValue);
                    ++column;
                }
            } else /*(row > column)*/ {
                if (column > 0) {
                    --column;
                } else {
                    assert(row > 0);
                    --row;
                }
            }
        }
    }
    void rotatePartial(vector<vector<int>>& matrix, int matrixOrder) {
        // Rotate outside part of matrix and call again rotating inside matrix
        // Which is just changing the order to order - 2
        //std::cout << "matrixOrder: " << matrixOrder << std::endl;
        if (matrixOrder < 2) return;
        int relativeIndex = (matrix.back().size() - matrixOrder)/2;
        //std::cout << "relativeIndex: " << relativeIndex << std::endl;
        for (int i = 0; i < matrixOrder-1; ++i) {
            //std::cout << "///////////begin line ///////////" << std::endl;
            int row = 0;
            int column = i;
            int elem = matrix[row+relativeIndex][column+relativeIndex];
            for (int move = 0; move < 4; ++move) {
                //std::cout << "curr elem: " << elem << std::endl;
                //std::cout << "row: " << row  << " column: " << column << std::endl;
                //std::cout << "relative row: " << row+relativeIndex  << " relative column: " << column+relativeIndex << std::endl;
                sumMatrixIndex(row, column, matrixOrder);
                //std::cout << "new row: " << row  << " new column: " << column << std::endl;
                //std::cout << "new relative row: " << row+relativeIndex << " new relative column: " << column+relativeIndex << std::endl;
                int* tmpPosition = &matrix[row+relativeIndex][column+relativeIndex];
                int newElem = *tmpPosition;
                //std::cout << "new elem: " << newElem << std::endl;
                *tmpPosition = elem;    
                elem = newElem;
            }
            //std::cout << "///////////finished line ///////////" << std::endl;
        }
        rotatePartial(matrix, matrixOrder - 2);
    }
    void rotate(vector<vector<int>>& matrix) {
        for (int matrixOrder = matrix.back().size(); matrixOrder > 1; matrixOrder-=2) {
            int relativeIndex = (matrix.back().size() - matrixOrder)/2;
            for (int i = 0; i < matrixOrder-1; ++i) {
            //std::cout << "///////////begin line ///////////" << std::endl;
                int row = 0;
                int column = i;
                int elem = matrix[row+relativeIndex][column+relativeIndex];
                for (int move = 0; move < 4; ++move) {
                    //std::cout << "curr elem: " << elem << std::endl;
                    //std::cout << "row: " << row  << " column: " << column << std::endl;
                    //std::cout << "relative row: " << row+relativeIndex  << " relative column: " << column+relativeIndex << std::endl;
                    sumMatrixIndex(row, column, matrixOrder);
                    //std::cout << "new row: " << row  << " new column: " << column << std::endl;
                    //std::cout << "new relative row: " << row+relativeIndex << " new relative column: " << column+relativeIndex << std::endl;
                    int* tmpPosition = &matrix[row+relativeIndex][column+relativeIndex];
                    int newElem = *tmpPosition;
                    //std::cout << "new elem: " << newElem << std::endl;
                    *tmpPosition = elem;    
                    elem = newElem;
                }
            }
        }
        //rotatePartial(matrix, matrix.back().size());
    }
};

int main () {
    Solution sol;
    int row = 1;
    int column = 0;
    sol.sumMatrixIndex(row, column, 2);
    std::cout << "new row: " << row << " - new column: " << column << std::endl;
	return 0;
}
