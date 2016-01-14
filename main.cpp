#include <iostream>
#define N 9

using namespace std;

bool findUnassignedCell(int grid[N][N], int &row, int &col){
    for(row=0; row<N; row++){
        for(col=0; col<N; col++){
            if(grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafeRow(int grid[N][N], int row, int i){
    for(int col = 0; col<9; col++){
        if(grid[row][col] == i)
            return false;
    }
    return true;
}

bool isSafeCol(int grid[N][N], int col, int i){
    for(int row=0; row<9; row++){
        if(grid[row][col] == i)
            return false;
    }
    return true;
}

bool isSafeSquare(int grid[N][N], int row, int col, int i){
    int rowStart = row - (row%3);
    int colStart = col - (col%3);

    for(int row=0; row < 3; row++){
        for(int col=0; col<3; col++){
            if(grid[row+rowStart][col+colStart] == i)
                return false;
        }
    }
    return true;
}

void print(int grid[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j%3 == 0 && j!=0)
                cout<<"\t";
            cout<<grid[i][j];
        }
        if((i+1)%3 == 0)
            cout<<"\n";
        cout<<"\n";
    }
}

bool possibleSafe(int grid[N][N], int row, int col, int i){

    bool safeRow = isSafeRow(grid, row, i);
    bool safeCol = isSafeCol(grid, col, i);
    bool safeSquare = isSafeSquare(grid, row, col, i);

    return safeRow&&safeCol&&safeSquare;

}

bool solver(int grid[N][N]){

    int row, col;
    //Check to see if there are any unassigned cells, if not its solved
    if(!findUnassignedCell(grid, row, col))
        return true;

    for(int i=1; i<=9; i++){
        if(possibleSafe(grid,row,col,i)){
            grid[row][col] = i;

            if(solver(grid))
                return true;
            //failed
            grid[row][col] = 0;

        }
    }
    return false;
}

int main()
{
    int grid[N][N] = {{0, 0, 0, 7, 2, 0, 4, 0, 0},
                      {0, 0, 1, 0, 0, 8, 9, 0, 0},
                      {0, 0, 0, 0, 4, 0, 8, 5, 7},
                      {5, 0, 6, 0, 0, 0, 0, 2, 0},
                      {0, 4, 0, 0, 0, 0, 1, 0, 6},
                      {9, 0, 0, 0, 0, 0, 0, 0, 4},
                      {0, 0, 0, 0, 0, 4, 0, 7, 0},
                      {2, 0, 0, 0, 9, 0, 0, 0, 0},
                      {0, 5, 0, 8, 0, 7, 0, 0, 0}};


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<"Value for ["<<i+1<<"],["<<j+1<<"]: ";
            cin>>grid[i][j];
        }
    }



    if(solver(grid))
        print(grid);
    else
        cout<<"NO SOLUTION!"<<endl;




    return 0;
}
