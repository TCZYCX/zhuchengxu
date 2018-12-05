#include "path.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int maxdist = 9999;

void printpath(vector<int>& pre, int init, int fina)
{
	int temp;
	temp = fina;
	vector<int> t;
	while (fina != init)
	{
		t.push_back(temp);
		temp = pre[fina];
		fina = temp;
	}
	cout << init << "->";
	for (int i = t.size(); i > 1; i--)
	{
		cout << t[i - 1] << "->";
	}
	int i;
	cout << t[0] << endl;
	cout << "ÏÂÒ»ÌøÎª:" << t[i = t.size() - 1] << endl;
	t.clear();
}
