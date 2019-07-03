#include <iostream>
#include<vector>
using namespace std;
void display(vector<vector<int> > &sol,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool safe(vector<vector<int> >maze,int x,int y, int N){
    if(x>=0 && x< N && y >=0 && y<N && maze[x][y] ==1 ){
        return true;
    }
    return false;
}
bool find_path(vector<vector<int> >maze,vector<vector<int> > &sol,int x,int y,int N){
    if(x == N-1 && y == N-1){
        sol[x][y] = 1;
        return true;
    }
    if(safe(maze,x,y,N)==true){
        sol[x][y] = 1;
        if(find_path(maze,sol,x+1,y,N)==true)
          return true;
        if(find_path(maze,sol,x,y+1,N)==true)
          return true;
        sol[x][y] = 0;
    }
    return false;

}
bool rat_in_a_maze(vector<vector<int> >maze,int N){

    vector<vector<int> > sol(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sol[i][j] = 0;
        }
    }
    if(find_path(maze,sol,0,0,N)==false) {
        cout<<"invalid sol";
        return false;
    }
    display(sol,N);
    return true;
}
int main() {
    int N;
    cin >> N;
    vector<vector<int> > maze(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> maze[i][j];
        }
    }
    rat_in_a_maze(maze,N);
    // printf("Hello World!");
}
/* Input
4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
 
Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 
*/
