
void DFS(Graph &G, int v, int &Vnum, int &Enum, visited[]){
	visited[v] = true; // 访问过 
	Vnum++; // 顶点数 + 1
	
	int w = FirstNeighbor(G, v);
	// w 不为 -1，说明存在邻边 
	while(w != -1){
		// 第一个邻接结点存在 存在边
		Enum++; // 边 +1 
		// 判断 w 是否访问过 
		if(!visited[w]){
			DFS(G, w, Vnum, Enum, visited);
		}
		// 返回除 w 以外顶点 v 的下一个邻接点的顶点 
		w = NextNeighbor(G, v, w);
	} 
} 

bool istree(){
	int Vnum = 0, Enum = 0;
	
	bool visited[Max];
	
	for(int i = 0; i < Max; i++){
		visited[i] = false;
	}
	
	// 参数：图，当前顶点，顶点个数，边的个数，visited
	DFS(G, 1, Vnum, Enum, visited);
	if(Vnum == G.vexnum && Enum == 2*(G.vexnum - 1)){
		return true;
	}
	return false;
}
