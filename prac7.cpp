#include<iostream>
using namespace std;
class snode
{
    public:
    char u1,  u2;
    int wt;
};
class test
{
    int m,x,n;
    snode arr[10],res[10];
    public:
        test()
        {
            m=1;
            n=0;
        }
        void create()
        {
            cout<<"\n enter no of edge: ";
            cin>>n;
            cout<<"\n enter no of vertex: ";
            cin>>x;
            for(int i=0;i<n;i++)
            {
                cout<<"\n 1st vrx: ";
                cin>>arr[i].u1;
                cout<<"\n 2nd vrx: ";
                cin>>arr[i].u2;
                cout<<"\n wt: ";
                cin>>arr[i].wt;
                cout<<endl;

            }
            bsort();
        }
        void display()
        {
            for(int i=0;i<n;i++)
            {
                cout<<arr[i].u1<<" "<<arr[i].u2<<" "<<arr[i].wt<<endl;
            }
        }
        void mstdis()
        {
            for(int i=0;i<m;i++)
            {
                cout<<res[i].u1<<" "<<res[i].u2<<" "<<res[i].wt<<endl;
            }
        }
        void bsort()
        {
            snode temp;
            for(int i=0;i<n-1;i++)
            {
                for (int j=0;j<n-1-i;j++)
                {
                    if(arr[j].wt>arr[j+1].wt)
                    {
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                }   }
            }
        }
        void prims()
        {
            int cnt=0;
            int flag1,flag2;
            res[0]=arr[0];
            m=1;
            cnt=1;
            do{
                
                for(int i=0;i<n;i++)
                {
                    flag1=0;
                    flag2=0;
                    for(int j=0;j<m;j++)
                    {
                        if ((arr[i].u1==res[j].u1||arr[i].u1==res[j].u2 )&& flag1==0)
                            flag1++;
                        if ((arr[i].u2==res[j].u1||arr[i].u2==res[j].u2 )&& flag2==0)
                            flag2++;
                        
                    }
                    if(flag1!=1 ^ flag2!=1)
                    {
                        res[m++]=arr[i];
                    }
                }

                cnt=x-1;
            }while(m!=cnt);
        }
};

int main()
{
   test obj;
   obj.create();
   obj.display();
   obj.prims();
   cout<<"RESULT:"<<endl;
   obj.mstdis();
return 0;
}