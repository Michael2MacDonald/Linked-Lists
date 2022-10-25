#include "list.h"
#include "student.h"

// Required for compiler to know to build versions of the methods with the student type
template class Node<Student>;
template class List<Student>;


template<typename T>
Node<T>::Node(T* data) {
	this->next = nullptr;
	this->data = data;
}

template<typename T>
Node<T>::~Node() {
	// Delete data (Call deconstructor, etc)
	delete this->data;
}

template<typename T>
Node<T>* Node<T>::getNext() {
	return this->next;
}

template<typename T>
void Node<T>::setNext(Node* node) {
	this->next = node;
}

template<typename T>
T* Node<T>::getData() {
	return this->data;
}


/////////////////////////////
/////////// LIST ////////////
/////////////////////////////

template<typename NT>
List<NT>::List(Node<NT>* node) {
	this->start = node;
}

template<typename NT>
List<NT>::List(NT* data) {
	this->start = new Node<NT>(data);
}

template<typename NT>
Node<NT>* List<NT>::getNode(int i) {
	Node<NT>* node = this->start;
	for (int j=0; j<i; j++) {
		if (node->getNext() == nullptr) {
			// error
			return nullptr;
		} else {
			node = node->getNext();
		}
	}
	return node;
}

template<typename NT>
Node<NT>* List<NT>::getStart() {
	return this->start;
}

template<typename NT>
Node<NT>* List<NT>::getEnd() {
	Node<NT> *node = this->start;
	while(1) {
		if (node->getNext() == nullptr) {
			return node;
		} else { node = node->getNext(); }
	}
}

template<typename NT>
int List<NT>::size() {
	int i = 1;
	Node<NT> *node = this->start;
	while(1) {
		if (node->getNext() == nullptr) {
			return i;
		} else {
			node = node->getNext();
			i++;
		}
	}
}

template<typename NT>
Node<NT>* List<NT>::operator[](int i) {
    return this->getNode(i);
}

template<typename NT>
void List<NT>::addNode(Node<NT>* node) {
	// Check if the given node is already part of a list
	// This does not work in the node is at the end of a list
	// We need to implement a 'previous' or 'start' varuable so the entire list can be found from any node
	if (node->getNext() != nullptr) return;
	
	// Check if the list is empty
	if (this->start == nullptr) {
		this->start = node; // Make the node the first node
	} else {
		Node<NT>* end = this->getEnd(); // get the last node
		end->setNext(node); // append the node to the last node
	}
}

template<typename NT>
void List<NT>::delNode(int i) {
	// Get the node to delete
	Node<NT>* node = this->getNode(i);
	
	// Check if the node is the start node
	if (i == 0) this->start = node->getNext(); // set new start
	// Set the previous node's 'next' to this node's 'next' to remove this node from the chain
	else this->getNode(i-1)->setNext( node->getNext() );
	
	delete node; // delete!!!!
}

//Node<NT>

//template<typename T>
//Node<T>::~Node() {
//	// Delete data (Call deconstructor, etc)
//	delete *(this->data);
//	
//	// If this is the only node in the list, no need to do anything
//	if (this->start == this && this->end == this) return;
//
//	Node* tmp = this->start;
//	while (tmp->next != this) {
//		tmp = tmp->next;
//	}
//	tmp->next = this->next;
//	//this->~Node();
//}


//template<typename T>
//int Node<T>::setEnd(Node* node) {
//	if (this->next != node) {
//		return -1; // ERROR: This function assumes that 
//	}
//
//	for (Node* curr = this->start; curr != node; curr = curr->next) {
//		*curr->end = node;
//	}
//	return 0;
//}


//template<typename T>
//void Node<T>::destroyList() {
//	Node* cur = this;
//	Node* nxt = this->next;
//	
//	while (this->end != cur) {
//		cur->~Node();
//		cur = nxt;
//		nxt = cur->next;
//	}
//	cur->~Node();
//}


