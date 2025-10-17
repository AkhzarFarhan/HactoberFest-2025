/*Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell 
is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true 
or false.
Input - 9 Lines where ith line contains ith row elements separated by space  */
#include<iostream>
using namespace std;

int rowcheck(int board[][9],int a,int b)
{
    for(int i=0;i<9;i++)
    {
        if(board[a][i]==b)return false;
    }
    return true;
}
int colcheck(int board[][9],int a,int b)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][a]==b)return false;
    }
    return true;
}
int cellcheck(int board[][9],int a,int b,int key)
{
    for(int i=a;i<a+3;i++)
    {
        for(int j=b;j<b+3;j++)
        if(board[i][j]==key)return false;
    }
    return true;
}
bool solve(int board[][9],int i, int j)
{
    if(i==8 && j==8)
    {
        if(board[8][8]==0)
        {
            for(int t=1;t<=9;t++)
            {
                if(rowcheck(board,8,t) && colcheck(board,8,t) && cellcheck(board,6,6,t))
                    return true;
            }
            return false;
        }
        else return true;
    }
    bool ans;
    if(board[i][j]==0)
    {
        for(int t=1;t<=9;t++)
        {
            if(rowcheck(board,i,t) && colcheck(board,j,t) && cellcheck(board,3*(i/3),3*(j/3),t))
            {
                board[i][j]=t;
                if(j<8)ans=solve(board,i,j+1);
                if(j==8)ans=solve(board,i+1,0);
            }
        }
        if(board[i][j]==0)return false;
        if(ans==false)board[i][j]=0;
    }
    else
    {
        if(j<8)ans=solve(board,i,j+1);
        if(j==8)ans=solve(board,i+1,0);
    }
    return ans;
}
bool sudokuSolver(int board[][9]){
  bool ans =solve(board,0,0);
    return ans;

}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}