#include "net.h"
template <typename T>
void Graph<T>::CreateGraph() {
	numVexes = 9;
	numArcs = 15;
	for (int i = 0; i < 9; i++) {
		vexs[i] = i + 1;
	}
	arcs[0][1] = arcs[1][0] = 2;
	arcs[0][6] = arcs[6][0] = 1;
	arcs[0][5] = arcs[5][0] = 1;
	arcs[1][2] = arcs[2][1] = 2;
	arcs[1][3] = arcs[3][1] = 4;
	arcs[2][5] = arcs[5][2] = 3;
	arcs[2][6] = arcs[6][2] = 2;
	arcs[2][3] = arcs[3][2] = 1;
	arcs[3][6] = arcs[6][3] = 6;
	arcs[3][4] = arcs[4][3] = 1;
	arcs[3][7] = arcs[7][3] = 5;
	arcs[3][8] = arcs[8][3] = 2;
	arcs[4][5] = arcs[5][4] = 5;
	arcs[5][6] = arcs[6][5] = 1;
	arcs[6][7] = arcs[7][6] = 3;
	arcs[7][8] = arcs[8][7] = 2;
}



template <typename T>
void Graph<T>::PrintGraph() {
	cout << "The vertexes : " << endl;

	int i = 0, n = numVexes, e = numArcs;

	for (i = 0; i < n; i++) {
		cout << vexs[i] << " ";
	}

	cout << endl;
	int j = 0;
	for (i = 0; i < n; ++i) {
		cout << GetValue(i) << "\t:\t";
		for (j = 0; j < n; ++j) {
			if (arcs[i][j] > 0 && arcs[i][j] < maxWeight) {
				cout << "(" << GetValue(j) << " , " << arcs[i][j] << ")\t";
			}
		}
		cout << endl;
	}
}



template <typename T>
void Graph<T>::ShortestPath(Graph& G, int v, int dist[], int path[])
{	
	int n = G.NumberOfVertices();
	bool *s = new bool[n];
	int i, j, k, w, min;
	int a, b, c;
	for (i = 0; i < n; i++) {
		dist[i] = G.getWeight(v, i);
		s[i] = false;
		if (i != v&&dist[i] < maxWeight) path[i] = v;
		else path[i] = -1;
	}
	s[v] = true; dist[v] = 0;
	for (i = 0; i < n - 1; i++) {
		min = maxWeight; int u = v;
		for (j = 0; j<n; j++)
			if (s[j] == false && dist[j] < min) {
				u = j; min = dist[j];
			}
		s[u] = true;
		for (k = 0; k < n; k++) {
			w = G.getWeight(u, k);
			if (s[k] == false && w < maxWeight&&dist[u] + w < dist[k]) {
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
	cout << "路由器" << G.GetValue(v) << "的路由表为" << endl;
	cout << "目的路由       " << "下一跳路由器     " << "距离" << endl;
	int *d = new int[n];
	for (i = 0; i < n; i++)
		if (i != v) {
			j = i; k = 0;
			while (j != v) {
				d[k++] = j; j = path[j];
			}
			cout << G.GetValue(i) << "            " << G.GetValue(d[--k]) << "                   " << dist[i] << endl;
		}
	delete[]d;
}



