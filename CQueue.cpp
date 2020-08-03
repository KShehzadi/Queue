#include <iostream>
#include "Node.cpp"
using namespace std;

class CQueue
{
public:
  int count;
  Node* head;
  Node* tail;

  CQueue();
  CQueue(Node* &ptr);
  void Add(Node* &ptr);
  Node* Remove();
};

CQueue::CQueue():count(0),head(NULL),tail(NULL)
{

}

CQueue::CQueue(Node* &ptr):count(1),tail(ptr),head(ptr)
{
  tail->next = NULL;
  ptr = NULL;
}

void CQueue::Add(Node* &ptr)
{
  if(head)
  {
    tail->next = ptr;
    tail = tail->next;
  }
  else
  {
    head = tail = ptr;
  }
  count++;
  ptr = NULL;
  tail->next = NULL;
}

Node* CQueue::Remove()
{
  Node* ptr = head;
  if(head)
  {
    head = head->next;
    ptr->next = NULL;
  }
  else
  {
    tail = NULL; // Why need to do this?
  }
  if(count) count--; // Mistake correction?
  return ptr;
}

int main()
{
  Node* ptr1 = new Node(1);
  Node* ptr2 = new Node(2);
  Node* ptr3 = new Node(3);
  Node* ptr4 = new Node(4);
  Node* ptr5 = new Node(5);

  CQueue Q1;
  Q1.Add(ptr1);
  Q1.Add(ptr2);
  Q1.Add(ptr3);
  Q1.Add(ptr4);

  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;

  Q1.Add(ptr5);

  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;
  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;
  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;
  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;
}
