
//* Swap two adjacent elements by adjusting only the links(and not the data) using
//*  a.singly linked lists
//*  b.doubly linked lists
//* -----------------------------------------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

//*linked list node
class Node
{
public:
  int data;
  Node *next;
};

/* Fuction to swap nodes x and y in the linked list
 by changing links */
void swapNodes(Node **head_ref, int x, int y)
{
  if (x == y)
    return;

  //*search for x and then keep track of the prevX and the currX
  Node *prevX = NULL, *currX = *head_ref;
  while (currX && currX->data != x)
  {
    prevX = currX;
    currX = currX->next;
  }

  //*search for y and then keep track of the prevYnd the currY
  Node *prevY = NULL, *currY = *head_ref;
  while (currY && currY->data != y)
  {
    prevY = currY;
    currY = currY->next;
  }

  //* if either x or y is not present, there is nothing to do
  if (currX == NULL || currY == NULL)
    return;

  //* if x is not head of linked list
  if (prevX != NULL)
    prevX->next = currY;
  else //* Else make y as new head
    *head_ref = currY;

  //* if y is not head of linked list
  if (prevY != NULL)
    prevY->next = currX;
  else //* Else make y as new head
    *head_ref = currX;

  //* Swap next pointers
  Node *temp = currY->next;
  currY->next = currX->next;
  currX->next = temp;
}

void push(Node **head_ref, int new_data)
{
  //* Allocate new node
  Node *new_node = new Node();
  //* insert data
  new_node->data = new_data;
  //*link the old list off the new node
  new_node->next = (*head_ref);
  //* move the head to point to the new node
  (*head_ref) = new_node;
}

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

  Node *start = NULL;

  push(&start, 7);
  push(&start, 6);
  push(&start, 5);
  push(&start, 4);
  push(&start, 3);
  push(&start, 2);
  push(&start, 1);

  cout << "Linked list before calling swapNodes() ";
  printList(start);

  swapNodes(&start, 4, 3);

  cout << "\nLinked list after calling swapNodes() ";
  printList(start);

  return 0;
}