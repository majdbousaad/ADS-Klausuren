#pragma once
#include<iostream>

class DoubleNode
{
public:
	int key;
	DoubleNode* next;
	DoubleNode* prev;

	DoubleNode(int key) {
		this->key = key;
		next = nullptr;
		prev = nullptr;
	}
};

class DoubleList {



public:
	DoubleNode* head;
	DoubleNode* tail;


	DoubleList() {
		head = new DoubleNode(-1);
		head->next = tail;
		tail = new DoubleNode(-1);
		tail->prev = head;
	}

	void add(int item) {
		DoubleNode* newitem = new DoubleNode(item);
		
		newitem->prev = tail->prev;
		tail->prev->next = newitem;
		

		newitem->next = tail;
		tail->prev = newitem;
		
		


	}
	DoubleNode* search(int item) {
		DoubleNode* search = head->next;
		while (search != tail && search->key != item)
			search = search->next;
		if (search == tail)
			return nullptr;
		return search;
	}

	DoubleNode* prev(DoubleNode* p) {
		

		return p->prev;
	}

	void swap(DoubleNode* p1, DoubleNode* p2) {

		// Annahme : p1 kommt vor p2 in die Liste!
		// sonst

		if (p2->next == p1) {
			DoubleNode* tmp = p1;
			p1 = p2;
			p2 = tmp;
		}

		DoubleNode* p1prev = p1->prev;
		DoubleNode* p2prev = p2->prev;

		

		p1prev->next = p2;
		p2->prev = p1prev;

		p2prev->next = p1;
		p1->prev = p2prev;

		DoubleNode* tmp = p2->next;
		p2->next = p1->next;
		p1->next->prev = p2;

		p1->next = tmp;
		tmp->prev = p1;

	}
};