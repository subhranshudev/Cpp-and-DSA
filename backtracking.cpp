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

// Grid ways
int gridWays(int row, int col, int n, int m, string move){   // --> TC = O(2^(m+n))
    if(row == n-1 && col == m-1){ // Basecase
        cout<< move<< '\n';
        return 1;
    }
    if(row >= n ||  col >= m){ // Important basecase
        return 0;
    }

    int val1 = gridWays(row, col+1, n, m, move+"R"); // MOve Right
    int val2 = gridWays(row+1, col, n, m, move+"D");  // Move Down

    return val1 + val2; // Add the number of ways if moved right and moved down AND return
}

// Generate Parentheses --> Leetcode --> 22
bool isSafeforClose(string str, int i, int n){
    int openPcount = 0, closePcount = 0;
    for(int j = 0; j < i; j++){
        if(str[j] == '('){
            openPcount++;
        }else{
            closePcount++;
        }
    }
    if((closePcount < n) && (openPcount > closePcount)){
        return true;
    } else{
        return false;
    }

}
bool isSafeforOpen(string str, int i, int n){
    int openPcount = 0;
    for(int j = 0; j < i; j++){
        if(str[j] == '('){
            openPcount++;
        }
    }
    if((openPcount < n)){
        return true;
    } else{
        return false;
    }

}
void wellParentheses(string str, int n,  int i){

    if(i == (2*n)-1){
        str += ')';
        cout<< str<< '\n';
        return;
    }

    if(isSafeforOpen(str, i, n)){
        wellParentheses(str+"(", n, i+1);
    }

    if(isSafeforClose(str, i, n)){
        wellParentheses(str+")", n, i+1);
    }
   
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

/*    // N-Queens --> TC = O(n!), SC = O(n^2)
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
*/
    
/*    // Grid Ways
    int n =3, m = 3;
    string move = "";
    cout<< "Total grid ways = "<< gridWays(0, 0 , n, m, move)<< endl;
*/

    // Generate Parentheses --> Leetcode --> 22
    string str = "(";
    int n = 3, i = 1;
    wellParentheses(str, n, i);


    return 0;
}