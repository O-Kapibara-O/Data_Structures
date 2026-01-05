#pragma once

namespace singly {
	class Node {
	private:
		int value;
		Node* next;
	public:
		Node(int value, Node* next = nullptr);
		~Node();
		void setValue(int _value);
		int getValue() const;
		void setNextNode(Node* _next);
		Node* getNextNode() const;
	};

	class Linked_List
	{
	private:
		singly::Node* Head;
		singly::Node* createNewNode(int _value);
	public:
		Linked_List();
		~Linked_List();
		Linked_List(const Linked_List& source);
		Linked_List& operator=(const Linked_List& source);
		void push_front(int _value);
		void push_back(int _value);
		void pop_front();
		void pop_back();
		void show_list();
		void clear_list();
	};
}
