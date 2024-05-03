#include<iostream>
using namespace std;
class node{
    public:
    node *left;
    node *right;
    int data;
    int lbit,rbit;

};
class tbt
{
    public:
    node *root,*head;
    tbt()
    {root =NULL;
    head= NULL;
    }
    void create_TBT();
    void preorder();
    void inorder();


};
void tbt::create_TBT()
{
    char ans;
    node *new_node,*temp;
    head=new node();
head->data=-999;
head->left=NULL;
head->right=NULL;
head->rbit=0;
head->lbit=0;
    root=new node();
    cout<<"root data: ";
    cin>>root->data;
    head->left=root;
    head->lbit=1;
    root->left=head;
    root->right=head;
    root->lbit=0;
    root->rbit=0;
    do{
        new_node =new node();
        cout<<"node data: ";
        cin>>new_node->data;
        new_node->lbit=0;
        new_node->rbit=0;
        temp=root;
        int flag=0;
        while(flag==0)
        {
            if (new_node->data<temp->data)
            {
                if(temp->lbit==0)
                {
                    new_node->left=temp->left;
                    temp->lbit=1;
                    temp->left=new_node;
                    new_node->right=temp;
                    

                    flag=1;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else if (new_node->data>temp->data)
            {
                if(temp->rbit==0)
                {
                    new_node->right=temp->right;
                    temp->rbit=1;
                    temp->right=new_node;
                    new_node->left=temp;
                    

                    flag=1;
                }
                else
                {
                    temp=temp->right;
                }
            }
            else
            {
                cout<<"\n\tData already exist.....!!!";
            }
        }
        cout<<"\n\tDo you want to continue:";
        cin>>ans;


    }while(ans=='y'||ans=='Y');

}
void tbt::inorder()
{
    node *temp;
    temp=root;
    int flag=0;
    if (root==NULL)
    {
        cout<<"\n\tTree is empty...!";
    }
    else
    {
        while(temp!=head)
        {
            if(temp->lbit==1 && flag==0)
            {
                temp=temp->left;
            }
            else
            {
                cout<<" "<<temp->data;
                if (temp->rbit==1)
                {
                    temp=temp->right;
                    flag=0;
                }
                else
                {
                    temp=temp->right;
                    flag=1;
                }
            }
        } 
    }
}
void tbt::preorder()
{
    node *temp;
    temp=root;
    int flag=0;
    if (root==NULL)
    {
        cout<<"\n\tTree is empty...!";
    }
    else
    {
        while(temp!=head)
        {
            if (flag==0)
            {
                cout<<" "<<temp->data;
            }
            if(temp->lbit==1 && flag==0)
            {
                temp=temp->left;
            }
            else
            {
                
                if (temp->rbit==1)
                {
                    temp=temp->right;
                    flag=0;
                }
                else
                {
                    temp=temp->right;
                    flag=1;
                }
            }
        } 
    }

}


int main()
{
    tbt t;
    int choice;
    do
    {
        cout<<"\n\t1.Insert element ";
        cout<<"\n\t2.Display inorder ";
        cout<<"\n\t3.Display inorder ";
        cout<<"\n\t4.Exit ";
        cout<<"\n\tEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:  
                t.create_TBT();
            break;
            case 2: 
                cout<<"\n\t1Inorder is: ";
                t.inorder();
            break;
            case 3:
                cout<<"\n\tPreorder is: ";
                t.preorder();
            break;
            case 4:
                cout<<"\n\tExit";
            break;
        }
    }while(choice!=4);
    return 0;
   
}