#include "DoublyLinkedList.h"
#include <iostream>
using namespace doubly;
//----------------------------------------------------------Node
Node::Node(int _value, Node* _next,Node* _prev) {
	value = _value;
	next = _next;
	prev = _prev;
}
Node::~Node() {
}
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
void Node::setPrevNode(Node* _prev) {
	prev = _prev;
}
Node* Node::getPrevNode() const {
	return prev;
}
//----------------------------------------------------------DoublyLinkedList
DoublyLinkedList::DoublyLinkedList() {
	Head = nullptr;
	Tail = nullptr;
}
DoublyLinkedList::~DoublyLinkedList() {
	clear();
}
Node* DoublyLinkedList::createNode(int _value) {
	Node* newNode = new Node(_value);
	return newNode;
	}
void DoublyLinkedList::pushFront(int _value) {
	Node* temp = createNode(_value);
	if (Head == nullptr) {
		Head = temp;
		Tail = temp;
	}else
	{
		Head->setPrevNode(temp);
		temp->setNextNode(Head);
		Head = temp;
	}
}
void DoublyLinkedList::pushBack(int _value) {
	Node* temp = createNode(_value);
	if (Head == nullptr) {
		Head = temp;
		Tail = temp;
	}
	else {
		Tail->setNextNode(temp);
		temp->setPrevNode(Tail);
		Tail = temp;
	}
}
void DoublyLinkedList::insertAt(int _value, int index) {
	Node* helper = Head;
	int current = 1;
	if (Head == nullptr || index <= 1) {
		pushFront(_value);
		return;
	}else {
		while (helper->getNextNode() != nullptr && current < index) {
			helper = helper->getNextNode();
			current++;
		}
		if (helper ->getNextNode() == nullptr && current < index) {
			pushBack(_value);
			return;
		}
		Node* temp = createNode(_value);
		temp->setPrevNode(helper->getPrevNode());
		temp->setNextNode(helper);
		helper->getPrevNode()->setNextNode(temp);
		helper->setPrevNode(temp);
	}
}
void DoublyLinkedList::popFront() {
	if (Head == nullptr) return;
	if (Head == Tail) {
		delete Head;
		Head = nullptr;
		Tail = nullptr;
	}
	else {
		Head = Head->getNextNode();
		delete Head->getPrevNode();
		Head->setPrevNode(nullptr);
	}
}
void DoublyLinkedList::popBack() {
	if (Head == nullptr) return;
	if (Head == Tail) {
		delete Head;
		Head = nullptr;
		Tail = nullptr;
	}
	else {
		Tail = Tail->getPrevNode();
		delete Tail->getNextNode();
		Tail->setNextNode(nullptr);
	}
}
void DoublyLinkedList::removeAt(int index) {
	Node* helper = Head;
	int current = 1;
	if (Head == nullptr || index <= 1) {
		popFront();
		return;
	}
	else {
		while (helper->getNextNode() != nullptr && current < index) {
			helper = helper->getNextNode();
			current++;
		}
		if (helper->getNextNode() == nullptr && current <= index) {//(helper == tail)
			popBack();
			return;
		}
		helper->getPrevNode()->setNextNode(helper->getNextNode());
		helper->getNextNode()->setPrevNode(helper->getPrevNode());
		delete helper;
	}
}
void DoublyLinkedList::clear() {
	while (Head != nullptr) {
		popBack();
	}
}
void DoublyLinkedList::print() {
	Node* temp = Head;
	while (temp !=nullptr)
	{
		std::cout << temp->getValue() << "\t";
		temp = temp->getNextNode();
	}
	std::cout << std::endl;
}