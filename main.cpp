// Assignment3_DS.cpp : Defines the entry point for the application.
//

#include "Trees.h"

using namespace std;

int main()
{
	BST tree;
	vector<string> item = { "1", "Mohamed Ali", "3.4", "CS" };
	vector<string> item2 = { "2", "Mona Samir", "3.2", "IT" };
	vector<string> item3 = { "3", "Ola Maher", "1.2", "CS" };
	vector<string> item4 = { "4", "Magy Madgy", "2.3", "DS" };
	vector<string> item5 = { "5", "Omnia Osama", "3.6", "IS" };
	vector<string> item6 = { "6", "Ahmed Omar", "3.9", "CS" };
	vector<string> item7 = { "7", "Mai Adel", "3.1", "IS" };
	vector<string> item8 = { "8", "Mohamed Saleh", "2.4", "CS" };

	tree.insertStudent(item3);
	tree.insertStudent(item2);
	tree.insertStudent(item);
	tree.insertStudent(item7);
	tree.insertStudent(item4);
	tree.insertStudent(item6);
	tree.insertStudent(item5);
	tree.insertStudent(item8);

	tree.deleteStudent(7);
	tree.deleteStudent(2);
	tree.deleteStudent(5);
	tree.inorderTraversal();

}
