#include <iostream>
#include<vector>
using namespace std;
void display(vector<int> path,int N){
    for(int i=0;i<N;i++){
      cout<<path[i]<<" ";
    }
}
bool safe(vector<vector<int> >hamiltongraph,vector<int> &path,int pos, int N,int v){
    if(hamiltongraph[path[pos-1]][v] != 1)
        return false;
    for(int i=0;i<N;i++){
        if(path[i] == v)
        return false;
    }
    return true;
}
bool find_path(vector<vector<int> >hamiltongraph,vector<int> &path,int pos,int N){
    if(pos == N){
        if(hamiltongraph[path[pos-1]][path[0]]== 1)
           return true;
        return false;
    }
    for(int v=1;v<N;v++){
       if(safe(hamiltongraph,path,pos,N,v)==true){
          path[pos] = v;
          if(find_path(hamiltongraph,path,pos+1,N)==true)
              return true;
           path[pos] = 0;
       }
    }
    return false;

}
bool hamilton(vector<vector<int> >hamiltongraph,int N){

    vector<int> path(N);
    for(int i=0;i<N;i++){
        path[i] = -1;
        }
        path[0] = 0;
    if(find_path(hamiltongraph,path,1,N)==false) {
        cout<<"invalid sol";
        return false;
    }
    display(path,N);
    return true;
}
int main() {
    int N;
    cin >> N;
    vector<vector<int> > hamiltongraph(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> hamiltongraph[i][j];
        }
    }
    hamilton(hamiltongraph,N);

}
/* Input
5
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0

Output
0 1 2 4 3

Input 
5
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 0
0 1 1 0 0
*/