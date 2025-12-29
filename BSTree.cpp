#include <iostream>
#include <queue>

#include "BSTree.h"

using namespace BinarySearchTree;

std::ostream& operator<<(std::ostream& os, const std::optional<int>& opt) {
	if (opt.has_value()) os << *opt;
	else
		os << "Its empty";
	return os;
}

Node::Node(int _value, Node* _leftChild, Node* _rightChild) {
	value = _value;
	leftChild = _leftChild;
	rightChild = _rightChild;
}
Node::~Node() {};
void Node::setValue(int _value) {
	value = _value;
}
int Node::getValue() const {
	return value;
}
void Node::setRightChild(Node* _rightChild) {
	rightChild = _rightChild;
}
Node* Node::getRightChild() const {
	return rightChild;
}
void Node::setLeftChild(Node* _leftChild) {
	leftChild = _leftChild;
}
Node* Node::getLeftChild() const {
	return leftChild;
}
//---------------------------------------------------------
BSTree::BSTree() {
	root = nullptr;
}
BSTree::~BSTree() {
}

Node* BSTree::createNode(int _value) {
	Node* newNode = new Node(_value);
	return newNode;
}
Node* BSTree::insert(Node* node,int _value) {
	if (node == nullptr) {
		return createNode(_value);
	}
	else {
		if (node->getValue() < _value) {
			node->setRightChild(insert(node->getRightChild(), _value));
		}else if (node->getValue() > _value) {
			node->setLeftChild(insert(node->getLeftChild(),_value));
		}
		return node;
	}
}
void BSTree::insert(int value) {
	root = insert(root, value);
}

bool BSTree::search(Node* node, int searchValue) {
	if (node == nullptr) return false;
	if (node->getValue() == searchValue) return true;
	if (node->getValue() < searchValue) {
		return search(node->getRightChild(), searchValue);
	}
	else{
		return search(node->getLeftChild(), searchValue);
	}
}
bool BSTree::search(int value) {
	return search(root, value);
}

Node* BSTree::remove(Node* node, int _value) {
	if (node == nullptr) return node;
	if (node->getValue() > _value) {
		node->setLeftChild(remove(node->getLeftChild(), _value));
	}
	else if (node->getValue() < _value) {
		node->setRightChild(remove(node->getRightChild(), _value));
	}
	else {
		if (node->getLeftChild() == nullptr) {
			Node* temp = node->getRightChild();
			delete node;
			return temp;
		}
		if (node->getRightChild() == nullptr) {
			Node* temp = node->getLeftChild();
			delete node;
			return temp;
		}
		Node* next = node;
		next = next->getRightChild();
		while (next != nullptr && next->getLeftChild() != nullptr) {
			next = next->getLeftChild();
		}
		node->setValue(next->getValue());
		node->setRightChild(remove(node->getRightChild(), next->getValue()));
	}
	return node;
}
void BSTree::remove(int value) {
	root = remove(root, value);
}

Node* BSTree::minimum(Node*node) {
	if (node == nullptr) return nullptr;
	if (node->getLeftChild() == nullptr)return node;
	return minimum(node->getLeftChild());
}
std::optional<int> BSTree::minimum() {
	Node* minNode = minimum(root);
	if (minNode != nullptr)  return minNode->getValue();
	return std::nullopt;
}
Node* BSTree::maximum(Node* node) {
	if (node == nullptr) return nullptr;
	if (node->getRightChild() == nullptr)return node;
	return maximum(node->getRightChild());
}
std::optional<int> BSTree::maximum() {
	Node* maxNode = maximum(root);
	if (maxNode != nullptr)  return maxNode->getValue();
	return std::nullopt; 
}
void BSTree::inorder(Node* node) {

	if (node == nullptr) return;
	inorder(node->getLeftChild());
	std::cout << node->getValue() << "\t";
	inorder(node->getRightChild());

}
void BSTree::preorder(Node* node) {

	if (node == nullptr) return;
	std::cout << node->getValue() << std::endl;
	preorder(node->getLeftChild());
	preorder(node->getRightChild());

}
void BSTree::postorder(Node* node) {

	if (node == nullptr) return;
	postorder(node->getLeftChild());
	postorder(node->getRightChild());
	std::cout << node->getValue() << std::endl;
}
void BSTree::preorder() {
	preorder(root);
}
void BSTree::inorder() {
	inorder(root);
}
void BSTree::postorder() {
	postorder(root);
}

void BSTree::bfs (Node* node){
	if (node == nullptr) return;
	std::queue<Node *> queue;
	queue.push(node);
	while (!queue.empty()) {

		std::cout << queue.front()->getValue() << "\t";

		if (queue.front()->getLeftChild() != nullptr) {
			queue.push(queue.front()->getLeftChild());
		}
		if (queue.front()->getRightChild() != nullptr) {
			queue.push(queue.front()->getRightChild());
		}
		queue.pop();
	}
	std::cout << std::endl;
}
void BSTree::bfs() {
	bfs(root);
}
void BSTree::printTree(Node* node,int space,int indent) {
	if (node == nullptr)return;
	space = space + indent;
	printTree(node->getRightChild(), space);
	std::cout << std::endl;
	for (int i = indent; i < space; i++) {
		std::cout << " ";
	}
	std::cout << node->getValue() << std::endl;
	printTree(node->getLeftChild(), space);
}
void BSTree::printTree() {
	printTree(root);
}
