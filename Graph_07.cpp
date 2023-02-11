#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
vector<int>graph[N];
int subtreeSum[N];
int evenCount[N];


void dfs (int vertex, int parent=0){

	//Take action on vertex after entering on the vertex

	subtreeSum[vertex]+=vertex;
	if(vertex%2==0)evenCount[vertex]++;
	for(int child:graph[vertex]){

		//Take action on child before entering the child node
		if(child==parent)continue;
		dfs(child, vertex);

		//Take action on child after exiting the child node

		subtreeSum[vertex]+=subtreeSum[child];
		evenCount[vertex]+=evenCount[child];
	}  

	//Take action on vertex before exiting the vertex
}


int main(){
	int n;
	cin>>n;


	for(int i=0; i<n-1; i++){
		int v1,v2;
		cin>>v1>>v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(1);

	for(int i=1; i<=n; i++){
		cout<<subtreeSum[i]<<" "<<evenCount[i]<<endl;
	}

	return 0;
}