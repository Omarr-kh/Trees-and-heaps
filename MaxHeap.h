#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void max_heapify(vector<vector<string>>& students, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && stoi(students[left][0]) > stoi(students[largest][0])) {
        largest = left;
    }
    if (right < n && stoi(students[right][0]) > stoi(students[largest][0])) {
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

    for (int i = n - 1; i > 0; --i) {
        swap(students[i], students[0]);

        max_heapify(students, 0, i);
    }
}
