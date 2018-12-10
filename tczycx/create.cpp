#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "create.h"
#include "dijkstra.h"
#include "path.h"
using namespace std;

const int maxdist = 9999;


void Create(int n, int l) {

	vector<vector<int>> d(n + 4, vector<int>(n + 4));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			d[i][j] = maxdist;
	}
	fstream file;
	int ch;
	file.open("Dog.txt", ios::in);
	ch = file.get();
	if (file.eof()) {
		cout << "文件为空，需要重新初始化" << endl;
		file.close();
		ofstream file;
		file.open("Dog.txt");
		int p, q, len;
		for (int i = 1; i <= l; ++i)
		{
			cin >> p >> q >> len;
			file << p << " " << q << " " << len << " ";
			if (len < d[p][q])       // 有重边
			{
				d[p][q] = len;      // p指向q
				d[q][p] = len;      // q指向p，这样表示无向图
			}
		}
		file.close();
	}
	else {
		cout << "已有拓扑文件信息：" << endl;
		ifstream file;
		file.open("Dog.txt");
		int p, q, len;
		for (int i = 1; i <= l; ++i)
		{
			file >> p >> q >> len;
			if (len < d[p][q])       // 有重边
			{
				d[p][q] = len;      // p指向q
				d[q][p] = len;      // q指向p，这样表示无向图
			}
		}

	}
	while (1) {
		vector<int> dist(n + 4), pre(n + 4);



		cout << "*************************路由表管理系统*********************" << endl;
		cout << "**************1删除一个结点*********************************" << endl;
		cout << "**************2删除一个边***********************************" << endl;
		cout << "**************3增加n个边或者结点****************************" << endl;
		cout << "**************4查询某个结点的路由表结点*********************" << endl;
		cout << "**************5退出此应用程序*******************************" << endl;
		cout << "************************************************************" << endl;

		cout << "请输入1——5中任意一个数进行操作" << endl;
		int y = 0;
		cin >> y;

		if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5) {
			switch (y) {
			case 1: {
				ofstream file;
				int ch1;
				file.open("Dog.txt");

				//ofstream file1;
				//	ifstream file1;
				cout << "请输入你想要删除的结点" << endl;
				int r;
				cin >> r;
				for (int i = 1; i <= n; ++i)
				{
					d[i][r] = maxdist;
					d[r][i] = maxdist;
				}
				/*for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						if (d[i][j] < maxdist)
							if (i > j) {
								file << i << " " << j << " " << d[i][j] << " ";
							}
					}

				}*/
				cout << "文件内容更新" << endl;



				/*(b, a, dist, pre, m);
				cout << "点" << a << "到点" << b << "的最短路径长度: " << dist[b] << endl;
				cout << "点" << a << "到点" << b << "的路径为:";
				printpath(pre, a, b);*/
				 /*
					int p;
					cout << "输入你要查询的路由器的路由表:";
					cin >> p;
					for (int b = 1; b <= n; b++) {
						if (p != b || p != r) {
							for (int i = 1; i <= b; ++i)
								dist[i] = maxdist;
							Dijkstra(b, p, dist, pre, d);
							if (dist[b] != maxdist) {
								cout << "点" << p << "到点" << b << "的最短路径长度: " << dist[b] << endl;

								cout << "点" << p << "到点" << b << "的路径为:";
								printpath(pre, p, b);
							}
							else {
								continue;
							}

						}
						else {
							continue;
						}
					}
				*/

			}
					; break;
			case 2: {
				ofstream file;
				int ch2;
				file.open("Dog.txt");

				cout << "请输入你想要删除的边" << endl;

				int t, k;
				cin >> t >> k;
				for (int i = 1; i <= l; ++i)
				{
					d[t][k] = maxdist;      // p指向q
					d[k][t] = maxdist;      // q指向p，这样表示无向图
				}
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						
								cout  << d[i][j] << " ";
							}
					cout << endl;
					}
				
				cout << "文件更新成功" << endl;
			/*	int choice3;
				cout << "输入1进行查询路由器并输出其路由表!" << endl;
				cin >> choice3;
				if (choice3 == 1) {
					int p;
					cout << "输入你要查询的路由器的路由表:";
					cin >> p;
					for (int b = 1; b <= n; b++) {
						if (p != b) {
							for (int i = 1; i <= b; ++i)
								dist[i] = maxdist;
							Dijkstra(b, p, dist, pre, d);
							if (dist[b] != maxdist) {
								cout << "点" << p << "到点" << b << "的最短路径长度: " << dist[b] << endl;

								cout << "点" << p << "到点" << b << "的路径为:";
								printpath(pre, p, b);
							}
							else {
								continue;

							}

						}
					else {*/
			}
							break;// continue;
						
					
			
					;
					break;
			case 3: {
				ofstream file;
				int ch3;
				file.open("Dog.txt");


				cout << "请输入你想要增加的结点数量" << endl;
				int x;
				cin >> x;
				int temp;
				temp = n;
				n += x;
				/*vector<vector<int>> g(n + 1, vector<int>(n + 1));
				for (int i = 1; i <= temp; i++)
				{
					for (int j = 1; j <= temp; j++) {
						g[i][j] = d[i][j];
						g[j][i] = d[j][i];
					}
				}*/
				for (int i = temp + 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
						d[i][j] = maxdist;
				}
				for (int i = 1; i <= n; i++) {
					for (int j = temp + 1; j <= n; j++) {
						d[i][j] = maxdist;
					}
				}
				cout << "请输入边的数量" << endl;
				int o, u, v, f;
				cin >> o;
				cout << "请输入结点和边" << endl;
				for (int i = 1; i <= o; ++i)
				{
					cin >> u >> v >> f;
					if (f < d[u][v])       // 有重边
					{
						d[u][v] = f;      // p指向q
						d[v][u] = f;
						// q指向p，这样表示无向图
					}
				}



				//矩阵输出，正常。
				cout << "文件更新成功" << endl;
			}
				//vector<int> dist1(n + 5), pre1(n + 5);
			/*	int p1;
				cout << "输入你要查询的路由器的路由表:";
				cin >> p1;

				for (int b = 1; b <= n; b++) {
					if (p1 != b) {

						dist[b] = maxdist;
						Dijkstra(b, p1, dist, pre, d);
						if (dist[b] != maxdist) {
							cout << "点" << p1 << "到点" << b << "的最短路径长度: " << dist[b] << "      ";

							cout << "点" << p1 << "到点" << b << "的路径为:";
							printpath(pre, p1, b);
						}
						else {
							continue;
						}
					}

					else {
						continue;
					}
				}

				file.close();
			}*/
					;
					break;
			case 4: {
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
							if (dist[b] != maxdist) {
								cout << "点" << p << "到点" << b << "的最短路径长度: " << dist[b] << "   ";

								cout << "点" << p << "到点" << b << "的路径为:";
								printpath(pre, p, b);
							}
							else {
								continue;
							}
						}

						else {
							continue;
						}
					}
				

				}



				break;
			};



			case 5:exit(0);
				break;

			}
		}
		else {
			cout << "输入错误请重新输入" << endl;
		}
	
	}
}