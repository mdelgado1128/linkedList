#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

void push(Node **head_ref, int new_data)
{
  Node *new_node = new Node();
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void getCount(Node *head)
{
  // initialize a counter
  int count = 0;
  Node *current = head;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  cout << count;
}

void getNth(Node *head, int x)
{
  Node *current = head;
  int count = 1;
  while (current != NULL)
  {
    if (current->data == x)
      cout << " yes " << current->data;

    count++;
    current = current->next;
  }
}

void addNth(Node **head, int newData)
{
  // Node *current = *head;
  // while (current != NULL)
  // {
  //   if (current->data != newData)
  //   {
  Node *newNode = new Node();
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
  cout << newData;
  //   }
  // }
}

void printList(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

int main()
{
  Node *head = NULL;

  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  cout << "a. Count of linked List: ";
  getCount(head);
  cout << endl;

  cout << "b. print linked list: ";
  printList(head);
  cout << endl;
  cout << "c. Is value x contained in the list:";
  getNth(head, 6);
  cout << endl;
  cout << "d. add a value x if its not in the contained list: ";
  addNth(&head, 9);
  cout << endl;
  cout << "e. remove a value x if it is contained in the lisnked list ";

  return 0;
}
