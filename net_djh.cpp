////////////////////// 代建昊负责模块
#include "net.h"
template <typename T>
bool Graph<T>::InsertVex(const T &vex) {
	cout << "kjajsbdvkjasdbfh" << endl << endl;
	if (IsGraphFull()) {
		return false;
	}
	vexs[numVexes++] = vex;
	return true;
}

template <typename T>
bool Graph<T>::InsertEdge(const T &fromVex, const T &endVex, int cost) {
	if (IsGraphFull()) {
		cout << "Full!!" << endl;
		return false;
	}
	int row = GetLocation(fromVex), col = GetLocation(endVex);
	//	cout << row << endl << col << endl;

	if (row == -1 || col == -1) {
		cout << "Failure" << endl;
		return false;
	}

	//if (arcs[row][col] <= maxWeight) {
	arcs[row][col] = arcs[col][row] = cost;
	//cout << arcs[row][col] << endl;
	//		cout << "ok!ok!ok!" << endl;
	numArcs++;
	return true;
	//	}
}
template <typename T>
bool Graph<T>::RemoveVex(const T &vex) {
	if (IsGraphEmpty()) {
		return false;
	}
	int pos = GetLocation(vex);
	if (pos == -1) {
		return false;
	}
	vexs[pos] = vexs[numVexes - 1];
	int i = 0;
	for (i = 0; i < numVexes; ++i) {
		arcs[pos][i] = arcs[numVexes - 1][i];
	}
	for (i = 0; i < numVexes - 1; ++i) {
		arcs[i][pos] = arcs[i][numVexes - 1];
	}
	numVexes--;
}

template <typename T>
bool Graph<T>::RemoveEdge(const T &fromVex, const T &endVex) {
	int from = GetLocation(fromVex), end = GetLocation(endVex);
	if (end == -1 || from == -1) {
		return false;
	}
	arcs[from][end] = arcs[end][from] = maxWeight;
	return true;
}

template <typename T>
Graph<T>::Graph(int sz) {
	maxVexes = sz;
	numVexes = 0;
	numArcs = 0;
	int i, j;
	vexs = new T[sz];
	arcs = (int**)new int*[sz];
	for (i = 0; i < maxVexes; ++i) {
		arcs[i] = new int[maxVexes];
	}
	for (i = 0; i < maxVexes; ++i) {
		for (j = i; j < maxVexes; ++j) {
			if (i == j) {
				arcs[i][j] = 0;
				continue;
			}
			arcs[i][j] = arcs[j][i] = maxWeight;
		}
	}
}
////skjdgbfsdhgfy


