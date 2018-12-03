#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
const int maxdist = 9999;

using namespace std;

/*n是总的结点数,v是出发结点,dist是距离,pre前一个结点,d是结点间的权值*/


void Dijkstra(int n, int v, vector<int> &dist, vector<int> &pre, vector<vector<int>> &d)
{
	if (v < n) {
		vector<bool> s(n + 1);
		for (int i = 1; i <= n; i++)
		{
			dist[i] = d[v][i];
			if (dist[i] < maxdist)
				pre[i] = v;
			else
				pre[i] = 0;
		}
		dist[v] = 0;
		s[v] = true;
		for (int i = 2; i <= n; i++)//总的迭代次数
		{
			int best = v;
			int temp = maxdist;
			for (int j = 1; j <= n; j++)//找到最小的距离
			{
				if (!s[j] && dist[j] < temp)
				{
					temp = dist[j];
					best = j;
				}
			}
			s[best] = true;
			for (int j = 1; j <= n; j++)//更新dist和pre
			{
				if (!s[j] && d[best][j] != maxdist)
				{
					int newdist = dist[best] + d[best][j];
					if (newdist < dist[j])
					{
						dist[j] = newdist;
						pre[j] = best;
					}
				}
			}
		}
	}
	if (v > n) {
		vector<bool> s(v + 1);
		for (int i = 1; i <= v; i++)
		{
			dist[i] = d[v][i];//将当前结点到每一个结点的距离
			if (dist[i] < maxdist)
				pre[i] = v;
			else
				pre[i] = 0;
		}
		dist[v] = 0;
		s[v] = true;
		for (int i = 2; i <= v; i++)//总的迭代次数
		{
			int best = n;
			int temp = maxdist;
			for (int j = 1; j <= v; j++)//找到最小的距离
			{
				if (!s[j] && dist[j] < temp)
				{
					temp = dist[j];
					best = j;
				}
			}
			s[best] = true;
			for (int j = 1; j <= v; j++)//更新dist和pre
			{
				if (!s[j] && d[best][j] != maxdist)
				{
					int newdist = dist[best] + d[best][j];
					if (newdist < dist[j])
					{
						dist[j] = newdist;
						pre[j] = best;
					}
				}
			}
		}
	}
}



void printpath(vector<int> pre, int init, int fina)
{
	ofstream fout("path.txt");
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
	fout << init << "->";
	for (int i = t.size(); i > 1; i--)
	{
		cout << t[i - 1] << "->";
		fout<< t[i - 1] << "->";
	}
	int i;
	cout << t[0] << endl;
	fout << t[0];
	cout << "下一跳为:" << t[i = t.size() - 1] << endl;
	fout << "下一跳为:" << t[i = t.size() - 1];
	fout.close();
	t.clear();
}




void Create(int n, int l) {
	ofstream fout("1.txt");
	if (!fout) {
		cout << "文件不能打开" << endl;
	}
	else {
		vector<vector<int>> d(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				d[i][j] = maxdist;
		}
		int p, q, len;
		for (int i = 1; i <= l; ++i)
		{
			cin >> p >> q >> len;
			if (len < d[p][q])       // 有重边
			{
				d[p][q] = len;      // p指向q
				d[q][p] = len;      // q指向p，这样表示无向图
			}
		}
		vector<int> dist(n + 1), pre(n + 1);
		int choice;
		cout << "输入1进行查询路由器并输出其路由表!" << endl;
		cin >> choice;
		if (choice == 1) {
			int p;
			cout << "输入你要查询的路由器的路由表:";
			cin >> p;
			for (int b = 1; b <= n; b++) {
				if (p != b) {
					for (int i = 1; i <= b; ++i)
						dist[i] = maxdist;
					Dijkstra(b, p, dist, pre, d);
					cout << "点" << p << "到点" << b << "的最短路径长度: " << dist[b] << endl;
					fout << dist[b];
					cout << "点" << p << "到点" << b << "的路径为:";
					printpath(pre, p, b);
				}
				else {
					continue;
				}
			}
		}
		int a, b;
		cout << "请输入起始点:";
		cin >> a;
		cout << "请输入终止点:";
		cin >> b;
		for (int i = 1; i <= b; ++i)
			dist[i] = maxdist;
		Dijkstra(b, a, dist, pre, d);
		cout << "点" << a << "到点" << b << "的最短路径长度: " << dist[b] << endl;
		cout << "点" << a << "到点" << b << "的路径为:";
		printpath(pre, a, b);
		/*for (a = 1; a <= n; a++) {
		for (b = 1; b <= n; b++) {
		if (a != b) {
		for (int i = 1; i <= b; ++i)
		dist[i] = maxdist;
		Dijkstra(b, a, dist, pre, d);
		cout << "点" << a << "到点" << b << "的最短路径长度: " << dist[b] << endl;
		cout << "点" << a << "到点" << b << "的路径为:";
		printpath(pre, a, b);
		}
		else {
		continue;
		}
		}*/
		/*cout << "************************************************************" << endl;
		cout << "**************1删除一个结点*********************************" << endl;
		cout << "请输入你想要删除的结点" << endl;
		int r;
		cin >> r;
		for (int i = 1; i <= n; ++i)
		{
			d[i][r] = maxdist;
			d[r][i] = maxdist;
		}
		Dijkstra(b, a, dist, pre, d);
		cout << "点" << a << "到点" << b << "的最短路径长度: " << dist[b] << endl;
		cout << "点" << a << "到点" << b << "的路径为:";
		printpath(pre, a, b);


		cout << "**************2删除一个边边*********************************" << endl;
		cout << "请输入你想要删除的边" << endl;
		int t, k, h;
		cin >> t >> k >> h;
		for (int i = 1; i <= l; ++i)
		{
				d[t][k] = maxdist;      // p指向q
				d[k][t] = maxdist;      // q指向p，这样表示无向图
		}
		Dijkstra(b, a, dist, pre, d);
		cout << "点" << a << "到点" << b << "的最短路径长度: " << dist[b] << endl;
		cout << "点" << a << "到点" << b << "的路径为:";
		printpath(pre, a, b);*/


		cout << "**************3增加多个结点*********************************" << endl;
		cout << "请输入你想要增加的结点数量" << endl;
		int x;
		cin >> x;
		int temp;
		temp = n;
		n += x;
		vector<vector<int>> g(n + 1, vector<int>(n + 1));

		for (int i = temp; i <= n; i++)
		{
			for (int j = temp; j <= n; j++)
				g[i][j] = maxdist;
		}
		cout << "请输入边的数量" << endl;
		int o, u, v, f;
		cin >> o;
		cout << "请输入结点和边" << endl;
		for (int i = 1; i <= o; ++i)
		{
			cin >> u >> v >> f;
			if (len < g[u][v])       // 有重边
			{
				g[u][v] = f;      // p指向q
				g[v][u] = f;      // q指向p，这样表示无向图
			}
		}
		int choice1;
		cout << "输入1进行查询路由器并输出其路由表!" << endl;
		cin >> choice1;
		if (choice1 == 1) {
			int p;
			cout << "输入你要查询的路由器的路由表:";
			cin >> p;
			for (int b = 1; b <= n; b++) {
				if (p != b) {
					for (int i = 1; i <= b; ++i)
						dist[i] = maxdist;
					Dijkstra(b, p, dist, pre, d);
					cout << "点" << p << "到点" << b << "的最短路径长度: " << dist[b] << endl;
					cout << "点" << p << "到点" << b << "的路径为:";
					printpath(pre, p, b);
				}
				else {
					continue;
				}
			}
		}
	}
}




int main()
{
	
	int n, l;
	cout << "请输入结点数和线数：";
	cin >> n >> l;
	Create(n, l);
	/*for (int i = 1; i <= b; ++i)
	dist[i] = maxdist;
	Dijkstra(b, a, dist, pre, d);
	cout << "点"<<a<<"到点"<<b<<"的最短路径长度: " << dist[b] << endl;
	cout << "点"<<a<<"到点"<<b<<"的路径为:";
	printpath(pre, a, b);*/
	system("pause");
	return 0;
}