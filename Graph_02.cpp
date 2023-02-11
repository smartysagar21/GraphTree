#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
vector<int>graph[N];
bool vis[N];


void dfs (int vertex){

	//Take action on vertex after entering on the vertex
	//cout<<vertex<<endl;
	vis[vertex]=true;

	for(int child:graph[vertex]){

		//Take action on child before entering the child node
		if(vis[child])continue;

		cout<<"parent "<<vertex<<", child "<<child<<endl;
		dfs(child);

		//Take action on child after exiting the child node
	}  

	//Take action on vertex before exiting the vertex
}


int main(){
	int n,m;
	cin>>n>>m;


	for(int i=0; i<m; i++){
		int v1,v2;
		cin>>v1>>v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}


	for(int i=1; i<=n; i++){

		dfs(i);
	}

	return 0;
}