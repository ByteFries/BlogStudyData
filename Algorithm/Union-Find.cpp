#include <iostream>
#include <vector>

using namespace std;

vector<int> parents; // 부모 노드
vector<int> ranks;   // 속한 집합의 랭크


int Find(int node)
{
	// 루트 노드가 같으면 true
	if (parents[node] == node) return node;
	return parents[node] = Find(parents[node]); //경로 압축
}

void Union(int node1, int node2)
{
	// 랭크 높은 애가 루트

	int root1 = Find(node1);
	int root2 = Find(node2);

	if (ranks[root1] == ranks[root2])
	{
		parents[root2] = parents[root1];
		ranks[root1]++;
	}
	else if (ranks[root1] < ranks[root2])
	{
		parents[root1] = parents[root2];
	}
	else
	{
		parents[root2] = parents[root1];
	}
}

vector<bool> Solution(int k, vector<vector<char>> operations)
{
	parents.resize(k);
	ranks.resize(k);

	for (int i = 0; i < k; i++) parents[i] = i;

	vector<bool> result;

	for (const auto& operation : operations)
	{
		int node1 = operation[1] - '0';
		int node2 = operation[2] - '0';
		if (operation[0] == 'u')
		{
			Union(node1, node2);
		}
		else if (operation[0] == 'f')
		{
			result.push_back(Find(node1) == Find(node2));
		}
	}

	return result;
}
