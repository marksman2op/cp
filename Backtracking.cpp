  
#include <vector>
#include <iostream>

/* 16 Diagonals problem: Consider a grid of 5 x 5 where each element is a square.
   Aim is to insert 16 diagonals in the squares such that no two diagonals touch each other
   Backtracking algorithm: Main idea is to construct a recursive tree 
   and cut its dead ends (partial permutations that cannot be solutions)
*/

#define gridLength 5

using gridType = std::vector<std::vector<int>>;

/* TR(Top to right) = \
   BR(Bottom to right) = /
   None = no diagonals
*/
namespace Orientation {
	int TR = 2;
	int BR = 1;
	int None = 0;
}

int getEmptyElements(gridType& grid) {
	int count = 0;
	for (auto row : grid) {
		for (int element : row) {
			if (element == Orientation::None)
				count++;
		}
	}
	return count;
}

bool canBeExtended(gridType& grid, int row, int column, int currentElement) {

    // 9 empty elements already present and we are trying to insert another
	if (getEmptyElements(grid) == 9 && currentElement == Orientation::None)
		return false;

	if (currentElement == Orientation::None)
		return true;

	if (currentElement == Orientation::TR) {
		// Element on the left cannot be BR
		if (row > 0 && grid[row - 1][column] == Orientation::BR)
			return false;
		// Element above cannot be BR
		if (column > 0 && grid[row][column - 1] == Orientation::BR)
			return false;
		// Element in left diagonal cannot be same
		if (row > 0 && column > 0 && grid[row-1][column - 1] == Orientation::TR)
			return false;
	}

	if (currentElement == Orientation::BR) {
		// Element on the left cannot be TR
		if (row > 0 && grid[row - 1][column] == Orientation::TR)
			return false;
		// Element above cannot be TR
		if (column > 0 && grid[row][column - 1] == Orientation::TR)
			return false;
		// Element in right diagonal cannot be same
		if (row > 0 && column < gridLength-1 && grid[row - 1][column + 1] == Orientation::BR)
			return false;
	}

	return true;
}

bool extend(gridType& grid, int row, int column) {

	if (column == gridLength) {
		column = 0;
		row++;
	}

	//all elements filled
	if (row == gridLength) {
		return true;
	}

	for (int i = Orientation::TR; i >= Orientation::None; i--) {
		if (canBeExtended(grid, row, column, i)) {
			grid[row][column] = i;
			if (extend(grid, row, column + 1)) {
				return true;
			}
		    grid[row][column] = -1;
		} 
	}
	return false;
}

void printSolution(gridType& grid) {
	std::cout << "Solution: \n";
	for (auto row : grid) {
		for (int element : row) {
			std::cout << element << " ";
		}
	}
}

int main() {
	gridType grid(5, std::vector<int>(5, -1));
	if (extend(grid, 0, 0)) {
	  printSolution(grid);
    }else {
		std::cout << "No Solution";
	}
	return 0;
}
