//#include"Graph_AdjMatrix.h"
#include"Graph_AdjList.h"
int main()
{
	ALGraph G;
	VertexType v="k";
	CreateGraph(G);
	Display(G);
	InsertVex(G, v);
	Display(G);
	InsertArc(G, v, "a");
	Display(G);
	DeleteVex(G,v);
	Display(G);
	
	cout << "----------------------------------------------------------------------------" << endl;
	BFSTraverse(G);
	return 0;
}