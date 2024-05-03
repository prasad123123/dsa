#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
struct stud
{
    int roll;
    char name[10];
    char add[10];
    char div;
}rec;
class student
{
    public:
    void create()
    {
        char ans;
        ofstream fout;
        fout.open("stud.dat",ios::out|ios::binary);
        do
        {
                    cout<<"\n\tEnter Roll No of Student : "; 
        cin>>rec.roll; 
        cout<<"\n\tEnter a Name of Student : "; 
        cin>>rec.name; 
        cout<<"\n\tEnter a Division of Student : "; 
        cin>>rec.div; 
        cout<<"\n\tEnter a Address of Student : "; 
        cin>>rec.add; 
        fout.write((char *)&rec,sizeof(stud))<<flush;
        cout<<"\n\tDo You Want to Add More Records: "; 
        cin>>ans; 

        }while(ans=='y'||ans=='Y');
        fout.close();
    
    }
    void display()
    {
        ifstream fin;
        fin.open("stud.dat",ios::in|ios::binary);
        fin.seekg(0,ios::beg);
        cout<<"\n\tThe Content of File are:\n"; 
        cout<<"\n\tRoll\tName\tDiv\tAddress"; 
while(fin.read((char *)&rec,sizeof(stud)))
{
    if (rec.roll!=-1)
     cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;  
        
    } 
    fin.close();
    }
    int search()
    {
        ifstream fin;
        int i=0,key;
        fin.open("stud.dat",ios::in|ios::binary);
        fin.seekg(0,ios::beg);
        cout<<"\n\tEnter a Roll No: "; 
        cin>>key;
        while(fin.read((char *)&rec,sizeof(stud)))
        
        {
            if (rec.roll==key)
            {
            cout<<"\n\tRecord Found...\n"; 
            cout<<"\n\tRoll\tName\tDiv\tAddress"; 
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add; 
            return i;       
            }
            i++;

        } 
        fin.close();
        return 0;


    }
    void del()
    {
        int pos;
        pos=search();
        fstream f;
        f.open("stud.dat",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        if (pos==0)
        {
            cout<<"\nnot found";
            return;
        }
        int offset=pos*sizeof(stud);
        f.seekp(offset);
        rec.roll=-1;
        strcpy(rec.name,"NULL");
        rec.div='n';
        strcpy(rec.add,"NULL");
        f.write((char *)&rec,sizeof(stud));
        f.seekg(0);
        f.close();
        cout<<"\n\tRecord Deleted"; 

    }

};
int main() 
{ 
       student obj; 
       int ch,key; 

       do 
       { 
              cout<<"\n\t***** Student Information *****"; 
              cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4.  Search\n\t5. Exit"; 
              cout<<"\n\t..... Enter Your Choice: "; 
              cin>>ch; 
              switch(ch) 
              { 
              case 1: obj.create(); 
              break; 
              case 2: obj.display(); 
              break; 
              case 3: obj.del(); 
              break; 
              case 4: key=obj.search(); 
              break; 
              case 5: 
              break; 
              } 
        }while(ch!=5); 
 
return 0; 
 } 