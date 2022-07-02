#include "WS0708.h"

#include<iostream>
#include "List.h"

using namespace std;

void SelectionSort(Liste& unsorted) {
	Node* start = unsorted.head->next;

	if (!start)
		return;

	Node* min; // 2 2 3 4 5
	for (Node* travel = start; travel != nullptr; travel = travel->next) {
		min = travel;
		for (Node* find_min = travel->next; find_min != nullptr; find_min = find_min->next) {
			if (find_min->key < min->key)
				min = find_min;
		}
		unsorted.swap(travel, min);
		travel = min;

	}
}

int main() {

	/*
	ADS_Klausur_WS0708_LÖSUNG
	*/
	cout << "ADS_Klausur_WS0708_LOESUNG" << endl;
	// Test Aufgabe 2
	{
	Baum3 baum;

	for (int i = 0; i < 10; i++)
	{
		baum.addNode(i);
	}
	baum.preOrderRek(baum.wurzel);

	cout << endl;

	baum.preOrderIte();

	cout << endl;
	}

	// Test Aufgabe 3d
	{
		vector<int> nodelist{ 6, 8, 3, 2, 3, 4, 2, 1, 4, 3, 1, 4, 5, 4, 1, 2, 3, 5, 2, 3, 4, 1, 4 };

		map<int, vector<int>> result = getAdjanzenzList(nodelist);
		for (int i = 1; i <= result.size(); i++)
		{
			cout << i << " -> ";
			for (int element : result[i])
			{
				cout << element << " ";
			}
			cout << endl;
		}

	}

	/*
	ADS_Klausur10_B2a_LÖSUNG
	*/

	cout << "ADS_Klausur10_B2a_LOESUNG" << endl;
	// Test Aufgabe 6d
	{
		vector<int> nodelist{ 10, 16, 3, 2, 3, 4, 2, 1, 3, 5, 1, 2, 5, 6, 7, 3, 1, 6, 7, 3, 3, 9, 10, 3, 3, 4, 8, 4, 3, 4, 8, 9, 3, 6, 7, 10, 3, 5, 7, 10, 3, 5, 8, 9 };

		map<int, vector<int>> result = getAdjanzenzList(nodelist);
		for (int i = 1; i <= result.size(); i++)
		{
			cout << i << " -> ";
			for (int element : result[i])
			{
				cout << element << " ";
			}
			cout << endl;
		}

	}

	// ADS_Klausur17_Test
	Liste L;
	L.add(5);
	L.add(4);
	L.add(3);
	L.add(3);
	L.add(2);
	L.add(1);

	SelectionSort(L);

	for (Node* i = L.head->next; i != nullptr; i = i->next)
	{
		cout << i->key << " ";
	}
	cout << endl;

	cout << "==========================" << endl;

	system("PAUSE");
	return 0;
}