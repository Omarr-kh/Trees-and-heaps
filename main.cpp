// Assignment3_DS.cpp : Defines the entry point for the application.
//

#include "Trees.h"
#include "menu.h"
#include "MinHeap.h"
#include "MaxHeap.h"
#include <fstream>

using namespace std;

int main()
{
	cout << "Welcome to Student Information Control System\n";
    while (true)
    {
        int choice = 0;
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            BTS();
            break;
        case 2:
            //AVL_MENU();
            break;
        case 3:
            minHeap();
            break;
        case 4:
            maxHeap();
            break;
        case 5:
            cout << "Good Bye!";
            return 0;
        default:
            LineBreak();
            cout << "Please Enter vaild number for operation\n";
            break;
        }
    }
}

