
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

/*
PURPOSE: Finds the node where the two link lists merge.
DATE: 6-4-2019
PARAMETERS:
* SinglyLinkedListNode* head1; head node of first link list.
* SinglyLinkedListNode* head2; head node of second link list.
VARIABLE:
* SinglyLinkedListNode* c1; the current node during traversal of linklist1,
which loops to link list 2.
* SinglyLinkedListNode* c2; the current node during traversal of linklist2, which loops to link list1. 
*/
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  SinglyLinkedListNode* c1 = head1;
  SinglyLinkedListNode* c2 = head2;

  while (c1 != c2) {
    //if linklist1 reaches the end, have it start at beginning of list2
    if (c1->next == NULL) {
      c1 = head2;
    } else {
      c1 = c1->next;
    }
    //linklist 2 follows same logic as list1
    if (c2->next == NULL) {
      c2 = head1;
    } else {
      c2 = c2->next;
    }
  }

  return c2->data;
}

