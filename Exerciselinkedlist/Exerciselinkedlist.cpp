#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode(int rollNumber) {
		Node* new_node = new Node();
		new_node->rollNumber = rollNumber;

		if (LAST == NULL) {
			LAST = new_node;
			new_node->next = LAST;
		}
		else if (rollNumber < LAST->rollNumber) {
			Node* current = LAST->next;
			Node* previous = NULL;
			while (current->rollNumber < rollNumber && current != LAST) {
				previous = current;
				current = current->next;
			}
			new_node->next = current;
			previous->next = new_node;
		}
		else {
			new_node->next = LAST->next;
			LAST->next = new_node;
			LAST = new_node;
		}
	}

	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode(int rollNumber) {
		if (LAST == NULL) {
			return;
		}

		Node* current = LAST->next;
		Node* previous = NULL;

		if (current->rollNumber == rollNumber) {
			if (current->next == current) {
				LAST = NULL;
				delete current;
				return;
			}
			else {
				LAST->next = current->next;
				delete current;
				return;
			}
		}

		while (current->rollNumber != rollNumber && current != LAST) {
			previous = current;
			current = current->next;
		}

		if (current == LAST) {
			previous->next = current->next;
			LAST = previous;
		}
		else {
			previous = LAST;
			while (previous->next != current) {
				previous = previous->next;
			}
			previous->next = current->next;
		}

		delete current;
	}
};
	void traverse() {
		if
};
void CircularLinkedList::addNode(int rollNumber) { //write your answer here
	
}
bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {