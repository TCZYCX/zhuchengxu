#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "dijkstra.h"
using namespace std;

const int maxdist = 9999;


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
		for (int i = 2; i <= n; i++)//�ܵĵ�������
		{
			int best = v;
			int temp = maxdist;
			for (int j = 1; j <= n; j++)//�ҵ���С�ľ���
			{
				if (!s[j] && dist[j] < temp)
				{
					temp = dist[j];
					best = j;
				}
			}
			s[best] = true;
			for (int j = 1; j <= n; j++)//����dist��pre
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
			dist[i] = d[v][i];//����ǰ��㵽ÿһ�����ľ���
			if (dist[i] < maxdist)
				pre[i] = v;
			else
				pre[i] = 0;
		}
		dist[v] = 0;
		s[v] = true;
		for (int i = 2; i <= v; i++)//�ܵĵ�������
		{
			int best = n;
			int temp = maxdist;
			for (int j = 1; j <= v; j++)//�ҵ���С�ľ���
			{
				if (!s[j] && dist[j] < temp)
				{
					temp = dist[j];
					best = j;
				}
			}
			s[best] = true;
			for (int j = 1; j <= v; j++)//����dist��pre
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
