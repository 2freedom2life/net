#include"stdio.h"
#include "net.h"
#include "net_wg.cpp"
#include "net_djh.cpp"
#include <iostream>
using namespace std;
int main() {
	Graph<int> graph;
	int c[30],d[30];
	int a, b, e,f,g;
	graph.CreateGraph();
	graph.PrintGraph();
	while (1) {
		cout << "请输入要进行的操作：1.增添路由器   2.增添新的路径  3.删除路由器  4.删除路径  5.导出路由表	6.输出图" << endl;
		cin >> b;
		switch (b)
		{
		case 1:cout << "请输入要增加的序号" << endl;
			int a;
			cin >> a;
			graph.InsertVex(a);
			graph.PrintGraph();break;
		case 2:cout << "请输入起始点，请输入结束点,请输入距离" << endl;
			int p; int b; int o;
			cin >> p; cin >> b; cin >> o;
			graph.InsertEdge(a, b, o);
			break;
		case 3:cout << "请输入要删除的路由器序号";cin >> e;
			graph.RemoveVex(e);graph.PrintGraph();break;
		case 4:cout << "请输入要删除路径的路由器序号";cin >> f;cin >> g;
			graph.RemoveEdge(f, g);
			graph.PrintGraph();break;
		case 5:cout << "请输入要导出路由表的路由器序号";
			cin >> a;
			a--;
			graph.ShortestPath(graph, a,c, d);break;
		case 6:
			graph.PrintGraph();
		}
	}
	system("pause");
	return 0;
}