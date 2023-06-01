#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void relax ( vector< vector<int> > &adj_matrix, vector<int> &times , vector<int> &predecessors, int startNode , int n){
    for (int i=0 ; i<n ; i++){
        if (adj_matrix[startNode][i] && times[i]>times[startNode]+adj_matrix[startNode][i]){
            times[i] = times[startNode]+adj_matrix[startNode][i];
            predecessors[i] = startNode;
        }
    }
}


vector<int> dijkstra (vector<vector<int>> adj_matrix, int n, int startNode){
    vector<int > unvisited ;
    for (int i=0 ; i<n ; i++){
        unvisited.push_back(i);
    }

    vector<int> times;
    vector<int> predecessors;

    for (int i =0; i < n ; i++){
        if (i == startNode){
            times.push_back(0);
        }
        else{
            times.push_back(INT8_MAX);};
        predecessors.push_back(0);
    }



    for(int i=0;i<n-1;i++){
        int min = INT8_MAX, minIndex;

    for (auto v:unvisited) {
        if (times[v] < min) {
            min = times[v];
            minIndex = v;
        }
    }

        relax(adj_matrix, times,predecessors, minIndex,n);
        unvisited.erase(remove(unvisited.begin(), unvisited.end(), minIndex), unvisited.end());

    }

    return times;

};

double Print(vector<int>& time, int src){
   int total_Time =0;

    cout<<"Source City: "<<src<<endl<<endl;
    for(int i=0; i < time.size(); i++){
        int shortestTime = time[i];
        cout << i << "\t" << shortestTime << endl;
        total_Time+=shortestTime;
    }
    double avgTime = (double)total_Time/(time.size()-1);
    cout<<"\n Avg Time: "<<avgTime<<endl<<endl<<endl;
    return avgTime;
}

int  main(){

    vector<vector<int>> adj_matrix = {{0,10,0,0,15,5},
                                      {10,0,10,30,0,0},
                                      {0,10,0,12,5,0},
                                      {0,30,12,0,0,20},
                                      {15,0,5,0,0,0},
                                      {5,0,0,20,0,0}};
   
    for (int i=0 ; i<adj_matrix.size() ; i++){
        vector<int> time= dijkstra (adj_matrix, adj_matrix.size(),i);
        Print(time, i);
    }
   

    return 0;
};