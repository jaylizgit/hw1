/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{// test_split.cpp
#include "split.h"
#include <iostream>
#include <vector>
#include <cstddef>

static Node* build(const std::vector<int>& vals) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int x : vals) {
        Node* n = new Node{ x, NULL };
        if (!head) { head = tail = n; }
        else { tail->next = n; tail = n; }
    }
    return head;
}

static void print_list(const char* name, Node* p) {
    std::cout << name << ":";
    while (p) { std::cout << " " << p->value; p = p->next; }
    std::cout << "\n";
}

static void free_list(Node* p) {
    while (p) { Node* tmp = p; p = p->next; delete tmp; }
}

int main() {
    Node* in = build({1,2,3,4,5,6});   // sorted input
    Node* odds = NULL;
    Node* evens = NULL;

    split(in, odds, evens);

    std::cout << "in is " << (in == NULL ? "NULL" : "not NULL") << "\n";
    print_list("odds", odds);   // expect: 1 3 5
    print_list("evens", evens); // expect: 2 4 6

    free_list(odds);
    free_list(evens);
    return 0;
}
}
