
// 邻接表存储结点
// 边表的结点 
typedef struct Arcnode{
	// 但前弧指向顶点的位置
	int adjvex;
	// 指向下一条弧的指针
	struct Arcnode *next; 
}Arcnode; 

// 顶点表结点
typedef struct Vnode{
	// 顶点信息
	char data;
	// 指向第一条 依附该顶点弧的指针 
	// 注意：指针类型为 Arcnode类型 
	Arcnode *first;
}Vnode, AdjList[10]; 

// 组合的邻接表
typedef struct{
	// 邻接表
	AdjList v; 
	// 顶点数 和 弧数 
	int vnum, arcnum;
}ALGraph; 
 

void Convert(ALGraph &G, int arc[N][N]){
	// 用来取边 
	Arcnode *p; 
	
	// for循环 遍历 每条顶点表结点为头 的边链表（竖向表） 
	for(int i = 0; i < n; i++){
		// 注意写法 
		// 取顶点 i 的第一条边 
		p = (G->v.first);
		
		// while循环 遍历该顶点表结点为头的边链表 （横向表） 
		while(p != NULL){
			// 置 1 
			arcs[i][p->adjvex] = 1;
			// 指向下一个结点 即取下一条边
			p = p->next 
			
		}
	} 
}


