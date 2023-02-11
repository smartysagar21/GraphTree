#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

vector<vector<int>>cc;
vector<int>current_cc;

void dfs (int vertex){

	vis[vertex]=1;
	current_cc.push_back(vertex);

	for(int child:g[vertex]){

		if(vis[child])continue;

		dfs(child);
	}  
}


int main(){
	int n,m;
	cin>>n>>m;

	for(int i=0; i<m; i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	int ct=0;
	for(int i=1; i<=n; i++){

		current_cc.clear();

		if(vis[i])continue;
		dfs(i);
		cc.push_back(current_cc);
		ct++;
	}

	cout<<ct<<endl;

	for(auto i:cc){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}