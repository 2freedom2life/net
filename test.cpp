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
		cout << "������Ҫ���еĲ�����1.����·����   2.�����µ�·��  3.ɾ��·����  4.ɾ��·��  5.����·�ɱ�	6.���ͼ" << endl;
		cin >> b;
		switch (b)
		{
		case 1:cout << "������Ҫ���ӵ����" << endl;
			int a;
			cin >> a;
			graph.InsertVex(a);
			graph.PrintGraph();break;
		case 2:cout << "��������ʼ�㣬�����������,���������" << endl;
			int p; int b; int o;
			cin >> p; cin >> b; cin >> o;
			graph.InsertEdge(a, b, o);
			break;
		case 3:cout << "������Ҫɾ����·�������";cin >> e;
			graph.RemoveVex(e);graph.PrintGraph();break;
		case 4:cout << "������Ҫɾ��·����·�������";cin >> f;cin >> g;
			graph.RemoveEdge(f, g);
			graph.PrintGraph();break;
		case 5:cout << "������Ҫ����·�ɱ��·�������";
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