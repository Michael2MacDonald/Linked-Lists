#include <iostream>
#include <cstring>
#include <cctype> // tolower

#include "student.h"
#include "list.h"

typedef List<Student> StudentList;
typedef Node<Student> StudentNode;

void add(StudentList *Students);
void del(StudentList *Students);
void print(StudentList *Students);


int main() {

	Student* tmp = new Student();
	*tmp = { .id = 123456, .firstName = "John", .lastName = "Doe", .gpa = 3.817 };
//	tmp->id = 1234;
//	tmp->firstName = "bob";
//	tmp->lastName = "joey";
//	tmp->gpa = 100.1;

	// List to hold all the students. List class is just a class that helps transverse nodes
	// Node class could be used without the List class but you will have to manually save the start node and transverse the node chain to do anything
	//StudentList *Students = new StudentList(new StudentNode(new Student()));
	StudentList *Students = new StudentList(tmp);
	
	
	while(1) {
		// This will produce and error or unexpected behavior if the user enters more than 9 characters
		// To fix this we would have to implement some sort of "string" class with operator overloading or something
		// Because this is not a production, we can just ignore this
		char input[10] = {}; // zero-init the entire array
		std::cout << "===============\nType A Command:\n";
		std::cin >> input;
		
		// to lower case
		for (int i = 0; i < std::strlen(input); i++) {
			input[i] = std::tolower(input[i]);
		}
		
		if (!strcmp(input, "add")) {
			add(Students);
		} else if (!strcmp(input, "del")) {
			del(Students);
		} else if (!strcmp(input, "print")) {
			print(Students);
		} else if (!strcmp(input, "quit")) {
			return 0;
		} else { std::cout << "ERROR: Incorrect Command\n"; }
		//} else { std::cout << "========================\nERROR: Incorrect Command\n========================\n"; }

	}
	
	
	//Student* bob = Students->getStart()->getData();
	//bob->id = 123;
	//std::cout << bob->id << '\n';
	
	return 0;
}


void add(StudentList *Students) {
	Student* student = new Student();
	
	// ID
	std::cout << "ID:\n";
	std::cin >> student->id;
	// First name
	char buf[128] = {};
	std::cout << "First Name:\n";
	//return;
	std::cin >> buf;
	char* firstName = (char*)malloc(strlen(buf)+1);
	strcpy(firstName, buf);
	student->firstName = firstName;
	// Last Name
	memset(buf, 0, strlen(buf)); // clear
	std::cout << "Last Name:\n";
	std::cin >> buf;
	char* lastName = (char*)malloc(strlen(buf)+1);
	strcpy(lastName, buf);
	student->lastName = lastName;
	// GPA
	std::cout << "GPA:\n";
	std::cin >> student->gpa;
	
	StudentNode* node = new StudentNode(student);
	Students->addNode(node);
}

void del(StudentList *Students) {
	int id = 0;
	std::cout << "Enter The ID Of The Student You Want To Thanos Snap:\n";
	std::cin >> id;
	//std::cout << id << '\n';
	
	for (int i=0; i<Students->size(); i++) {
		//std::cout << i << "\n";
		//std::cout << Students->getNode(i)->getData()->id << " == " << id << '\n';
		if (Students->getNode(i)->getData()->id == id) {
			Students->delNode(i);
			return;
		}
	}
	std::cout << "Student does not exist!\n";
}

void print(StudentList *Students) {
	if (Students->getStart() == nullptr) {
		std::cout << "- No Students -\n";
		return;
	}

	for (int i=0; i<Students->size(); i++) {
		StudentNode* node = (*Students)[i];
		Student* student = node->getData();
		
		std::cout << "-----------------------\n";
		std::cout << "ID: " << student->id << '\n';
		std::cout << "First Name: ";
		for (int i=0; i < strlen(student->firstName); i++) { std::cout << (student->firstName)[i]; }
		std::cout << '\n';
		std::cout << "Last Name: ";
		for (int i=0; i < strlen(student->lastName); i++) { std::cout << (student->lastName)[i]; }
		std::cout << '\n';
		std::cout << "GPA: " << student->gpa << '\n';
	}
}



//template class List<int>;


