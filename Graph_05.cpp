#include <bits/stdc++.h>

using namespace std;



void dfs (vector<vector<int>> &graph, int n, int m, int i, int j, int k, int z){

	if(graph[i][j]==z)graph[i][j]=k;
	else return;

	if(j<m-1)dfs(graph,n,m,i,j+1,k,z);
	if(j>0)dfs(graph,n,m,i,j-1,k,z);
	if(i<n-1)dfs(graph,n,m,i+1,j,k,z);
	if(i>0)dfs(graph,n,m,i-1,j,k,z);
}


int main(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>>graph;
	for(int i=0; i<n; i++){
		vector<int>v(m);
		for(int j=0; j<m; j++){
			cin>>v[j];
		}
		graph.push_back(v);
	}

	int i,j,k;
	cin>>i>>j>>k;
	int z = graph[i][j];
	dfs(graph,n,m,i,j,k,z);

	for(int p=0; p<n; p++){
		for(int q=0; q<m; q++){
			cout<<graph[p][q]<<" ";
		}
		cout<<endl;
	}

	return 0;
}