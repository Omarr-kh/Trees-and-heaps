#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Min-Heapify
// build-Min_Heap

void min_heapify(vector<vector<string>>& students, int i, int n) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && stoi(students[left][0]) < stoi(students[smallest][0])) {
        smallest = left;
    }
    if (right < n && stoi(students[right][0]) < stoi(students[smallest][0])) {
        smallest = right;
    }

    if (smallest != i) {
        swap(students[smallest], students[i]);

        min_heapify(students, smallest, n);
    }
}

vector<vector<string>> build_min_heap(vector<vector<string>> students) {
    int n = students.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        min_heapify(students, i, n);
    }
    return students;
}


void min_heap_sort(vector<vector<string>>& students) {
    // [1, 3, 2, 7, 4, 5, 6, 11, 8, 9, 10]
    int n = students.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        min_heapify(students, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(students[i], students[0]);
        min_heapify(students, 0, i);
    }

    reverse(students.begin(), students.end());
}

