#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class sudoku
{
public:
std::vector<std::vector<int>> Grid;

private:
// return a vector of pair of co-ordinates of all empty cells in the sudoku board
std::vector<std::pair<int, int>> empty_cells(std::vector<std::vector<int>> &Grid)
{
    std::vector<std::pair<int, int>> list_empty_cells;
    for (int i = 8; i >= 0; i--)
    {
        for (int j = 8; j >= 0; j--)
        {
            if (Grid[i][j] == 0)
            {
                list_empty_cells.push_back(std::make_pair(i, j));
            }
        }
    }
    return list_empty_cells;
}

// checks if it is valid to enter the number "n" at (x,y) in the given sudoku Grid
bool isvalid(int x, int y, int n, const std::vector<std::vector<int>> &Grid)
{
    // check in row x
    for (int i = 0; i < 9; i++)
    {
        if (Grid[x][i] == n)
        {
            return false;
        }
    }
    // check in column y
    for (int i = 0; i < 9; i++)
    {
        if (Grid[i][y] == n)
        {
            return false;
        }
    }
    // check in 3 x 3 grid containg (x,y)
    int X = (x / 3) * 3;
    int Y = (y / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Grid[X + i][Y + j] == n)
            {
                return false;
            }
        }
    }

    return true;
}

// returns an empty sudoku grid i.e. a 9 x 9 matrix with all zeros;
std::vector<std::vector<int>> generate_grid()
{
    std::vector<std::vector<int>> Grid(9, {0, 0, 0, 0, 0, 0, 0, 0, 0});
    return Grid;
}

void helper_is_solution_unique(std::vector<std::pair<int, int>> &list_empty_cells,
                               std::vector<std::vector<int>> &Grid,
                               std::vector<std::vector<std::vector<int>>> &Solutions,
                               int &count)
{
    if (count > 1)
        return;

    if (list_empty_cells.size() == 0)
    {
        Solutions.push_back(Grid);
        count++;
        return;
    }
    int x = (list_empty_cells.back()).first, y = (list_empty_cells.back()).second;
    for (int i = 1; i <= 9; i++)
    {
        if (isvalid(x, y, i, Grid))
        {
            Grid[x][y] = i;
            list_empty_cells.pop_back();
            helper_is_solution_unique(list_empty_cells, Grid, Solutions, count);
            Grid[x][y] = 0;
            list_empty_cells.push_back(std::make_pair(x, y));
            if (count > 1)
                break;
        }
    }
    return;
}

// checks the existence and uniqueness of solution to the given sudoku grid
std::pair<bool, bool> is_solution_unique(std::vector<std::vector<int>> Grid)
{
    std::vector<std::pair<int, int>> list_empty_cells = empty_cells(Grid);
    std::vector<std::vector<std::vector<int>>> Solutions;
    int count = 0;
    helper_is_solution_unique(list_empty_cells, Grid, Solutions, count);
    bool is_solution = false, is_unique = false;
    if (count == 1)
    {
        is_solution = true;
        is_unique = true;
    }
    else if (count > 1)
    {
        is_solution = true;
    }
    return std::make_pair(is_solution, is_unique);
}

// helper function of generate_sudoku
void helper_generate_sudoku(std::vector<std::vector<int>> &Grid, std::vector<int> &indices, bool &flag)
{

    if (flag == true || indices.empty())
        return;

    int last_index = indices.back();
    indices.pop_back();
    int x = last_index / 9;
    int y = last_index % 9;

    for (int i = 1; i <= 9; i++)
    {
        if (isvalid(x, y, i, Grid))
        {
            Grid[x][y] = i;
            std::pair<bool, bool> nature_of_solution = is_solution_unique(Grid);
            if (nature_of_solution.second)
            {
                flag = true;
                break;
            }
            else if (nature_of_solution.first)
            {
                helper_generate_sudoku(Grid, indices, flag);
                if (flag == true)
                    break;
                indices.push_back(last_index);
                Grid[x][y] = 0;
            }
        }
    }
    return;
}

// helper function of solve
void helper_solve(std::vector<std::pair<int, int>> &list_empty_cells,
                         std::vector<std::vector<int>> &Grid,
                         std::vector<std::vector<std::vector<int>>> &Solutions)
{
    if (list_empty_cells.size() == 0)
    {
        Solutions.push_back(Grid);
        return;
    }
    int x = (list_empty_cells.back()).first, y = (list_empty_cells.back()).second;
    for (int i = 1; i <= 9; i++)
    {
        if (isvalid(x, y, i, Grid))
        {
            Grid[x][y] = i;
            list_empty_cells.pop_back();
            helper_solve(list_empty_cells, Grid, Solutions);
            Grid[x][y] = 0;
            list_empty_cells.push_back(std::make_pair(x, y));
        }
    }
    return;
}

public:
// generates a sudoku with a unique valid solution
std::vector<std::vector<int>> generate_sudoku()
{
    std::vector<std::vector<int>> Grid = generate_grid();
    std::vector<int> indices(81);
    for (int i = 0; i < 81; i++)
        indices[i] = i;
    random_shuffle(indices.begin(), indices.end());
    bool flag = false;
    helper_generate_sudoku(Grid, indices, flag);
    return Grid;
}

// returns all the possible solutions of a given sudoku grid
std::vector<std::vector<std::vector<int>>> solve()
{
    std::vector<std::vector<int>> DummyGrid = Grid;
    std::vector<std::pair<int, int>> list_empty_cells = empty_cells(Grid);
    std::vector<std::vector<std::vector<int>>> Solutions;
    helper_solve(list_empty_cells, DummyGrid, Solutions);
    return Solutions;
}

// prints sudoku
void print(const std::vector<std::vector<int>> matrix)
{
    for(int i = 0; i < 9; i++)
    {
        if(i % 3 == 0)
        {
            std::cout<<"\n";
        }
        for(int j = 0; j < 9; j++)
        {
            if(j % 3 == 0)
            {
                std::cout<<" ";
            }
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}
};