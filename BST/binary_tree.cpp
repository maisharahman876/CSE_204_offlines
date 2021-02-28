#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
     node* left;
     node* right;
};

class bst
{

    node *remove_data(node *leaf,int key);
    void insert_in(int key, node *leaf);
    node *search_in(int key, node *leaf);
    node *FindMin(node *root);
public:
     node *root;
    bst()
    {
      root= NULL;
    }
    bool search(int);
    void del(int);
    void insert(int);
    void inorder(node *);
    void preorder(node *);

};
node *bst::search_in(int key,node *leaf)
{
    if(leaf!=NULL)
  {
    if(key==leaf->data)
      return leaf;
    if(key<leaf->data)
      return search_in(key, leaf->left);
    else
      return search_in(key, leaf->right);
  }
  else return NULL;
}
bool bst::search(int key)
{
    if(search_in(key,root)==NULL)
        return false;
    return true;
}
void bst::insert_in(int key, struct node* leaf)
{
   if(key<leaf->data)
   {


       if(leaf->left!=NULL)
       {
           insert_in(key,leaf->left);
       }

   else
   {
       leaf->left=new node;
       leaf->left->data=key;
       leaf->left->left=NULL;
       leaf->left->right=NULL;
   }
   }
   else if(key>leaf->data)
   {
       if(leaf->right!=NULL)
         insert_in(key,leaf->right);
    else
   {
       leaf->right=new node;
       leaf->right->data=key;
       leaf->right->left=NULL;
       leaf->right->right=NULL;
   }

   }
}
void bst::insert(int key)
{
    if(search(key))
        return;
    else
    {
        if(root!=NULL)
        {
            insert_in(key,root);
        }
        else
        {
            root=new node;
            root->data=key;
            root->left=NULL;
            root->right=NULL;
        }
    }
}
node *bst:: FindMin(node* root)
{
	while(root->left != NULL)
        root = root->left;
	return root;
}

node *bst::remove_data(node *leaf,int key)
{
    if(leaf==NULL)
        return leaf;
    else if(key<leaf->data)
        leaf->left=remove_data(leaf->left,key);
    else if(key>leaf->data)
        leaf->right= remove_data(leaf->right,key);
    else
    {
       if(leaf->left==NULL&&leaf->right==NULL)
       {
           delete leaf;
           leaf=NULL;
       }
       else if(leaf->left == NULL) {
			struct node *temp = leaf;
			leaf = leaf->right;
			delete temp;
		}
		else if(leaf->right == NULL) {
			struct node *temp = leaf;
			leaf = leaf->left;
			delete temp;
		}
		else {
			struct node *temp = FindMin(leaf->right);
			leaf->data = temp->data;
			leaf->right = remove_data(leaf->right,temp->data);
		}

    }
    return leaf;
}
void bst::del(int key)
{
    if(search(key))
        root=remove_data(root,key);
    return;
}
void bst:: inorder(node *root) {
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void bst:: preorder(node *root) {
	if(root == NULL) return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
    bst b;
    int i,n;
    while(1){

        cout<<"1.Insert an element "<<endl;
        cout<<"2. Search an element "<<endl;
        cout<<"3.Delete an element "<<endl;
        cout<< "4.Print inOrder "<<endl;
        cout<<"5.Print preOrder "<<endl;
        cout<<"6.Exit: "<<endl;
        cout<<"Enter your choice: "<<endl;

        cin>>i;
        switch(i)
        {
            case 1:
                {
                    cout<<" Insert the number: ";
                    cin>>n;
                    b.insert(n);
                    break;
                }
            case 2:
                {
                    cout<<" Search the number ";
                    cin>>n;
                    if(b.search(n))
                        cout<<"This is in the tree."<<endl;
                    else
                        cout<<" Not in the tree."<<endl;
                    break;

                 }
            case 3:
                { cout<<" Delete the number: ";
                    cin>>n;
                    b.del(n);
                    break;

                }
            case 4:
                {
                    b.inorder(b.root);
                    cout<<endl;
                    break;
                }
            case 5:
                {
                    b.preorder(b.root);
                    cout<<endl;
                    break;
                }
            case 6:
                {
                    exit(1);

                }



    }
    }



    return 0;

}



