#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Trees.h"
#include "MinHeap.h"
#include "MaxHeap.h"

using namespace std;

vector<vector<string>> students_data() {
	vector<vector<string>> students;
	string n;

	ifstream file("students.txt");

	if (!file) {
        cout << "Error opening file." << std::endl;
        exit(1);
    }
	
	getline(file, n);

	for (int i = 0; i < stoi(n); i++) {
		vector<string> student;
		string line;
		getline(file, line);
		student.push_back(line);
		getline(file, line);
		student.push_back(line);
		getline(file, line);
		student.push_back(line);
		getline(file, line);
		student.push_back(line);
		students.push_back(student);
	}
	return students;
}


void LoadData(BST &bst)
{

    fstream file;
    cout << "Loading File...." << endl;
    if (!file)
    {
        cerr << "Error laoding the file\n";
        return;
    }

    file.open("students.txt", ios::in);

    string line;
    getline(file, line);
    string elements = line;
    // stoi(elements)
    for (int i = 0; i < 3 ; i++)
    {
        vector<string> v;
        string id, gpa, name, dep;
        getline(file, id);
        getline(file, name);
        getline(file, gpa);
        getline(file, dep);

        v.push_back(id);
        v.push_back(name);
        v.push_back(gpa);
        v.push_back(dep);

        // tree insertion 
        bst.insertStudent(v);
        //avl.insertStudent(v);

        // clearing to avoid duplicates
        v.clear();
    }

    file.close();
}


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
	cout << endl;
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


// void AVL_MENU()
// {
// 	AVL tree;
// 	int ID;
// 	vector<string> data;
// 	BTS_AVL_MENU();
// 	int choice;
// 	cin >> choice;
// 	while (true)
// 	{
// 		switch (choice)
// 		{
// 		case 1:
// 			data = ADD_STUDENT();
// 			tree.insertStudent(data);
// 			break;
// 		case 2:
// 			ID = TRANSFER_ID();
// 			tree.deleteStudent(ID);
// 			break;
// 		case 3:
// 			ID = TRANSFER_ID();
// 			tree.search(ID);
// 			break;
// 		case 4:
// 			break;
// 		case 5:
// 			return;
// 		default:
// 			LineBreak();
// 			cout << "Please Enter vaild number for operation";
// 			break;
// 		}
// 	}
// }

void minHeap() {
	vector<vector<string>> students = students_data();

	int choice;
	vector<string> student;
	
	while (true)
	{
		MIN_MAX_HEAP_MENU();
		cin >> choice;
		switch (choice)
		{
		case 1:
			student = ADD_STUDENT();
			add_student_minH(students, student);
			break;
		case 2:
			print_all_minH(students);
			break;
		case 3:
			return;
		default:
			LineBreak();
			cout << "Please Enter vaild number for operation";
			break;
		}
	}
}


void maxHeap() {
	vector<vector<string>> students = students_data();

	int choice;
	vector<string> student;
	
	while (true)
	{
		MIN_MAX_HEAP_MENU();
		cin >> choice;
		switch (choice)
		{
		case 1:
			student = ADD_STUDENT();
			add_student_maxH(students, student);
			break;
		case 2:
			print_all_maxH(students);
			break;
		case 3:
			return;
		default:
			LineBreak();
			cout << "Please Enter vaild number for operation";
			break;
		}
	}
}



