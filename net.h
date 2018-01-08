#pragma once
#ifndef NET_H
#define NET_H
#define DefaultVertexes 30 
#define maxWeight 100 
extern int visited[DefaultVertexes];
template <typename T>
class Graph {
public:
	Graph(int sz = DefaultVertexes);
	~Graph() {
		delete[] vexs;
		delete[] arcs;
	}
	void CreateGraph();
	void PrintGraph();
	void ShortestPath(Graph& G, int v, int dist[], int path[]);
	bool InsertVex(const T &vex);
	bool InsertEdge(const T &fromVex, const T &endVex, int weight);
	bool RemoveVex(const T &vex);
	bool RemoveEdge(const T &fromVex, const T &endVex);
	bool IsGraphFull() {
		if (numVexes == maxVexes || numArcs == numVexes*(numVexes - 1) / 2) {
			return true;
		}
		return false;
	}
	bool IsGraphEmpty() {
		if (numVexes == 0) {
			return true;
		}
		return false;
	}
	int GetLocation(const T &vex) {
		int i = 0;
		for (i = 0; i < numVexes; ++i) {
			if (vex == vexs[i]) {
				return i;
			}
		}
		return -1;
	}
	int getWeight(int v1, int v2) {
		return v1 != -1 && v2 != -1 ? arcs[v1][v2] : 0;
	}
	int NumberOfVertices() {
		return numVexes;
	}
	T GetValue(int pos) {
		if (pos >= 0 && pos < numVexes) {
			return vexs[pos];
		}
		return -1;
	}
private:
	T *vexs;
	int **arcs;
	int maxVexes;
	int numVexes;
	int numArcs;
};
#endif