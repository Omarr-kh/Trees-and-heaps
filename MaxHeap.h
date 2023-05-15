#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void max_heapify(vector<vector<string>>& students, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && stod(students[left][2]) > stod(students[largest][2])) {
        largest = left;
    }
    if (right < n && stod(students[right][2]) > stod(students[largest][2])) {
        largest = right;
    }

    if (largest != i) {
        swap(students[largest], students[i]);

        max_heapify(students, largest, n);
    }
}

vector<vector<string>> build_max_heap(vector<vector<string>> students) {
    int n = students.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        max_heapify(students, i, n);
    }
    return students;
}

void max_heap_sort(vector<vector<string>>& students) {
    int n = students.size();

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        max_heapify(students, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(students[i], students[0]);

        max_heapify(students, 0, i);
    }
}

void add_student_maxH(vector<vector<string>>& students, vector<string> student) {
    students.push_back(student);
    max_heapify(students, students.size() - 1, students.size());
}

void print_all_maxH(vector<vector<string>>& students) {
    max_heap_sort(students);

    for (int i = students.size() - 1; i >= 0; --i) {
        cout << "[";
        for (int j = 0; j < 4; j++) {
            cout << students[i][j];

            if (j != 3)
                cout << ", ";
        }
        cout << "]\n";
    }

}
