#include<iostream>
#include<string>
using namespace std;
class node
{
    public:
    node *left;
    node *right;
    char data;

};
class stack
{
    public:
    node *a[20];
    int top;
    stack()
    {top=-1;}
    void push(node *temp)
    {
        if(!isfull())
        {
            a[++top]=temp;
        }
        else
        {
            cout<<"full";
        }    
    }
    node *pop()
    {
        if(!isempty())
        {
            return(a[top--]);
        }
        else 
        { 
            cout<<"empty";
        }    
    }
    int isfull()
    {
        if(top==19)
        { 
            return 1;
        }
        else
        {
           return 0;
        }
    }
    int isempty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

};
class exp
{
    public:
    node *root;
    exp()
    {root=NULL;}
    void create_exp_tree();
    void infix(node *temp);
    void prefix(node *temp);
    void postfix(node *temp);
    void del(node *temp);


};
void exp::create_exp_tree()
{
    char ch;
    int i;
    string str;
    node *new_node,*temp;
    stack s;
    cout<<"\nenter the exp: ";
    cin>>str;
    for(i=(str.length()-1);i>=0;i--)
    {
        ch=str[i];
        new_node=new node();
        new_node->data=ch;
        new_node->left=NULL;
        new_node->right=NULL;
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            s.push(new_node);
        }
        else
        {
            temp=s.pop();
            new_node->left=temp;
            temp=s.pop();
            new_node->right=temp;
            s.push(new_node);
        }
    }
    root=s.pop();
}
void exp::infix(node *temp)
{
    if(temp!=NULL)
    {

        infix(temp->left);
    cout<<" "<<temp->data;
        infix(temp->right);

    }
}

void exp::prefix(node *temp)
{
    if(temp!=NULL)
    {
    cout<<" "<<temp->data;            
        prefix(temp->left);

        prefix(temp->right);

    }
}
void exp::postfix(node *temp)
{
    if(temp!=NULL)
    {

        postfix(temp->left);

        postfix(temp->right);
    cout<<" "<<temp->data;
    }
}
void exp::del(node *temp)
{
    if (temp==NULL)
        return;
    else
    {
        del(temp->left);
        del(temp->right);
        cout<<"\nDeleting node :"<<temp->data;
        delete(temp);
    }
}
int main()
{
    exp ext;
     ext.create_exp_tree();
    cout<<"\n Prefix expression is: ";
    ext.prefix(ext.root);
    
    cout<<"\n Infix expression is: ";
    ext.infix(ext.root);
    
    cout<<"\n Postfix Expression is:  ";
    ext.postfix(ext.root);
    
    
    cout<<"\n Deleting Node:";
    ext.del(ext.root);
    cout<<endl;
    return 0;
}

