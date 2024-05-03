#include<iostream>
using namespace std;
class ht
{
    public:
        int key;
        long int mob_no;
};
class hashing
{
    ht t[10];
    public:
    int i;
    hashing()
    {
        for(i=0;i<10;i++)
        {
            t[i].key=i;
            t[i].mob_no=-1;
        }
    }
    void display();
    void insert(int prob);
    int search(int x);
    int linear(int col);
    int quad(int col);

};

int hashing::search(int x)
{
    for(i=0;i<10;i++)
    {
        if(t[i].mob_no==x)
            {
                return i;
            }
    }
    return -1;

}
void hashing:: display()
{
    cout<<"\n\tkey\tvalue"<<endl;
    for(i=0;i<10;i++)
    {
        cout<<"\n\t"<<t[i].key<<"\t"<<t[i].mob_no<<endl;
    }
}

void hashing::insert(int prob)
{
    long int num;
    int col,pos;
    cout<<"\nenter the no:";
    cin>>num;
    pos=num%10;
    for(i=0;i<10;i++)
    {
        if(t[i].key==pos)
        {
            if(prob==1)
            {
                col=pos;
                int temp=linear(col);
                t[temp].mob_no=num;
                cout<<"\n \t Mobile number store at key "<< temp <<endl;
                break;
            }
            else if(prob==2)
            {
                col=pos;
                int temp=quad(col);
                t[temp].mob_no=num;
                cout<<"\n \t Mobile number store at key "<< temp <<endl;
                break;
            }
            else    
                cout<<"\n\tinvalid!";

        }
    }
}
int hashing::linear(int col)
{
    for(i=col;i<10;i++)
    {
        if(t[i].mob_no==-1)
            return i;

        if(i==9)
        {
            i=-1;
        }
    
    }

}

int hashing::quad(int col)
{
     for(i=0;i<10;i++)
     {
        int temp_quad=(col+(i*i)%10);
        if(t[temp_quad].mob_no==-1)
        {
            return temp_quad;
        }
     }
}
int main()
{
    hashing h;
    int ch,prob;
    do{
        cout<<"\n \t Main Menu "<<endl;
		cout<<"\n \t 1: Insert Data "<<endl;
		cout<<"\n \t 2: Display Data "<<endl;
		cout<<"\n \t 3: Search Data "<<endl;
		cout<<"\n \t 4:Exit "<<endl;
		cout<<"\n \t Enter the choice :- ";
		cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\n \t 1:Linear Probing "<<endl;
				cout<<"\n \t 2:Quadratic Probing "<<endl;
				cout<<"\n \t Enter the choice :- ";
                cin>>prob;
                h.insert(prob);
            break;
            case 2:
                h.display();
            break;
            case 3:
                int val,pos;
                cout<<"\n \t Enter the number :- ";
                cin>>val;
                pos=h.search(val);
                if (pos!=-1)
                {
                    cout<<"\n \t Data successfully found at "<<pos<<" position"<<endl;
				}
				else
					cout<<"\n \t Data not found "<<endl;
            break;
            case 4:
            
            break;
       
        
        }
    }while (ch!=4);
    return 0;
    
}
