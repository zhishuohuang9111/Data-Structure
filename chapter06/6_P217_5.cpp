
int visited[Max];

// i：表示开始顶点，j：表示要找的顶点 
void DFS(ALGraph G, int i, 
// u：开始顶点 v：终点结点 d：路径长度 
void FindPath(ALGraph *G, int u, int v, int []path, int &d){
	// 添加当前结点到路径中：首先路劲长度 + 1，再加入结点 
	d++;
	path[d] = u;
	visited[u] = 1;
	
	// 如果该点为路径终点，输出 
	if(u == v){
		for(int i = 0; i < path.length; i++){
			printf("%d", path[i]);
		}
	}
	// p 指向 u的邻接点，即第一个相邻点 
	ArcNode *p = G->adjList[u].firstarc;
    
	// 不断去访问 相邻点的下一个邻接点，往深处去搜索 
	while(p != NULL){
		// 获取 当前的邻接点的弧 所指向顶点的位置 
		int w = p->adjex;
		// w为被访问过，直接递归调用 
		if(visited[w] == 0){
			FindPath(G, w, v, path, d);
		}
		// 否则 p 后移 
		p = p->nextarc;
	}
	// 可能当前递归没有找到，需要回溯，使该点可以重新使用 
	visited[u] = 0;
}int j, bool &isok){
	if(i == j){
		isok = true;
		return;
	}
	
	visited[i] = 1;
	
	for(int p=FirstNeighbor(G, i); p >= 0; p = NextNeighbor(G, i, p)){
		// 如果没有找到 j点 并且 该点没有访问过，继续DFS遍历
		if(!visited[p] && !isok){
			DFS(G, p, j, isok);
		} 
	}
}

int BFS(ALGraph G, int i, int j){
	queue Q;
	InitQueue(Q);
	
	EnQueue(Q, i);
	
	while(!isEmpty(Q)){
		// 出队 并 保留出队元素 
		DeQueue(Q, u)
		visited[u] = 1;
		
		if(u == j){
			return 1;
		}
		
		for(int p = FirstNeighbor(G, i); p >= 0; p = NextNeighbor(G, i, p)){
			// 再次判断是否为 j 顶点
			// 是 直接返回 
			if(p == j){
				return 1;
			}
			// 不是 将邻接点入队 
			if(!visited[p]){
				EnQueue(Q, p);
				visited[p] = 1;
			}
		}
	}
	// 广度遍历完图，还没有找到 j 顶点 
	return 0;
}




