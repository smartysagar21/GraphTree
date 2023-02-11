#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
vector<int>graph[N];
int depth[N];


void dfs (int vertex, int parent=0){

	//Take action on vertex after entering on the vertex

	for(int child:graph[vertex]){

		//Take action on child before entering the child node
		if(child==parent)continue;
		depth[child]=depth[vertex]+1;

		dfs(child,vertex);

		//Take action on child after exiting the child node
	}  

	//Take action on vertex before exiting the vertex
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

	int mx_depth=-1;
	int mx_depthNode=0;

	for(int i=1; i<=n; i++){
		if(mx_depth<depth[i]){
			mx_depth=depth[i];
			mx_depthNode=i;
		}
		depth[i]=0;
	}

	dfs(mx_depthNode);
	mx_depth=-1;

	for(int i=1; i<=n; i++){
		if(mx_depth<depth[i]){
			mx_depth=depth[i];
		}
	}

	cout<<mx_depth<<endl;

	return 0;
}