#ifndef LIST_H
#define LIST_H


/**
 * The CPU no longer overheats when you hold down the spacebar
 * https://xkcd.com/1172/
 */


template<typename T> class Node {
private:
	Node* next;
	T* data;
	
public:
	// Create node ('next' will equal 'nullptr')
	Node(T*); // Create node with provided data
	~Node(); // Destroy node and node data
	
	Node* getNext(); // Get pointer of next node
	void setNext(Node*); // Set the 'next' pointer of node
	
	T* getData(); // Get void pointer to node data
};


template<typename NT>
class List {
private:
	Node<NT>* start;
public:
	List(Node<NT>*); // Create list and set start node
	List(NT*); // Create List and create new start node with provided data
	~List(); // Delete list and all nodes
	
	Node<NT>* getNode(int); // Get node pointer by index
	Node<NT>* getStart(); // Get node pointer for the start node
	Node<NT>* getEnd(); // Get node pointer for the end node
	
	int size(); // get size
	
	void addNode(Node<NT>*); // Add node to end of list
	void delNode(int i); // Delete node at index i
	
	// Overloading [] operator to access elements in array style
	Node<NT>* operator[](int);	
};

// ===== IMPORTANT =====
// Required for compiler to know to build versions of the methods with the student type

#include "student.h" // change "student.h" to the header file that contains your student class
template class Node<Student>; // change "Student" to the name of your student class
template class List<Student>; // change "Student" to the name of your student class



#endif /* LIST_H */