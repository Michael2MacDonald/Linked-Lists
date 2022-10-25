#include "list.h"

template<typename T>
Node<T>::Node(T* data) {
	this->next = nullptr;
	this->data = data;
}

template<typename T>
Node<T>::~Node() {
	// Delete data (Call deconstructor, etc)
	delete *(this->data);
}

template<typename T>
Node<T>* Node<T>::getNext() {
	return this->next;
}

template<typename T>
void Node<T>::setNext(Node* node) {
	this->next = node;
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
	//this->start = new Node<NT>(data);
}

template<typename NT>
Node<NT>* List<NT>::operator[](int i) {
    Node<NT>* node;
    // Do stuff
	return node;
}

template<typename NT>
List<NT>::List() {
	
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
//int Node<T>::setNext(Node* node) {
//	// Check if the given node is already part of a list
//	if( node->start != node || node->end != node || node->next != nullptr ) {
//		return -1;
//	}
//	
//	*node->next = this->next;
//	this->next = node;
//	
//	*node->start = this->start;
//	if (this == this->end) {
//		*node->end = node;
//		this->setEnd(node);
//	} else {
//		*node->end = this->end;
//	}
//	
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


