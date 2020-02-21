class Hk{
public:
	int n;
	vector<int> b;
	vector<int> level;
	vector<bool> trip;
	vector<vector<int> > &adj;
	vector<int> idx;
	Hk(vector<vector<int> > &adj):adj(adj){
		n=adj.size();
		b=vector<int>(n);
		level=vector<int>(n);
		trip=vector<bool>(n);
		idx=vector<int>(n);
	}
	void bfs(){
		fill(level.begin(), level.end(), -1);
		queue<int> q;
		for(int i=0;i<n;i++){
			if(!trip[i]){
				q.push(i);
				level[i]=0;
			}
		}
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i];
				if(b[there]!=-1&&level[b[there]]==-1){
					level[b[there]]=level[now]+1;
					q.push(b[there]);
				}
			}
		}
	}
	bool dfs(int now){
		for(int &i=idx[now];i<adj[now].size();i++){
			int there=adj[now][i];
			if(b[there]==-1||(level[b[there]]==level[now]+1&&dfs(b[there]))){
				trip[now]=true;
				b[there]=now;
				return true;
			}
		}
		return false;
	}
	int flow(){
		fill(trip.begin(), trip.end(), false);
		fill(b.begin(), b.end(), -1);
		int total_flow=0;
		while(true){
			bfs();
			int flow=0;
			fill(idx.begin(), idx.end(), 0);
			for(int i=0;i<n;i++){
				if(!trip[i]&&dfs(i))
					flow++;
			}
			if(flow==0)
				break;
			total_flow+=flow;
		}
		return total_flow;
	}
};
