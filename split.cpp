/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{

    if (in == NULL) return;

    //moves forward and has the node move foward so recursion occurs and will end up null
    Node* curr = in; 
    in = in->next;

    //detach to prevent any fiture leaks from old chain 
    curr->next = NULL;

    //recurse now / maintasins order 
    split(in, odds, evens);


    //odd if statement recheck val spelling 
    if(curr->value % 2 != 0) {
        curr->next = odds;
        odds = curr;

    }
    else {
        curr->next = evens;
        evens = curr;
    }

}
