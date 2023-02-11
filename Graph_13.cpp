#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int INF=1e9+10; 
vector<pair<int,int>> graph[N];
vector<int>lev(N,INF);
int n,m;

int bfs(){
	deque<int>q;
	q.push_back(1);
	lev[1]=0;

	while(!q.empty()){
		int cur_vertex=q.front();
		q.pop_front();

		for(auto child:graph[cur_vertex]){
			int child_vertex=child.first;
			int weight=child.second;

			if(lev[cur_vertex]+weight<lev[child_vertex]){
				lev[child_vertex]=lev[cur_vertex]+weight;
				if(weight==1){
					q.push_back(child_vertex);
				}
				else{
					q.push_front(child_vertex);
				}
			}
		}
	}

	if(n==INF)return -1;
	else return lev[n];
}

int main (){
	cin>>n>>m;

	for(int i=0; i<m; i++){
		int x,y;
		cin>>x>>y;
		if(x==y)continue;
		graph[x].push_back({y,0});
		graph[y].push_back({x,1});
	}

	cout<<bfs()<<endl;


	return 0;
}
