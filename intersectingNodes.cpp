#include <iostream>
#include <cstdlib>

using namespace std;

//* linked list node
struct Node
{
  int data;
  Node *next;
};

void push(Node **head_ref, int new_data);

Node *sortedIntersect(Node *a, Node *b)
{
  Node dummy;
  Node *tail = &dummy;
  dummy.next = NULL;

  while (a != NULL && b != NULL)
  {
    if (a->data == b->data)
    {
      push((&tail->next), a->data);
      tail = tail->next;
      a = a->next;
      b = b->next;
    }

    else if (a->data < b->data)
      a = a->next;
    else
      b = b->next;
  }
  return (dummy.next);
}

//* Fuction to insert a node at the beging of the linked list

void push(Node **head_ref, int new_data)
{
  //*Allocate Node
  Node *new_node = (Node *)malloc(sizeof(Node));

  //* put in data
  new_node->data = new_data;

  //*link the old list of the new node
  new_node->next = (*head_ref);

  //* move the head to point to the new node
  (*head_ref) = new_node;
}

//* fuction that prints the linked list
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
}

int main()
{
  Node *a = NULL;
  Node *b = NULL;
  Node *intersect = NULL;

  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);

  intersect = sortedIntersect(a, b);

  cout << "Linked list with common nodes of list a and b \n";
  printList(intersect);
  cout << " " << endl;
}
