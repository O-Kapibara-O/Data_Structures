#pragma once

namespace doubly {

	class Node {
	private:
		int value;
		Node* next;
		Node* prev;
	public:
		Node(int value, Node* next = nullptr, Node* prev = nullptr);
		~Node();
		void setValue(int _value);
		int getValue() const;
		void setNextNode(Node* _next);
		Node* getNextNode() const;
		void setPrevNode(Node* _prev);
		Node* getPrevNode() const;
	};

	class DoublyLinkedList
	{
	private:
		Node* Head;
		Node* Tail;
		Node* createNode(int _value);
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		void pushFront(int _value);
		void pushBack(int _value);
		void insertAt(int _value,int index);
		void popFront();
		void popBack();
		void removeAt(int index);
		void print();
		void clear();
	};
}
