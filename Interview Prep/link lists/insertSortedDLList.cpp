
/*
 * For your reference: //HACKERRANK CODE
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};
 */

 /*
 PURPOSE: Inserts a new node in an already sorted least-to-greatest doubly link list in the correctly sorted position.
 DATE: 5-31-2019
 PARAMETERS:
 * DoublyLinkedListNode* head, the start of a doubly link list.
 * int data, data for the new node.
 VARIABLES:
 * DoublyLinkedListNode* c, current node that starts at head and traverses through the link list.
 * DoublyLinkedListNode* n, new node to be inserted.
*/
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
  DoublyLinkedListNode* c = head;
  DoublyLinkedListNode* n = new DoublyLinkedListNode(data); 

  while(c->data<=data&&c->next)
    c=c->next;
  
  if(c->data>data){
    if(c->prev==NULL){ //if new node is being inserted before the head
      n->prev=NULL;
      n->next=c;
      c->prev=c;
      head = n;
    } else{ //in middle of list
      c->prev->next=n;
      n->prev=c->prev;
      n->next=c;
      c->prev=n;
    }
  } else{ //end of list
    c->next=n;
    n->prev=c;
    n->next=NULL;
  }
  
  return head;
}

