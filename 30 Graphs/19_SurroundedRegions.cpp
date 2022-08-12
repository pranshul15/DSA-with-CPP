/* 
Given a 2D board containing 'X' and 'O' (the letter O)
Capture all regions surrounded by 'X'
Capture => A region is captured by flipping all the O's into 'X's
into that surrounded region
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    for(int i=0;i<board.size();i++){
        if(board[i][0] == 'O')
            board[i][0]='*';
        if(board[i][board[i].size()-1] == 'O')
            board[i][board[i].size()-1] = '*';
    }

    for(int j=0;j<board[0].size();j++){
        if(board[0][j] == 'O')
            board[0][j]='*';
        if(board[board.size()-1][j] == 'O')
            board[board.size()-1][j]='*';
    }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == '*'){
                board[i][j] = 'O';
            }
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}