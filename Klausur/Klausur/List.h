#pragma once
#include<iostream>

class Node {
public:
	int key;
	Node* next;
	Node(int key) {
		this->key = key;
		next = nullptr;
	}
};

class Liste {

public:
	Node* head;
	Liste() { 
		head = new Node(-1);		
	}

	void add(int item) {
		Node* newitem = new Node(item);
		
		Node* ptr = head;
		while (ptr->next != nullptr)
			ptr = ptr->next;

		ptr->next = newitem;
		
		
	}
	

	Node* prev(Node* p) {

		Node* ptr = head;
		while (ptr->next != p)
			ptr = ptr->next;

		return ptr;
	}

	void swap(Node* p1, Node* p2) {

		if (!p1 || !p2)
			return;
		// Annahme : p1 kommt vor p2 in die Liste!
		// sonst
		
		if (p2->next == p1) {
			Node* tmp = p1;
			p1 = p2;
			p2 = tmp;
		}

		Node* p1prev = prev(p1);
		Node* p2prev = prev(p2);

		p1prev->next = p2;
		p2prev->next = p1;

		Node* tmp = p2->next;

		p2->next = p1->next;
		p1->next = tmp;
		
		
	}

	Node* search(int item) {
		Node* search = head->next;
		while (search && search->key != item)
			search = search->next;

		return search;
	}
};