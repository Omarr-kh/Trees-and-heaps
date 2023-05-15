#include <iostream>
#include <string>
#include <vector>
#include "Trees.h"

using namespace std;
  


void LineBreak()
{
	cout << "==============================================================\n";
}

int TRANSFER_ID()
{
	LineBreak();
	int ID;
	cout << "Enter Student ID: ";
	cin >> ID;
	return ID;
}

vector<string> ADD_STUDENT()
{
	LineBreak();
	string id, name, gpa, dep;
	cout << "ID: ";
	cin >> id;
	cout << "Name:";
	cin >> name;
	cout << "GPA: ";
	cin >> gpa;
	cout << "Department: ";
	cin >> dep;
	vector<string> student_info = {id, name, gpa, dep};

	return student_info;
}


void menu()
{
	LineBreak();
	cout << "Choose Data Structure:\n";
	cout << "1. BST" << endl;
	cout << "2. AVL" << endl;
	cout << "3. Min Heap" << endl;
	cout << "4. Max Heap" << endl;
	cout << "5. Exit Program" << endl;
	cout << "Enter number of option: ";
}

void BTS_AVL_MENU()
{
	LineBreak();
	cout << "Choose one of the following options: " << endl;
	cout << "1. Add student" << endl;
	cout << "2. Remove student" << endl;
	cout << "3. Search student" << endl;
	cout << "4. Print All (sorted by id)" << endl;
	cout << "5. Return to main menu " << endl;
	cout << "Enter number of option: ";
}

void MIN_MAX_HEAP_MENU()
{
	LineBreak();
	cout << "Choose one of the following options:" << endl;
	cout << "1. Add student" << endl;
	cout << "2. Print All (sorted by gpa)" << endl;
	cout << "Enter number of option: ";
}

void BTS()
{
	BST tree;
	vector<string> data;
	int ID;
	BTS_AVL_MENU();
	int choice;
	cin >> choice;
	while (true)
	{
		switch (choice)
		{
		case 1:
			data = ADD_STUDENT();
			tree.insertStudent(data);
			break;
		case 2:
			ID = TRANSFER_ID();
			tree.deleteStudent(ID);
			break;
		case 3:
			ID = TRANSFER_ID();
			tree.search(ID);
			break;
		case 4:
			LineBreak();
			tree.inorderTraversal();
			break;
		case 5:
			return;
		default:
			LineBreak();
			cout << "Please Enter vaild number for operation";
			break;
		}
	}
}


void AVL_MENU()
{
	AVL tree;
	int ID;
	vector<string> data;
	BTS_AVL_MENU();
	int choice;
	cin >> choice;
	while (true)
	{
		switch (choice)
		{
		case 1:
			data = ADD_STUDENT();
			tree.insertStudent(data);
			break;
		case 2:
			ID = TRANSFER_ID();
			tree.deleteStudent(ID);
			break;
		case 3:
			ID = TRANSFER_ID();
			tree.search(ID);
			break;
		case 4:
			break;
		case 5:
			return;
		default:
			LineBreak();
			cout << "Please Enter vaild number for operation";
			break;
		}
	}
}





	// BST tree;
	// vector<string> item = {"1", "Mohamed Ali", "3.4", "CS"};
	// vector<string> item2 = {"2", "Mona Samir", "3.2", "IT"};
	// vector<string> item3 = {"3", "Ola Maher", "1.2", "CS"};
	// vector<string> item4 = {"4", "Magy Madgy", "2.3", "DS"};
	// vector<string> item5 = {"5", "Omnia Osama", "3.6", "IS"};
	// vector<string> item6 = {"6", "Ahmed Omar", "3.9", "CS"};
	// vector<string> item7 = {"7", "Mai Adel", "3.1", "IS"};
	// vector<string> item8 = {"8", "Mohamed Saleh", "2.4", "CS"};

	// tree.insertStudent(item3);
	// tree.insertStudent(item2);
	// tree.insertStudent(item);
	// tree.insertStudent(item7);
	// tree.insertStudent(item4);
	// tree.insertStudent(item6);
	// tree.insertStudent(item5);
	// tree.insertStudent(item8);

	// tree.deleteStudent(7);
	// tree.deleteStudent(2);
	// tree.deleteStudent(5);
	// tree.inorderTraversal();