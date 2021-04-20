//
//  main.cpp
//  LengthOfConnectedCells
//
//  Created by princeraj on 17/04/21.
//
//

/*
 this code is taken from GeeksforGeeks
 */

#include <climits>
#include <iostream>
using namespace::std;


// Program to find the length of the largest
// region in boolean 2D-matrix

#define ROW 5
#define COL 5

// A function to check if
// a given cell (row, col)
// can be included in DFS
int isSafe(int M[][COL], int row, int col,
        bool visited[][COL])
{
    // row number is in range,
    // column number is in
    // range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0)
        && (col < COL)
        && (M[row][col] && !visited[row][col]);
}

// A utility function to
// do DFS for a 2D boolean
// matrix. It only considers
// the 8 neighbours as
// adjacent vertices
void DFS(int arr[][COL], int row, int col,
        bool visited[][COL], int& count)
{
    // These arrays are used
    // to get row and column
    // numbers of 8 neighbours
    // of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
    {
        if (isSafe(arr, row + rowNbr[k],
                col + colNbr[k],
                visited))
        {
            // Increment region length by one
            count++;
            DFS(arr, row + rowNbr[k], col + colNbr[k],
                visited, count);
        }
    }
}

// The main function that returns
// largest length region
// of a given boolean 2D matrix
int largestRegion(int arr[][COL])
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize result as 0 and travesle through the
    // all cells of given matrix
    int result = INT_MIN;
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            // If a cell with value 1 is not
            if (arr[i][j] && !visited[i][j])
            {
                // visited yet, then new region found
                int count = 1;
                DFS(arr, i, j, visited, count);

                // maximum region
                result = max(result, count);
            }
        }
    }
    return result;
}


// Driver code
int main()
{
    int arr[ROW][COL] = {
        {1,1,0,0,0},
        {0,1,1,0,0},
        {0,0,1,0,1},
        {1,0,0,0,1},
        {0,1,0,1,1} };

    // Function call
    cout <<largestRegion(arr)<<endl;

    return 0;
}















