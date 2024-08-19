
int visited[Max];

// i：表示开始顶点，j：表示要找的顶点 
void DFS(ALGraph G, int i, int j, bool &isok){
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




