/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

/*
PURPOSE: Checks to see if a Link List has a loop within it.
DATE: 6-5-2019
PARAMETERS: 
* Node* head; the start of link list to be checked.
VARIABLES:
* Node* s; slowly traverses through the link list one step at a time.
* Node* f; fastly traverses through the link list two steps at a time. 
*/
bool has_cycle(Node* head) {
  Node* s = head;
  Node* f = head;
  
  //if the link list has an end, NULL, then there's no loop. but if the fast and slow nodes catch up to each other it means theres a loop.
  while(s != NULL && f!=NULL)
  {    
    s = s->next;
    f = f->next->next;
    
    if(s == f)
      return 1;
  }
  
  return 0;
}