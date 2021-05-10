/*
    Rat in a maze problem;
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    
    private:
    
    public:
        vector < vector < int > > maze; 

        void make_maze(int n);

        bool rat_path( int n , int r , int c , vector < vector < int > > &ans );

        bool is_safe(int n , int r , int c);


};

int main(){

    int n;
    cout<<"Enter dimensions of matrix: ";
    cin>>n;

    
    cout<<"Enter matrix: ";

    Solution sl;

    sl.make_maze(n);

    vector< vector < int > > ans;
    for(int i = 0 ; i < n ; ++i){
        vector < int > v1(n,0);
        ans.push_back(v1);
    }
    

    if(sl.rat_path(n , 0 , 0 , ans )){
        cout<<"Path exist\n";
        for(int i = 0 ; i < n ; ++i){
            
            for(int j = 0 ; j < n ; ++j){
                cout<<ans[i][j]<<" ";
            }
            
            cout<<endl;
        }   
    }
    else{
        cout<<"Path doesn't exist\n";
    }

    return 0;
}

void Solution::make_maze(int n){
    
    for(int i  = 0 ;  i < n ; ++i){

        vector < int > v1(n);

        for(int j = 0 ; j < n ; ++j){
            cin>>v1[j];
        }

        this->maze.push_back(v1);
    }
    return ;
}

bool Solution::rat_path( int n , int r , int c , vector < vector < int > > &ans){

    if(r == n-1 && c == n-1 && maze[r][c] == 1){
        ans[r][c] = 1;
        return true;
    }

    if(is_safe(n , r, c)){

    
        if(rat_path(n , r, c+1 ,ans)){
            ans[r][c] = 1;
            return true;
        }

        if(rat_path( n, r+1, c , ans)){
            ans[r][c] = 1;
            return true;
        }
    }

    return false;
}

bool Solution::is_safe(int n , int r , int c){
    return r < n && c < n && (this->maze[r][c] == 1);
}