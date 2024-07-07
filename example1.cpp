#include "sudoku.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // create an object
    sudoku Sudoku1;
    // the grid to be solved is entered
    Sudoku1.Grid = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // solve returns list of all solutions to the grid entered
    vector<vector<vector<int>>> solution = Sudoku1.solve();

    cout << "Number of Solutions of the given sudoku is: " << solution.size() << "\n";
    for (int i = 0; i < solution.size(); i++)
    {
        cout << "Solution " << i + 1 << "\n";
        // print prints any 9 x 9 matrix (given as argument to the function) in the form of sudoku
        Sudoku1.print(solution[i]);
        cout << endl;
    }
    return 0;
}