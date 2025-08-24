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

// Rat in maze 
int ratInMaze(vector<vector<int>> &maze, int row, int col, string move, vector<vector<bool>> &visited){
 // Always remember by default vector is pass by value. So in functions you have to pass it in pass by reference
 // Here the bug was I was passing visited in form of pass by value, hence in each call a copy of visited was made AND when we return to
 // previous call the positions that made true in later calls are not reflected in previous call's visited Because that later call's visited 
 // was another copy of visited and the previous call's visited was another copy. Hence when we returned form a call to its previous call the 
 // position made true was remained only just for that call and in previous call it was not reflected. And from previous call when we make 
 // another way call, the path that has been visited also shown as not visited although it is visited. Hence even if without making false a 
 // paticular cell it was behaving as false.Because in which call it was made true it remained only in that call. Not completely true.
 // So other calls were seeing it as false.
    int N = maze.size();
     if(row >= N || col >= N || row < 0 || col < 0 || maze[row][col] == 0 || visited[row][col] == true){
        return 0;
    }
    if(row == N-1 && col == N-1){
        cout<< move << '\n';
        return 1;
    }

    visited[row][col] = true;

    int val1 = ratInMaze(maze, row+1, col, move+"D", visited);
    int val2 = ratInMaze(maze, row, col+1, move+"R", visited);
    int val3 = ratInMaze(maze, row-1, col, move+"U", visited);
    int val4 = ratInMaze(maze, row, col-1, move+"L", visited);

    visited[row][col] = false;
    return val1 + val2 +val3 + val4;  
}
// Rat in maze in leetcode type design
void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis){
    int n = mat.size();
    if(r< 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c] == true){
        return;
    }

    if( r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    vis[r][c] = true;

    helper(mat, r+1, c, path+"D", ans, vis);
    helper(mat, r-1, c, path+"U", ans, vis);
    helper(mat, r, c-1, path+"L", ans, vis);
    helper(mat, r, c+1, path+"R", ans, vis);

    vis[r][c] = false;
}

vector<string> findPath(vector<vector<int>> &mat){
    int n = mat.size();

    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    
    helper(mat, 0, 0, path, ans, vis);

    return ans;
    
}

// Generate Parentheses --> Leetcode -22
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

// Sudoku Solver
void printSudoku(int sudoku[][9]){
    for(int i = 0; i< 9; i++){
        for(int j = 0; j< 9; j++){
            cout<< sudoku[i][j]<< " ";
        }
        cout<< endl;
    }
}

bool isSafe(int sudoku[][9], int row, int col, int digit){
    // horizontal
    for(int j = 0; j< 9; j++){
        if(sudoku[row][j] == digit){
            return false;
        }
    }

    // vertical
    for(int i = 0; i< 9; i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    // minor grid (3x3)
    int startingRow = (row/3) * 3 ;
    int startingCol = (col/3) * 3 ;
    for(int i = startingRow; i<= startingRow+2; i++){
        for(int j = startingCol; j<= startingCol+2; j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col){
    if(row == 9){
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;
    if(col+1 == 9){
        nextRow = row + 1;
        nextCol = 0;
    }

    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku, nextRow, nextCol);
    }
    for(int digit = 1; digit<=9; digit++){
        if(isSafe(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
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
    vector<vector<char>> sudoku;
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

/*    // Generate Parentheses --> Leetcode - 22
    string str = "(";
    int n = 3, i = 1;
    wellParentheses(str, n, i);
*/

/*    // Sudoku Solver
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}  
                        };
    sudokuSolver(sudoku, 0, 0);
*/

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    int ways =  ratInMaze(maze, 0, 0, "", visited);
    cout << "Total ways = "<< ways<< endl;
// Rat in maze in leetcode type design
    vector<string> ans = findPath(maze);
    for(string path : ans){
        cout<< path << endl;
    }

    return 0;
}