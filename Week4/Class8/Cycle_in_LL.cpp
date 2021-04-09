// To find if the given linked list has a loop/cycle or not  ----- T=O(n), S=O(n)
// M1: Keep iterating through the loop and make each traversed element -1 and if any next element is -1 when checked, it has a loop
// M2: Add the entries of LL in set or map, if duplicate, then cycle is present
#include <iostream>
#include <unordered_set>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void insertAtHead(struct Node **head, int new_data)
{
    struct Node *n = new Node;
    n->data = new_data;
    n->next = *head;
    *head = n;
}

bool detectLoop(struct Node *head)
{
    unordered_set<Node *> s;
    while (head != NULL)
    {
        //check if the element is already present in the Linked list, there's a loop
        if (s.find(head) != s.end())
            return true;

        //if element is not present add it in set
        s.insert(head);

        //increment head
        head = head->next;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    insertAtHead(&head, 20);
    insertAtHead(&head, 4);
    insertAtHead(&head, 15);
    insertAtHead(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop present";

    return 0;
}