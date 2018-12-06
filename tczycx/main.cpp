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
 	cout << "chenx" << endl;
	cout << "输入结点数，边数:" << endl;
	cin >> n >> l;
	while (1) {
		n=Create(n, l);
	//	n++;
		system("pause");
	}
		
	
	return 0;
}