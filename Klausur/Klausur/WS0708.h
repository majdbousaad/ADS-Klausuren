#pragma once
#include <vector>
#include <iostream> 
#include <queue>
#include <stack>
#include <map>

class Node3
{
public:
	int item;
	std::vector<Node3*> nachfolger;

	Node3(int item) : item(item) { this->nachfolger.resize(3, nullptr); };

};

class Baum3
{
public:

	Node3* wurzel;

	Baum3() :wurzel(nullptr) {}
	void preOrderRek(Node3* node) {
		if (!node)
			return;
		std::cout << node->item << " ";
		for (int i = 0; i < 3; i++)
		{
			preOrderRek(node->nachfolger[i]);
		}
	}

	void preOrderIte() {

		std::stack<Node3*> stack;

		if (wurzel)
			stack.push(wurzel);

		Node3* node;
		while (!stack.empty())
		{
			node = stack.top();
			stack.pop();

			std::cout << node->item << " ";

			for (int i = 2; i >= 0; i--)
			{
				if (node->nachfolger[i])
					stack.push(node->nachfolger[i]);
			}
		}
	}

	// Nur zum Testen. addNode() fügt einen Knoten in LevelOrder hinzu, daher das Queue
	void addNode(int item) {
		Node3 *newNode = new Node3(item);

		if (!wurzel)
			wurzel = newNode;
		else
		{
			std::queue<Node3*> queue;

			queue.push(wurzel);

			Node3* tmp;
			bool done = false;
			while (!queue.empty() && !done)
			{
				tmp = queue.front();
				queue.pop();

				for (int i = 0; i < 3; i++)
				{
					if (tmp->nachfolger[i] == nullptr) {
						tmp->nachfolger[i] = newNode;
						done = true;
						break;
					}
					else
					{
						queue.push(tmp->nachfolger[i]);
					}
				}
			}
		}
		
	}
};

std::map<int, std::vector<int>> getAdjanzenzList(std::vector<int> nodelist) {
	
	
	std::map<int, std::vector<int>> result;
	int resultIndex = 1;

	for (int i = 2; i < nodelist.size() - 1; i += nodelist[i] + 1)
	{
		for (int k = i + 1; k <= i + nodelist[i]; k++)
		{
			result[resultIndex].push_back(nodelist[k]);
		}
		resultIndex++;
	}

	return result;

}



