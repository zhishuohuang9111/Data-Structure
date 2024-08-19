
// 存储时间数组 
int finishtime[Max];
// 访问的标记数组 
bool visited[Max];
void DFS(Graph G, int v){
	// 访问当前顶点 
	visiited[v] = true; 
	visit(v);
	
	for(w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
		if(!visited[w]){
			DFS(G, w);
		}
	}
	
	// 递归完后，开始 回溯
	time++; 
	finishtime[v] = time;
	
	
}

void DFSTraverse(Graph G){
	for(int i = 0; i < G.vexnum; i++){
		visited[i] = false;
	}
	
	// 初始化时间
	time = 0;
	// DFS每个没有被访问过的顶点
	for(int v = 0; v < G.vexnum; i++){
		if(!visited[v]){
			DFS(G, v);
		} 
	} 
}
