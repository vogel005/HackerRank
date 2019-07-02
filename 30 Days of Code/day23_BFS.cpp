	
	/*
	PURPOSE: Shows a tree in level order, left to right and top to bottom. Also known as Breadth First Search.
	DATE: 7-2-2019
	PARAMETERS: 
	* Node * root; root of a binary tree. 
	VARIABLES:
	* queue<Node *> q; a queue that will be filled with nodes in the tree.
	* auto n; the current node being processed.
	*/
	void levelOrder(Node * root){
		if(root!=NULL){
		queue<Node *> q;
		q.push(root);

			while(!q.empty())
			{
			auto n=q.front();
			cout<<n->data<<' ';
			q.pop();

			if(n->left!=NULL)
				q.push(n->left);

			if(n->right!=NULL)
				q.push(n->right);
			}
		}
	}