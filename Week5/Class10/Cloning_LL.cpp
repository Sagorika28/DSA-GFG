// Given a linked list having two pointers in each node. The first one points to the next node of the list, however, the other pointer is random and can point to any node of the list.
// Write a program that clones the given list in O(1) space, i.e., without any extra space.
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next, *random;
    node(int x)
    {
        this->data = x;
        next = random = NULL;
    }
};

// printing the LL
void print(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        cout << "Data: " << ptr->data << ", Random node: " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

node *clone(node *start)
{
    node *curr = start, *temp;

    // adding a new node after the original node
    while (curr)
    {
        temp = curr->next;                 // storing the original next into temp
        curr->next = new node(curr->data); // adding a copy of original node after it
        curr->next->next = temp;
        curr = temp; // moving to the next original node of the orginal list
    }

    // adjusting the random pointers of the newly made nodes
    curr = start;
    while (curr)
    {
        if (curr->next)
        {
            curr->next->random = curr->random ? curr->random->next : curr->random;
        }

        // move to the next newly added node by skipping an original node
        curr = curr->next ? curr->next->next : curr->next;
    }

    node *original = start, *copy = start->next;

    // save the start of copied linked list
    temp = copy;

    // now separate the original list and copied list
    while (original && copy)
    {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;

        original = original->next;
        copy = copy->next;
    }

    return temp;
}

int main(int argc, char const *argv[])
{
    node *start = new node(1);
    start->next = new node(2);
    start->next->next = new node(3);
    start->next->next->next = new node(4);
    start->next->next->next->next = new node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random = start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    node *cloned_list = clone(start);
    print(cloned_list);
    return 0;
}