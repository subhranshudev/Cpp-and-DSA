#include<iostream>
#include<vector>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i< n; i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

void changeArr(int arr[], int n, int i){
    if(i == n){
        printArr(arr, n);
        return;
    }

    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2; // backtracking
}

void subsets(string str, string subset){
    if (str.size() == 0){
        cout<< subset<< endl;
        return;
    }

    char ch = str[0];
    subsets(str.substr(1, str.size()-1), subset+ch); // yes choice
    subsets(str.substr(1, str.size()-1), subset); // No choice
}

void permutations(string str, string permStr){
    int n = str.size();
    if(n == 0){
        cout<< permStr<< endl;
        return;
    }

    for(int i = 0; i< str.size(); i++){
        char ch = str[i];
        //permStr = permStr + str[i];
        string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1);
        permutations(nextStr, permStr + ch);
    }
}

// N-Queens
void printBoard(vector<vector<char>> board){
    for(int i = 0; i< board.size(); i++){
        for(int j = 0; j< board.size(); j++){
            cout<< board[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "-----------------------"<< endl;
}

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    // horizontally
    for(int j = 0; j < n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    // vertically
    for(int i = 0; i< row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // diagonal left
    for(int i = row, j = col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // diagonal right
    for(int i = row, j = col; i>=0 && j < n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

int nQueens(vector<vector<char>> board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return 1;
    }

    int count = 0;
    for(int j = 0; j< n; j++){
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';
        }
    }
    return count;
}

int main(){
    int arr[5];
    //int n = 5;
    // changeArr(arr, n, 0);
    // printArr(arr, n);

    // string str = "abc";
    // subsets(str, "");

    // string str = "abc";
    // string ans = "";
    // permutations(str, ans);

    // N-Queens --> TC = O(n!), SC = O(n^2)
    vector<vector<char>> board;
    int n = 4;

    for(int i = 0; i< n; i++){
        vector<char> newRow;
        for (int j = 0; j < n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);  
    }
    // printBoard(board);
    int count = nQueens(board, 0);
    // 2 another variations of N-Queens
    // 1-> Count of all solutions
       cout<< "count = "<< count;
    // 2-> Print any one solution

    return 0;
}