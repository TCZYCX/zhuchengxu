#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "dijkstra.h"
#include "path.h"
#include "create.h"
using namespace std;

int main() {
	system("color 2f");
	int n, l;
	cout << "输入结点数，边数:" << endl;
	cin >> n >> l;
	Create(n, l);
	system("pause");
	return 0;
}