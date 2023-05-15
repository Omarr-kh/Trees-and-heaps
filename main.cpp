// Assignment3_DS.cpp : Defines the entry point for the application.
//

#include "Trees.h"
#include "menu.h"
// #include "MinHeap.h"
#include "MaxHeap.h"
#include <fstream>

using namespace std;

// void display_menu();

int main()
{
	vector<vector<string>> students;
	string n;

	ifstream file("students.txt");

	if (!file) {
        cout << "Error opening file." << std::endl;
        return 1;
    }
	
	getline(file, n);

	for (int i = 0; i < stoi(n) + 1; i++) {
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

	vector<vector<string>> min_heap_students = build_max_heap(students);
	vector<string> student = {"12", "omar", "3.5", "CS"};
	add_student_maxH(min_heap_students, student);

	max_heap_sort(min_heap_students);

	for (int i = 0; i < min_heap_students.size(); i++)
	{
		for (int j = 0; j < 4; j++) {
			cout << min_heap_students[i][j] << ", ";
		}
		cout << endl;
	}

}















// void display_menu() {
// 	vector<vector<string>> students;
// 	string n;

// 	ifstream file("students.txt");

// 	if (!file) {
//         cout << "Error opening file." << std::endl;
//         return;
//     }
	
// 	getline(file, n);

// 	for (int i = 0; i < stoi(n); i++) {
// 		vector<string> student;
// 		string line;
// 		getline(file, line);
// 		student.push_back(line);
// 		getline(file, line);
// 		student.push_back(line);
// 		getline(file, line);
// 		student.push_back(line);
// 		getline(file, line);
// 		student.push_back(line);
// 		students.push_back(student);
// 	}

// 	int choice;
// 	cout << "Choose Data Structure:\n";
// 	cout << "1. BST" << endl;
// 	cout << "2. AVL" << endl;
// 	cout << "3. Min Heap" << endl;
// 	cout << "4. Max Heap" << endl;
// 	cout << "5. Exit Program" << endl;
	
// 	cin >> choice;
// 	switch(choice) {
// 		case 1:
// 			// BST
// 			BST tree;
// 			for (vector<string> student: students) {
// 				break;
// 			}
// 			break;
// 		case 2:
// 			// AVT
// 			break;
// 		case 3:
// 			// min heap
// 			break;
// 		case 4:
// 			// max heap
// 			break;
// 		case 5:
// 			// exit
// 			return;
// 		default:
// 			cout << "invalid choice\n";
// 			break;
// 	}
// }
