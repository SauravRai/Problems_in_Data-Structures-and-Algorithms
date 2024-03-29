//This problem is inspired by the idea in Geeks for Geeks
//The problem is solved by Backtracking method
#include<iostream>

using namespace std;
#define N 4
void printSolution(int sol[N][N])
  {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
         {
            cout<<sol[i][j]<<" "<<endl;
         }

  }
bool isSafe(int maze[N][N], int x , int y)
  {
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1 )
    {
       return true;
    }
    return false;
  }
bool solveMazeUtil(int maze[N][N],int x ,int y,int sol[N][N])
    {
      if(x== N-1 && y == N-1)
       {
          sol[x][y] = 1;
          return true;
       }

        if(isSafe(maze,x,y)==true)
          {
            sol[x][y] =1;
           //we need to check for the values in the x direction as well
           if(solveMazeUtil(maze,x+1,y,sol) == true)
              {
                return true;
              }
           if(solveMazeUtil(maze,x,y+1,sol)==true)
              {
              return true;
              }
         sol[x][y] = 0;
         return false;
       }
      return false;
    }
}

bool solveMaze(int maze[N][N])
   {
    int sol[N][N] = { {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    if(solveMazeUtil(maze,0,0,sol) == false)
    {
       cout<<"Solution does not exist"<<endl;
       return false;
    }
    printSolution(sol);
    return true;
   }


int main()
   {
     int maze[N][N] = { {1,0,0,0},
                        {1,1,0,1},
                        {0,1,0,0},
                        {1,1,1,1}};
     solveMaze(maze);
     return 0;
   }
