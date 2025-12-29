#include <iostream>
#include <queue>
#include "Linked_List.h"

using namespace singly;
//----------------------------------------------------------Node
Node::Node(int _value, Node* _next) {
	value = _value;
	next = _next;
}
Node::~Node() {
};
void Node::setValue(int _value) {
	value = _value;
}
int Node::getValue() const {
	return value;
}
void Node::setNextNode(Node* _next) {
	next = _next;
}
Node* Node::getNextNode() const {
	return next;
}
//----------------------------------------------------------Linked_List
Linked_List::Linked_List() {
	Head = nullptr;
}
Linked_List::~Linked_List() {
	clear_list();
};
Node* Linked_List::createNewNode(int _value) {
	Node* newNode = new Node(_value);
	return newNode;
}
void Linked_List::push_front(int _value) {
	if (Head == nullptr) {
		Head = createNewNode(_value);
	}
	else {
		Node* temp = createNewNode(_value);
		temp->setNextNode(Head);
		Head = temp;
	}
}
void Linked_List::push_back(int _value) {
	if (Head == nullptr) {
		Head = createNewNode(_value);
	}
	else {
		Node* temp = Head;
		while (temp->getNextNode() != nullptr) {
			temp = temp->getNextNode();
		}
		temp->setNextNode(createNewNode(_value));
	}
}
void Linked_List::pop_front() {
	if (Head != nullptr) {
		Node* temp = Head;
		Head = Head->getNextNode();
		delete temp;
	}
}
void Linked_List::pop_back() {
	if (Head == nullptr) {
		return;
	}
	if (Head->getNextNode() == nullptr) {
		delete Head;
		Head = nullptr;
		return;
	}
	Node* temp = Head;
	while (temp->getNextNode()->getNextNode() != nullptr) {
		temp = temp->getNextNode();
	}
	delete temp->getNextNode();
	temp->setNextNode(nullptr);
}
void Linked_List::show_list() {
	Node* temp = Head;
	while (temp != nullptr) {
		std::cout << temp->getValue() << "\t";
		temp = temp->getNextNode();
	}
	std::cout << std::endl;
}
void Linked_List::clear_list() {
	while (Head != nullptr)
	{
		pop_front();
	}
}