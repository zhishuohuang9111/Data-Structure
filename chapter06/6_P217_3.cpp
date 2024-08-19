// 非递归 DFS 遍历图 

void DFS(AGraph &G, int v){
	//初始化栈 
	stack S; 
	InitStack(S);
	
	bool visited[G.vexnum + 1];
	for(int i = 0; i < G.vexnum; i++){
		visited[i] = false;
	}
	
	// 顶点 v 压入栈中，更新 visited 数组 
	Push(S, v);
	visited[v] = true;
	
	while(!isEmpty(S)){
		// 出栈，并用  k 保存出栈结点 
		k = Pop(S, v);
		
		// 访问该结点，访问的顺序就是DFS顺序 
		visit(k);
		/*
		    w = NextNeighbor(G, v, w);
		    返回除 w 以外顶点 v 的下一个邻接点的顶点 
		*/
		// for循环：将 k 的所有 未压入过栈 的所有邻接结点 入栈 
		for(w = FirstNeighbor(G, k); w >= 0; w = NextNeighbor(G, k, w)){
			// 判断当前结点 w 是否 进入过栈 
			if(!visited[w]){
				Push(S, w);
				visited[w] = true;
			}
		} 
	}
}





