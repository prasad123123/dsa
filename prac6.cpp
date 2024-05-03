#include<iostream>
using namespace std;
class Queue
{
    int a[20],f,r;
    public:
    Queue()
    {
        f=0;
        r=0;
    }
    void insert(int key)
    {
        if (r!=20)
            a[r++]=key;
        else
            cout<<"\nfull";
    }
    int Delete()
    {
        if (f!=r)
            return (a[f++]);
        else
            cout<<"\n empty";
    }
};
class stack
{
    int a[20], top;
    public:
    stack()
    {top=-1;}
    void push(int key)
    {
        if(top!=19)
        {
            a[++top]=key;
        }
        else
        {
            cout<<"\nfull";
        }
    }
    int pop()
    {
        if (top!=-1)
        {
            return (a[top--]);

        }
        else
            cout<<"\nempty";
    }

};
class graph 
{
    int ad[10][10],vcnt;
    int v[10],rcnt;
    public:
        graph()
        {rcnt=0;
        vcnt=0;
        }
        void create()
        {
            cout<<"\n n. of vrx: ";
            cin>>vcnt;
            for(int i=1;i<=vcnt;i++)
            {
                for(int j=1;j<=vcnt;j++)
                {
                    cout<<"\nedge "<<j<<", "<<j<<" : ";
                    cin>>ad[i][j]; 
                }
            }
        }
        void display()
        {
             for(int i=1;i<=vcnt;i++)
            {
                for(int j=1;j<=vcnt;j++)
                {
                    
                    cout<<ad[i][j]<<" "; 
                }
                cout<<"\n";
            }
        }
        void dfs()
        {
            rcnt=0;
            int sv,curr;
            stack s;
            cout<<"start vrx : ";
            cin>>sv;
            v[rcnt++]=sv;
            s.push(sv);
            for(int i=1;i<=vcnt;i++)
            {
                curr=s.pop();
                for(int j=1;j<=vcnt;j++)
                {
                    if (ad[curr][j]==1)
                    {
                        s.push(j);
                        if(search(j)==0)
                        {
                            v[rcnt++]=j;
                        }
                    }
                }
            }
            cout<<"\nDFS: -";
            for(int i=0;i<rcnt;i++)
                cout<<"   "<<v[i];
        }

        void bfs()
        {
            rcnt=0;
            int sv,curr;
            Queue q;
            cout<<"start vrx : ";
            cin>>sv;
            v[rcnt++]=sv;
            q.insert(sv);
            for(int i=1;i<=vcnt;i++)
            {
                curr=q.Delete();
                for(int j=1;j<=vcnt;j++)
                {
                    if (ad[curr][j]==1)
                    {
                        q.insert(j);
                        if(search(j)==0)
                        {
                            v[rcnt++]=j;
                        }
                    }
                }
            }
            cout<<"\nBFS: -";
            for(int i=0;i<rcnt;i++)
                cout<<"   "<<v[i];

        }
        int search(int x)
        {
            int i;
            for(i=0;i<rcnt;i++)
            {
                if(v[i]==x)
                    return 1;
            }
            if(i==rcnt)
            {
                return 0;
            }
        }

};
int main()
{
       int choice,key;
       graph obj;
      
       obj.create();
       obj.display();
       do
       {
	       cout<<"\nMenu\n1.BFS\n2.DFS\n Enter choice ";
	       cin>>choice;
	       switch(choice)
	       {
		      case 1:
		                    obj.bfs();
		       break;                           
		       case 2:
		                    obj.dfs();
		       break;                              
	       }
       }while(choice!=3);
       return 0;
}
