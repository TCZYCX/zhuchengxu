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
	cout << "Test!" << endl;
	vector<vector<int>> d(n + 1, vector<int>(n + 1));
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
		cout << "�ļ�Ϊ�գ���Ҫ���³�ʼ��" << endl;
		file.close();
		ofstream file;
		file.open("Dog.txt");
		int p, q, len;
		for (int i = 1; i <= l; ++i)
		{
			cin >> p >> q >> len;
			file << p << " " << q << " " << len << " ";
			if (len < d[p][q])       // ���ر�
			{
				d[p][q] = len;      // pָ��q
				d[q][p] = len;      // qָ��p��������ʾ����ͼ
			}
		}
		file.close();
	}
	else {
		cout << "���������ļ���Ϣ��" << endl;
		ifstream file;
		file.open("Dog.txt");
		int p, q, len;
		for (int i = 1; i <= l; ++i)
		{
			file >> p >> q >> len;
			if (len < d[p][q])       // ���ر�
			{
				d[p][q] = len;      // pָ��q
				d[q][p] = len;      // qָ��p��������ʾ����ͼ
			}
		}

	}
	vector<int> dist(n + 1), pre(n + 1);


	cout << "*************************·�ɱ����ϵͳ*********************" << endl;
	cout << "**************1ɾ��һ�����*********************************" << endl;
	cout << "**************2ɾ��һ����***********************************" << endl;
	cout << "**************3����n���߻��߽��****************************" << endl;
	cout << "**************4��ѯĳ������·�ɱ���*********************" << endl;
	cout << "**************5�˳���Ӧ�ó���*******************************" << endl;
	cout << "************************************************************" << endl;

	cout << "������1����5������һ�������в���" << endl;
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
			cout << "����������Ҫɾ���Ľ��" << endl;
			int r;
			cin >> r;
			for (int i = 1; i <= n; ++i)
			{
				d[i][r] = maxdist;
				d[r][i] = maxdist;
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (d[i][j]<maxdist)
						if (i > j) {
							file << i << " " << j << " " << d[i][j] << " ";
						}
				}

			}
			cout << "�ļ����ݸ���" << endl;



			/*(b, a, dist, pre, m);
			cout << "��" << a << "����" << b << "�����·������: " << dist[b] << endl;
			cout << "��" << a << "����" << b << "��·��Ϊ:";
			printpath(pre, a, b);*/
			int choice2;
			cout << "����1���в�ѯ·�����������·�ɱ�!" << endl;
			cin >> choice2;
			if (choice2 == 1) {
				int p;
				cout << "������Ҫ��ѯ��·������·�ɱ�:";
				cin >> p;
				for (int b = 1; b <= n; b++) {
					if (p != b) {
						for (int i = 1; i <= b; ++i)
							dist[i] = maxdist;
						Dijkstra(b, p, dist, pre, d);
						cout << "��" << p << "����" << b << "�����·������: " << dist[b] << endl;
						if (dist[b] != maxdist) {
							cout << "��" << p << "����" << b << "��·��Ϊ:";
							printpath(pre, p, b);
						}
						else {
							cout << "���ɴ" << endl;
						}
					}
					else {
						continue;
					}
				}
			}
			file.close();
			system("pause");
		}
				; break;
		case 2: {
			ofstream file;
			int ch2;
			file.open("Dog.txt");

			cout << "����������Ҫɾ���ı�" << endl;

			int t, k, h;
			cin >> t >> k >> h;
			for (int i = 1; i <= l; ++i)
			{
				d[t][k] = maxdist;      // pָ��q
				d[k][t] = maxdist;      // qָ��p��������ʾ����ͼ
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (d[i][j]<maxdist)
						if (i > j) {
							file << i << " " << j << " " << d[i][j] << " ";
						}
				}
			}
			cout << "�ļ����³ɹ�" << endl;
			int choice3;
			cout << "����1���в�ѯ·�����������·�ɱ�!" << endl;
			cin >> choice3;
			if (choice3 == 1) {
				int p;
				cout << "������Ҫ��ѯ��·������·�ɱ�:";
				cin >> p;
				for (int b = 1; b <= n; b++) {
					if (p != b) {
						for (int i = 1; i <= b; ++i)
							dist[i] = maxdist;
						Dijkstra(b, p, dist, pre, d);
						cout << "��" << p << "����" << b << "�����·������: " << dist[b] << endl;
						if (dist[b] != maxdist) {
							cout << "��" << p << "����" << b << "��·��Ϊ:";
							printpath(pre, p, b);
						}
						else {
							cout << "���ɴ" << endl;
						}
					}
					else {
						continue;
					}
				}
			}file.close();
		}system("pause");
				;
				break;
		case 3: {
			ofstream file;
			int ch3;
			file.open("Dog.txt");


			cout << "����������Ҫ���ӵĽ������" << endl;
			int x;
			cin >> x;
			int temp;
			temp = n;
			n += x;
			vector<vector<int>> g(n + 1, vector<int>(n + 1));
			for (int i = 1; i <= temp; i++)
			{
				for (int j = 1; j <= temp; j++) {
					g[i][j] = d[i][j];
					g[j][i] = d[j][i];
				}
			}
			for (int i = temp + 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
					g[i][j] = maxdist;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = temp + 1; j <= n; j++) {
					g[i][j] = maxdist;
				}
			}
			cout << "������ߵ�����" << endl;
			int o, u, v, f;
			cin >> o;
			cout << "��������ͱ�" << endl;
			for (int i = 1; i <= o; ++i)
			{
				cin >> u >> v >> f;
				if (f < g[u][v])       // ���ر�
				{
					g[u][v] = f;      // pָ��q
					g[v][u] = f;      // qָ��p��������ʾ����ͼ
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (g[i][j] < maxdist) {
						if (i > j) {
							file << i << " " << j << " " << g[i][j] << " ";
						}
					}
				}


			}//���������������
			cout << "�ļ����³ɹ�" << endl;
			vector<int> dist1(n + 1), pre1(n + 1);
			int p1;
			cout << "������Ҫ��ѯ��·������·�ɱ�:";
			cin >> p1;

			for (int b = 1; b <= n; b++) {
				if (p1 != b) {

					dist1[b] = maxdist;

					Dijkstra(b, p1, dist1, pre1, g);
					cout << "��" << p1 << "����" << b << "�����·������: " << dist1[b] << endl;
					if (dist1[b] != maxdist) {
						cout << "��" << p1 << "����" << b << "��·��Ϊ:";
						printpath(pre1, p1, b);
					}
					else {
						cout << "���ɴ" << endl;
					}
				}
				else {
					continue;
				}
			}
			file.close();
		}system("pause");
				;
				break;
		case 4: {
			int choice;
			cout << "����1���в�ѯ·�����������·�ɱ�!" << endl;
			cin >> choice;
			if (choice == 1) {
				int p;
				cout << "������Ҫ��ѯ��·������·�ɱ�:";
				cin >> p;
				for (int b = 1; b <= n; b++) {
					if (p != b) {
						for (int i = 1; i <= b; ++i)
							dist[i] = maxdist;
						Dijkstra(b, p, dist, pre, d);
						cout << "��" << p << "����" << b << "�����·������: " << dist[b] << endl;
						if (dist[b] != maxdist) {
							cout << "��" << p << "����" << b << "��·��Ϊ:";
							printpath(pre, p, b);
						}
						else {
							cout << "���ɴ" << endl;
						}
					}
					else {
						continue;
					}
				}
				system("pause");
			}
			int a, b;
			cout << "��������ʼ��:";
			cin >> a;
			cout << "��������ֹ��:";
			cin >> b;
			for (int i = 1; i <= b; ++i)
				dist[i] = maxdist;
			Dijkstra(b, a, dist, pre, d);
			cout << "��" << a << "����" << b << "�����·������: " << dist[b] << endl;
			if (dist[b] != maxdist) {
				cout << "��" << a << "����" << b << "��·��Ϊ:";
				printpath(pre, a, b);
			}
			else {
				cout << "���ɴ" << endl;
			}

			system("pause");
			break;
		};



		case 5:exit(0);  system("pause");
			break;

		}
	}
	else {
		cout << "�����������������" << endl;
	}

}