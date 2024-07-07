# SudokuSolver

This project contains C++ header file that can be helpful in solving and generating sudoku puzzles

# How to Use

**Adding header file**

Add the file "sudoku.h" to the folder in which you are going to write your code.

Along with the other headers, add _#include "sudoku.h"_ in your code.

Create an object of class sudoku

**Functions in sudoku.h**

1. _generate_sudoku()_ (return type: vector<vector<int>>)
   
   returns a valid sudoku with few empty cells having a unique solution.
   
2. _solve()_ (return type: vector<vector<vector<int>>>)
   
   returns vector containing possible solutions of the sudoku passed on to _Grid_ of that object
   
3. _print(vector<vector<int>>)_ (return type: void)
   
   prints the 9 x 9 matrix passed as argument in the form of a sudoku (i.e. space after every 3 elements in a row, new line after every 3 columns)
# Examples

**Example1**

Passing a sudoku puzzle to _Grid_ of the object created.

Finding all possible solutions of the given sudoku puzzle.

Printing the solution.

**Example2**

Generating a random sudoku puzzle with unique solution and passing it to _Grid_ of the object created.

Finding all possible solutions of the sudoku generated.

Printing the solution.
