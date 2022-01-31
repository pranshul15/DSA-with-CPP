// we are given a 9x9 sudoku, solve it
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef map<pair<int,int>,map<int,int>> mpimi;
typedef vector<map<int,int>> vmi;
#define rep(i,a,b) for(int i=a;i<b;i++)


void helper(int r,int c,vvi &v, mpimi &m, vmi &row, vmi &col){
    // base case
    if(r == 9){
        // when function with row = 9 is called it will be last
        cout<<"its completed"<<endl;
        return;
    }

    if(c == 9){
        // after every row completion, we have to go to next row
        helper(r+1,0,v,m,row,col);
        return;
    }

    if(v[r][c] != 0){
        helper(r,c+1,v,m,row,col);
        return;
    }

    for(int i=1;i<=9;i++){
        int rw = r/3, cl = c/3;
        
        if(!m[{rw,cl}][i] and !row[r][i] and !col[c][i]){
            m[{rw,cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            v[r][c] = i;
            helper(r,c+1,v,m,row,col);
            m[{rw,cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            v[r][c] = 0;
        }
    }
    return;
}

void sudokuSolver(vvi &v){
    // map for 9 3x3 grid
    // pair will store the grid number => Key for grid
    // map for each grid 
    // ff => Key (Number 1-9)     ss => Occurance (0 or 1)
    mpimi mp;
    
    // to find particular number is in a row or not
    // vector of map for each row
    // vector for Row Number (0,8)
    // Map ff => Key (Number 1-9)   ss => Occurance (0 or 1)
    vmi row(9);
    
    // to find particular number is in a column or not
    // vector for Column Number (0,8)
    // Map ff => Key (Number 1-9)   ss => Occurance (0 or 1)
    vmi col(9);

    rep(i,0,9){
        rep(j,0,9){
            if(v[i][j] != 0){
                mp[{i/3,j/3}][v[i][j]] = 1;
                row[i][v[i][j]] = 1;
                col[j][v[i][j]] = 1;
            }
        }
    }

    helper(0,0,v,mp,row,col);

}

void helper2(int r,int c, vector<vector<int>> &v , map<int,map<int,int>> &grid,
vector<map<int,int>> &row , vector<map<int,int>> &col){
    if((r == 9) && (c == 9)){
        return;
    }
    if(r==9){
        helper2(0,c+1,v,grid,row,col);
        return;
    }
    if(v[r][c] != 0){
        helper2(r+1,c,v,grid,row,col);
        return;
    }

    for(int i=1;i<=9;i++){
        if(!row[r][i] && !col[c][i] && !grid[(r/3)*3 + (c/3)][i]){
            row[r][i] = 1;
            col[c][i] = 1;
            grid[(r/3)*3 + (c/3)][i] = 1;
            v[r][c] = 1;

            helper2(r+1,c,v,grid,row,col);

            v[r][c] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            grid[(r/3)*3 + (c/3)][i] = 0;

        }
    }
}

void sudokuSolver2(vvi &v){
    map<int , map<int,int>> grid;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            grid[(i/3)*3 + (j/3)][v[i][j]] = 1;
            row[i][v[i][j]] = 1;
            col[j][v[i][j]] = 1;
        }
    }

    helper2(0,0,v,grid,row,col);
}

bool helper3(int r,int c,vvi &v, mpimi &m, vmi &row, vmi &col){
    if((r==9) && (c==9)){
        return true;
    }
    if(r==9){
        return helper3(0,c+1,v,m,row,col);
    }
    if(v[r][c] != 0){
        return helper3(r+1,c,v,m,row,col);
    }
    for(int i=1;i<=9;i++){
        int rw=(r/3),cl=(c/3);
        if((!row[r][i]) && (!col[c][i]) && (!m[{rw,cl}][i])){
            row[r][i] = 1;
            col[c][i] = 1;
            m[{rw,cl}][i] = 1;
            v[r][c] = i;

            if(helper3(r+1,c,v,m,row,col)){
                return true;
            }

            row[r][i] = 0;
            col[c][i] = 0;
            m[{rw,cl}][i] = 0;
            v[r][c] = 0;

        }
    }
    return false;
}

void sudokuSolver3(vvi &v){
    mpimi m;
    vmi row(9);
    vmi col(9);
    rep(i,0,9){
        rep(j,0,9){
            if(v[i][j] != 0){
                int rw=(i/3),cl=(j/3);
                m[{rw,cl}][v[i][j]] = 1;
                row[i][v[i][j]] = 1;
                col[j][v[i][j]] = 1;
            }
        }
    }

    bool sudoku = helper3(0,0,v,m,row,col);
}

bool canSolveSudoku(vector<vector<char>>& board, int row, int col, vector<vector<bool>> rows, vector<vector<bool>> cols, vector<vector<bool>> box){
    
    if(row == 9 && col == 9)
        return true;
    if(row == 9)
        return canSolveSudoku(board,0,col+1,rows,cols,box);
    if(board[row][col] != '.')
        return canSolveSudoku(board,row+1,col,rows,cols,box);
    
    for(int i=1;i<=9;i++){
        if(!rows[row][i-1] && !cols[col][i-1] && !box[(row / 3) * 3 + col / 3][i-1]){
            rows[row][i-1] = true;
            cols[col][i-1] = true;
            box[(row / 3) * 3  + col / 3][i-1] = true;
            board[row][col] = char(i+48);
            if(canSolveSudoku(board,row+1,col,rows,cols,box))
                return true;
            board[row][col] = '.';
            rows[row][i-1] = false;
            cols[col][i-1] = false;
            box[(row / 3) * 3 + col / 3][i-1] = false;
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    vector<bool> temp(9);
    vector<vector<bool>> rows(9,temp);
    vector<vector<bool>> cols(9,temp);
    vector<vector<bool>> box(9,temp);
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] != '.'){
                int num = board[i][j] - '0';
                rows[i][num-1] = true;
                cols[j][num-1] = true;
                box[(i/3)*3 + j/3][num-1] = true;
            }
        }
    }
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(box[i][j])
                cout<<"box = "<<i<<" "<<j<<endl;
        }
    }
    
    canSolveSudoku(board,0,0,rows,cols,box);
    
}

int main(){

    vvi v ={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    vector<vector<char>> board ={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board);
    rep(i,0,9){
        rep(j,0,9){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}