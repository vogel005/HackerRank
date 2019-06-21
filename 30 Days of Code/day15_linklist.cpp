      Node* insert(Node *head,int data){
        Node** pp=&head; //pointer to pointer
        while(*pp) //while not NULL
          pp=&((*pp)->next);
        
        *pp = new Node(data); 

        return head;
      }