#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
vector<int>graph[N];
int par[N];

void dfs(int vertex, int parent=-1){

	par[vertex]=parent;

	for(int child:graph[vertex]){
		if(child==parent)continue;

		dfs(child,vertex);
	}
}

vector<int> path(int v){
	vector<int>ans;
	while(v!=-1){
		ans.push_back(v);
		v=par[v];
	}
	reverse(ans.begin(),ans.end());
	return ans;

}


int main(){

	int n;
	cin>>n;

	for(int i=0; i<n-1; i++){
		int x,y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	int x,y;
	cin>>x>>y;
	vector<int> path_x=path(x);
	vector<int> path_y=path(y);

	int mn_length=min(path_x.size(),path_y.size());

	int lca=-1;
	for(int i=0; i<mn_length; i++){
		if(path_x[i]==path_y[i])lca=path_x[i];
		else break;
	}

	cout<<lca<<endl;

	return 0;
}