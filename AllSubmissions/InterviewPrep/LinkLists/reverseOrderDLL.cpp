
/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

/*
PURPOSE: Reverses the order of a doubly link list
DATE: 6-2-2019
PARAMETERS:
* DoublyLinkedListNode* head; head of a doubly link list
VARIABLES:
* DoublyLinkedListNode* c; the current node in traversal
* DoublyLinkedListNode *p; the previous node in traversal
*/
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
  DoublyLinkedListNode* c = head; //current

  while(c !=NULL) //reverses the previous and next pointers for each node
  {
    DoublyLinkedListNode *p = c->prev;
    c->prev = c->next;
    c->next = p;
    head = c;
    c = c->prev;
  }

  return head;
}