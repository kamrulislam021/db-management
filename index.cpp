#include<iostream>
using namespace std;
class DataBase;
class ShowData;
class AddData;
class EditData;           //4 class has been declared
class DeleteData;
class SearchData;
static int count = 0; //to use as a friend class
class  DataBase
{

public:
    string name,num,dept,batch,roll,email;

    DataBase(): name(""), num(""), dept(""), batch(""), roll(""),email("") {}

    void setData(string new_name, string new_num, string new_dept,string new_batch,string new_roll,string emmail)
    {
        name=new_name;
        num= new_num;
        dept=new_dept;
        batch=new_batch;
        roll=new_roll;
        email= emmail;
    }
    friend   class SearchData;
    void display();
    friend class EditData;
    friend class ShowData;
};

void DataBase:: display()
{

    cout<<"\t\tName: "<<name<<endl;
    cout<<"\t\tNumber:"<<num<<endl;
    cout<<"\t\tDepertment: "<<dept<<endl;
    cout<<"\t\tBatch: "<< batch<<endl;
    cout<<"\t\troll: "<<roll<<endl;
    cout<<"\t\ttemail: "<<email<<endl;
    cout<<endl;
}

class AddData
{
public:

    DataBase *data1=new DataBase[count];
    void add();
    friend class EditData;
    friend class ShowData;
    friend class ShowData;
    friend  class SearchData;
    void displayA();
    void show(AddData &data,string search_term);
    void erase(AddData &data,string search_term);
    void edit(AddData & data,string namee);
};
void AddData::displayA()


{



    for(int i = 0; i<count; i++)
    {
        data1[i].display();
    }


}
void AddData:: show(AddData &data,string search_term)
{
    for (int i = 0; i < count; i++)
    {
        if(search_term==data.data1[i].name || search_term==data.data1[i].dept || search_term==data.data1[i].batch)
        {
            cout << data.data1[i].name << "\t" << data.data1[i].num <<"\t"<<data.data1[i].dept<<"\t"<<data.data1[i].batch<<"\t"<<data.data1[i].roll<< endl;

        }
    }
}
void AddData::add()
{
    cout<<"how may student do you want to add in the database?"<<endl;
    int n;
    cin>>n;

    DataBase *temp = new DataBase[count];
    copy(data1,data1+count,temp);
    delete [] data1;

    data1 = new DataBase[n+count];
    copy(temp,temp+count,data1);
    delete [] temp;

    for(int i = count; i<n+count; i++)
    {

        string name,num,dept,batch,roll,email;
        cin.ignore();
        cout << "Enter Student name:" << endl;
        getline(cin, name);
        cout << "Enter Student number:" << endl;
        getline(cin,num);
        cout << "Enter dep.:" << endl;
        getline(cin, dept);
        cout << "Enter Student batch:" << endl;

        getline(cin, batch);
        cout << "Enter Student roll:" << endl;
        getline(cin,roll);
        cout << "Enter Student email:" << endl;
        getline(cin, email);
        data1[i].setData(name,num,dept,batch,roll,email);
    }
    count+=n;

};

class ShowData
{
public:
    friend class AddData;
};

class EditData
{

    void  edit(AddData & data,string namee);
};
void AddData:: edit(AddData & data,string namee)
{

    string new_name,new_num,new_dept,new_batch,new_roll,new_email;

    int t=0;
    string s="skip",p;

    for (int i = 0; i < count; i++)
    {


        if(data.data1[i].name==namee)
        {

            system("cls");
            cout << "Enter new name: ";
          cout<<"\n\n\n command (option):        skip--or--edit"<<endl;
            cin>>p;
            if(p!=s)
            {
                cin.ignore(100,'\n');     cout << "Enter new name: ";
                cin >> new_name;
            }
            system("cls");
            cout << "Enter new mobile no: ";
           cout<<"\n\n\n command (option):        skip--or--edit"<<endl;
            cin>>p;
            if(p!=s)
            {
                cin.ignore(100,'\n'); cout << "Enter new mobile no: ";
                cin >> new_num;
            }
            system("cls");
            cout << "Enter new department: ";
         cout<<"\n\n\n command (option):        skip--or--edit"<<endl;
            cin>>p;
            if(p!=s)
            {
                cin.ignore(100,'\n');cout << "Enter new department: ";
                cin >> new_dept;
            }

            system("cls");
            cout << "Enter new batch: ";
           cout<<"\n\n\n command (option):        skip--or--edit"<<endl;
            cin>>p;
            if(p!=s)
            {
                cin.ignore(100,'\n');
            cout << "Enter new batch: ";

                cin >> new_batch;
            }

            system("cls");
            cout << "Enter new roll: ";
             cout<<"\n\n\n command (option):        skip--or--edit"<<endl;
            cin>>p;
            if(p!=s)
            {
                cin.ignore(100,'\n'); cout << "Enter new roll: ";
                cin >> new_roll;
            }

            system("cls");
            cout << "Enter new email";
           cout<<"\n\n\n command (option):        skip--or--edit"<<endl;
            cin>>p;
            if(p!=s)
            {
                cin.ignore(100,'\n');  cout << "Enter new email";
                cin>>new_email;
            }

            data.data1[i].name = new_name;
            data.data1[i].num = new_num;
            data.data1[i].dept=new_dept;
            data.data1[i].batch=new_batch;
            data.data1[i].roll=new_roll;
            data.data1[i].email=new_email;

            t=1;
        }
        system("cls");
    }
    if(t)
    {
        cout << "Edited Successfully!" << endl;
    }
    else cout<<"wrong input!!!";

}
class SearchData
{


};

class DeleteData
{
    friend erase(AddData &data,string search_term) ;
};
void AddData::erase(AddData &data,string search_term)
{
    for (int i = 0; i < count; i++)
    {
        if(search_term==data.data1[i].name || search_term==data.data1[i].dept || search_term==data.data1[i].batch)

        {
            data.data1[i].name = " ";
            data.data1[i].num=" ";
            data.data1[i].dept = " ";

            data.data1[i].batch=" ";
            data.data1[i].roll=" ";
            data.data1[i].email=" ";

        }
    }
    cout<<"delete successful!"<<endl;
    count--;
}
int main()
{
    AddData data;
    int choice;
    cout<<"Please enter the database INFOBOOK password"<<endl;
    string pass="000",p;
    int nul=3;
    while(nul--)
    {
        getline(cin,p);
        if(pass==p)
        {
            system("cls");
            do
            {

                cout << "\n\t\t\t\t\tDatabase Of KUET students\n\n" << endl;
                cout << "1.ShowData" << endl;
                cout << "2.Add Data" << endl;
                cout << "3. EditData" << endl;
                cout <<"4. Search data"<<endl;
                cout << "5.DeleteData" << endl;
                cout << "0.Exit" << endl;
                cin >> choice;
                if(choice==2)
                {
                    data.add();
                    system("cls");
                }
                else if (choice==1)
                {
                    system("cls");
                    cout<<"Database of total..." <<count<<" student"<<endl;
                    data.displayA( );
                }



                else if(choice==3)
                {
                    system("cls");
                    string namee;
                    cout << "Enter a contact name to edit:";

                    cin >>namee;



                    data.edit( data, namee);





                }
                else if(choice==4)
                {
                    system("cls");
                    cout<<"search by name "<<endl;
                    string search_term;
                    cin>>search_term;
                    data.show(data,search_term);



                }


                else if(choice==5)
                {
                    system("cls");
                    cout<<"delete by name or dept."<<endl;
                    string search_term;
                    cin>>search_term;
                    data.erase(data, search_term);
                }
            }
            while(choice!=0) ;
        }
        else cout<<"try again...you have   ...."<<nul<<" times"<<endl;



    }
    return 0;
}
