#include<iostream>
using namespace std;
class set
{
    int s[30],n;
    public:
    set(){n=0;}
    void add();
    void dis();
    void remove(int x);
    int search(int x);
    void inter(set &s1,set &s2);
    void uni(set &s1,set &s2);
    void diff(set &s1,set &s2);
    void sub(set &s1,set &s2);


};
void set::add()
{
    
    cout<< "enter the no";
    cin>>s[n];
    n++;
    
}
void set::dis()
{
    for (int i=0;i<n;i++)
        cout<<"\t"<<s[i];
}
int set::search(int x)
{
    for (int i=0;i<n;i++)
    {
        if(s[i]==x)
            return i;
    }
    return -1;
}
void set::remove(int x)
{
    int ele=search(x);
    if (ele!=-1){

    for(int j=ele;j<n-1;j++) {
        s[j]=s[j+ 1];

    } n--;
    cout<<"removed !";
    }  
}
void set::uni(set &s1,set &s2)
{
    n=0;
    for (int i=0;i<s1.n;i++)
    {
        s[i]=s1.s[i];
        n++;
    }
    for(int j=0;j<s2.n;j++)
    {
        if (search(s2.s[j])==-1)
            s[n++]=s2.s[j];

    }
    dis();


}
void set::inter(set &s1,set &s2)
{
    n=0;
    for (int i=0;i<s2.n;i++)
    {
        if(s1.search(s2.s[i])!=-1)
        {
            s[n++]=s2.s[i];
        }

    }
    dis();
    
}
void set::diff(set &s1,set &s2)
{
    n=0;
  for (int i=0;i<s1.n;i++)
    {
        int flag=0;
        if(s2.search(s1.s[i])!=-1)
        {
            flag=1;
            
        }
        if (flag==0)
        {
            s[n++]=s1.s[i];
        }
    }  
    dis();
    
}

void set::sub(set &s1,set &s2)
{
    inter(s1,s2);
    if (n == s1.n)
    {
        cout<<"\n A is subset of B :-";
        dis();
    }
    else if (n == s2.n)
    {
        cout<<"\n B is subset of A :-";
        dis();
    }
    else 
    {
        cout<<"\n There is subset not found. ";
    }
}
int main()
{
    set s1,s2,s3;
    int ch,ele;
    do{
        cout << "\n1: Enter an ele";
		cout << "\n2: dis eles";
		cout << "\n3: Remove an ele";
		cout << "\n4: Search for an ele";
		cout<<  "\n5: Union of set ";
        cout<<  "\n6: Intersection of set ";
        cout<<  "\n7: Difference of set ";
        cout<<  "\n8: Subset of set ";
		cout << "\n9: Exit";
		cout << "\nEnter your choice:- ";
		cin>>ch;
        switch(ch)
        {
            case 1: 
                int ch1;
                cout<<"add to set (1/2):";
                cin>>ch1;
                if (ch1==1)
                {
                cout<<"\n 1:Add ele in set A";
				s1.add();
                }
                else {
                cout<<"\n 2:Add ele in set B";
				s2.add();
                }
            break;
            case 2:
                cout<<"\n 1:dis ele in set A";
				s1.dis();
				cout<<"\n 2:dis ele in set B";
				s2.dis();
            break;
            case 3:
             int ch2;
                cout << "\nEnter the ele to remove: ";
				cin >> ele;
                cout<<"remove to set (1/2):";
                cin>>ch2;
                if (ch2==1)
                {
                    cout<<"\n 1:Remove ele in set A";
                    s1.remove(ele);
                }
                else {
                    cout<<"\n 2:Remove ele in set B";
                    s2.remove(ele);
                    
                }
            
				
				
            break;
            case 4:
                int ch4,pos;
				cout<<"\n 1:Search ele in set A";
				cout<<"\n 2:Search ele in set B";
				cout << "\nEnter your choice:- ";
				cin>>ch4;
				
				switch(ch4)
				{
					case 1:
						cout << "\nEnter the ele to search: ";
						cin >> ele;
						pos= s1.search(ele) ;
						if ( pos != -1) 
						{
						cout << "\nele " << ele << " found in the set at "<< pos;
						} 
						else
						{
						cout << "\nele " << ele << " not found in the set ";
						}
						break;
					case 2:
						cout << "\nEnter the ele to search: ";
						cin >> ele;
						pos= s2.search(ele) ;
						if ( pos != -1) 
						{
						cout << "\nele " << ele << " found in the set at "<< pos;
						} 
						else
						{
						cout << "\nele " << ele << " not found in the set ";
						}
						break;
                    default:
                        cout<<"\nInvalid choice";
				}
            break;
            case 5:
                s3.uni(s1,s2);
            break;
            case 6:
                s3.inter(s1,s2);
            break;
            case 7:
                cout<<"\n 1:Difference between set A & B";
				s3.diff(s1,s2);
				cout<<"\n 2:Difference between set B & A ";
				s3.diff(s2,s1);
            break;
            case 8:
                s3.sub(s1,s2);
            break;
            case 9:
                
            break;
        
        }

    }while(ch!=9);
    return 0;
}
