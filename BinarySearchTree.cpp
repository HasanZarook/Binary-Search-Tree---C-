
#include <iostream>
#include <string>
using namespace std;

/////////////////BST//////////////

class treeNode
{
public:
    treeNode * left;
    treeNode * right;
    string  data;
    treeNode* parent;
};


class BST
{
    
public:
    
    treeNode * root;
    
    BST()
    {
        root=NULL;
    }
    
    ////////// Inorder Traversal
    
    void InorderTraverse(treeNode *n )
    {
        if (n!=NULL)
        {
            InorderTraverse(n->left);
            cout<<n->data<<" ";
            InorderTraverse(n->right);
        }
    }
    
    ////////// Postorder Traversal
    
    void PostorderTraverse(treeNode *n )
    {
        if(n!=NULL){
        	PostorderTraverse(n->left);
        	PostorderTraverse(n->right);
        	cout<<n->data<<" ";
		}    
        
    }
    
    ////////// Preorder Traversal
    
    void PreorderTraverse(treeNode *n)
    {
        if(n!=NULL){
        cout<<n->data<<" ";
        PreorderTraverse(n->left);
        PreorderTraverse(n->right);
      	}
        
    }
    
    ////////// Insert in Tree
    
    void insert( string m)
    {
        treeNode *z=new treeNode();
        z->data=m;
        z->left=NULL;
        z->right=NULL;
        
        treeNode *y=NULL;
        treeNode *x=root;
        
        while(x!=NULL)
        {
            
            y=x;
            if(x->data.compare(z->data)>0)
                x=x->left;
            else
                x=x->right;    
        }
        
        z->parent=y;
        if(root==NULL)
            root=z;
        else if(y->data.compare(z->data)<0)
            y->right=z;
        else
            y->left=z;
    }
    
    ////////// Min Tree
    
    string TreeMin(treeNode* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        if(x->left !=NULL)
            x=x->left;
        return x->data;
    }
    
    ////////// Max Tree

    string TreeMax(treeNode* x=NULL)
    {
 		if(x==NULL){
 			x=root;
 		}
 		
		if(x->right !=NULL){
			x=x->right;
		}
		
		return x->data; 
        
    }
    
    /////////// Tree Search
    
    treeNode* search(string s)
{
    treeNode* x = root;
    while (x != NULL && s != x->data) {
        if (s.compare(x->data) < 0){
            x = x->left;
        }
        
        else{
            x = x->right;
        }
    }
    return x ;
}
    
    
    
    ////////// Predecessor of x
    
    
    treeNode* Predecessor(string x)
{
    treeNode* n = search(x);
    
    if (n == NULL){
		return NULL;
	}
	
    if (n->left != NULL){
	
        return search(TreeMax(n->left));
    }
    
    treeNode* p = n->parent;
    while (p != NULL && n == p->left) {
        n = p;
        p = n->parent;
    }
    return p;
}
    
    
    ////////// Successor of x
    
    treeNode*  Successor(string x)
    {
        treeNode* n=search(x);
        if (n==NULL){
			return NULL;
		}	
		
        if(n->right!=NULL){
        	return search(TreeMin(n->right));
        }
        
        treeNode* p=n->parent;
        while(p != NULL && n==p->right){
        	n=p;
        	p=p->parent;
		}
		return p;
    }

    
    ////////// Delete from tree
    
    void deleteNode(string x)
{
    treeNode* c = search(x);
    if (c == NULL){
	  return;
	}	

    treeNode* temp;
    if (c->left == NULL || c->right == NULL){
        temp = c;
    }
    
    else{
	   temp = Successor(c->data);
	}

    treeNode* temp2;
    if (temp->left != NULL){
        temp2 = temp->left;
    }
    else{
        temp2 = temp->right;
    }

    if (temp2 != NULL){
        temp2->parent = temp->parent;
    }

    if (temp->parent == NULL){
        root = temp2;
    }
    else if (temp == temp->parent->left){
        temp->parent->left = temp2;
    }
    else{
        temp->parent->right = temp2;
    }

    if (temp != c){
        c->data = temp->data;
    }

    delete temp;
}

};

int main()
{
    BST St;
    St.insert("pat");
    St.insert("use");
    St.insert("zoo");
    St.insert("try");
    St.insert("bat");
    St.insert("hay");
    St.insert("key");
    St.insert("jig");
    
    
    St.InorderTraverse(St.root);
    cout<<endl;
    
    
    cout<<St.TreeMin()<<endl;
    cout<<St.TreeMax()<<endl;
    
    treeNode* scNode=St.Predecessor("jig");
    cout<<scNode->data<<endl;
    cout<<St.Successor("")<<endl;
    
    
    St.PreorderTraverse(St.root);
    cout<<endl;
    St.PostorderTraverse(St.root);
    cout<<endl;
    
    treeNode* sNode=St.search("");
    if(sNode!=NULL)
        cout<<sNode->data<<endl;
    else
        cout<<"Data not found"<<endl;
    
    St.deleteNode("jig");
    St.InorderTraverse(St.root);
    cout<<endl;
    
    St.deleteNode("bat");
    St.InorderTraverse(St.root);
    cout<<endl;
    
    St.deleteNode("use");
    St.InorderTraverse(St.root);
    cout<<endl;
 
    
}


