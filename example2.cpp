#include<iostream>
#include<vector>
#include "sudoku.h"

using namespace std;

int main()
{
    // create an object
    sudoku Sudoku1;
    // generate_sudoku returns a 9 x 9 matrix which is a valid sudoku question and has a unique solution
    // the generated matrix is stored in grid
    Sudoku1.Grid = Sudoku1.generate_sudoku();
    // print prints any 9 x 9 matrix (given as argument to the function) in the form of sudoku
    Sudoku1.print(Sudoku1.Grid);
    cout<<endl;
    // solve returns list of all solutions to the grid entered
    vector<vector<vector<int>>> solutions = Sudoku1.solve();
    
    for(int i=0; i<solutions.size(); i++){
        Sudoku1.print(solutions[i]);
        cout<<endl;
    }

    return 0;
}