#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int M=1e9+10;
vector<int> graph[N];
int value[N];
int subtree_sum[N];

void dfs(int vertex, int parent){
	subtree_sum[vertex]+=value[vertex];

	for(int child:graph[vertex]){
		if(child==parent)continue;
		dfs(child,vertex);
		subtree_sum[vertex]+=subtree_sum[child];
	}
}

int main (){
	int n;
	cin>>n;

	for(int i=0; i<n-1; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for(int i=1; i<=n; i++){
		cin>>value[i];
	}

	dfs(1,0);

	long long ans=0;
	for(int i=2; i<=n; i++){
		long long x=subtree_sum[i];
		long long y=subtree_sum[1]-subtree_sum[i];

		ans=max(ans,(x*y)%M);
	}

	cout<<ans<<endl;


	return 0;
}
