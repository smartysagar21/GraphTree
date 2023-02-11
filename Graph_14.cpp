#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;
const int INF=1e9+10;
int val[N][N];
int lev[N][N];
int vis[N][N];
int n,m;

bool isValid(int i, int j){
	return(i<n && j<m && i>=0 && j>=0);
}

vector<pair<int,int>> movements={
	{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}
};

int bfs(){
	int mx=0;
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			mx=max(mx,val[i][j]);
		}
	}

	queue<pair<int,int>>q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(val[i][j]==mx){
				q.push({i,j});
				lev[i][j]=0;
				vis[i][j]=1;
			}
		}
	}

	while(!q.empty()){
		auto v=q.front();
		q.pop();
		int v_x=v.first;
		int v_y=v.second;

		for(auto movement:movements){
			int child_x=v_x+movement.first;
			int child_y=v_y+movement.second;
			if(!isValid(child_x,child_y))continue;
			if(vis[child_x][child_y])continue;
			q.push({child_x,child_y});
			lev[child_x][child_y]=lev[v_x][v_y]+1;
			vis[child_x][child_y]=1;
			ans=max(ans,lev[child_x][child_y]);
		}
	}

	return ans;
}

void reset(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			vis[i][j]=0;
			lev[i][j]=INF;
		}
	}
}

int main(){
	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;
		reset();
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>val[i][j];
			}
		}
		cout<<bfs()<<endl;
	}

	return 0;
}