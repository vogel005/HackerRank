/*
class SinglyLinkedListNode { //HACKERRANK CODE
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};
*/

/*
PURPOSE: Inserts a new node at a specific location.
DATE: 5-30-2019
PARAMETERS:
* SinglyLinkedListNode* head, the start of a link list.
* int data, the data for the new node.
* int position, the position for the new node.
VARIABLES:
* SinglyLinkedListNode* current, starts at the head of the Link list and
iterates to the node before the position.
* SinglyLinkedListNode* n, new node being added at the specified position
*/
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
  SinglyLinkedListNode* current = head;
  SinglyLinkedListNode* n = new SinglyLinkedListNode(data);

  for(int i=0; i < position-1; i++)
    current = current->next;

  n->next = current->next;
  current->next = n;

  return head;
}

