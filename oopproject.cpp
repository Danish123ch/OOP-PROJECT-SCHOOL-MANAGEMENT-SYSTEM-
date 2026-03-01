#include<iostream>
#include<string>
using namespace std;

class person {
    protected :
    string name;
    string contact;
    string address;

    public :
    person(){
        name="";
        contact="";
        address="";

    }

    person(string n,string c,string ad){
        name=n;
        contact=c;
        address=ad;

    }

    person(const person& u){
        name=u.name;
        contact=u.contact;
        address=u.address;

    }

    string getName() {
        return name;
    }

};

class DATE
{
    public:
    int dd, mm, yyyy;
   DATE()
    {
        dd = 12;
        mm = 12;
        yyyy = 2022;
    }
    DATE(int day, int month, int year)
    {
        dd = day;
        mm = month;
        yyyy = year;
    }
    DATE(const DATE& d)
    {
        dd=d.dd;
        mm=d.mm;
        yyyy=d.yyyy;
    }
    void adddate()
    {
            cin>>dd>>mm>>yyyy;
    }
    void displaydate()
    {
        cout<<"date :"<<dd<<","<<mm<<","<<yyyy<<endl;
    }
};

class student: public person{

    public:
    int roll_number;

   student():person(){
    roll_number=0;

   }

    student(int roll,string st_name,string st_contact,string st_address):person (st_name,st_contact,st_address){
        roll_number=roll;

    }

    student(const student& st):person(st){
        roll_number=st.roll_number;

    }

    ~student(){

    }
    void AddStudent(){

        int roll;
         string st_name, st_contact,st_address;
        cout<<"enter the roll_number : ";
         cin>>roll;
         cin.ignore();
         cout<<"enter the name of student : ";
         getline(cin,st_name);
        cout<<"enter the contact number : ";
        getline(cin,st_contact);
        cout<<"enter the address : ";
         getline(cin,st_address);

        roll_number=roll;
        name=st_name;
        contact=st_contact;
        address=st_address;
        cout<<"student added successfully ! "<<endl;
    }

    void displaystudent(){
        cout<<"----------------------------------------"<<endl;
        cout<<"roll number: "<<roll_number<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"contact: "<<contact<<endl;
        cout<<"address: "<<address<<endl;
        cout<<"----------------------------------------"<<endl;
    }

};

class teacher :public person{

    public:
    int t_id;


    teacher():person(){
        t_id=0;


    }

    teacher(int id,string name,string contact,string address): person(name,contact,address){
        t_id=id;

    }

    teacher(const teacher& teach):person(teach){
        t_id=teach.t_id;



    }

    ~teacher(){

    }

    void addteacher(){

        int id;
        string t_name, t_contact,t_address,t_qualification;
        cout<<"enter the teacher id : ";
        cin>>id;
        cin.ignore();
        cout<<"enter the name of teacher : ";
        getline(cin,t_name);
        cout<<"enter the contact number : ";
        getline(cin,t_contact);
        cout<<"enter the address : ";
        getline(cin,t_address);


        t_id=id;
        name=t_name;
        contact=t_contact;
        address=t_address;
        cout<<"teacher added successfully !"<<endl;

    }

    void displayteacher(){
        cout<<"----------------------------------------"<<endl;
        cout<<"teacher id : "<<t_id<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"contact : "<<contact<<endl;
        cout<<"address : "<<address<<endl;
        cout<<"----------------------------------------"<<endl;
    }

};

class course {
    public :
    string course_code;
    string course_title;
    int credit_hours;
    teacher* instructor;

    course(){
        course_code="";
        course_title="";
        credit_hours=0;
        instructor=nullptr;
    }

    course(string code,string title,int credits,teacher* t){
        course_code=code;
        course_title=title;
        credit_hours=credits;
        instructor=t;

    }

    course(const course& crs){
        course_code=crs.course_code;
        course_title=crs.course_title;
        credit_hours=crs.credit_hours;
        instructor=crs.instructor;

    }

    ~course(){

    }

    void addcourse( teacher Teachers[],int t_count);

    void displaycourse(){
        cout<<"----------------------------------------"<<endl;
        cout<<"course_code : "<<course_code<<endl;
        cout<<"course_title :"<<course_title<<endl;
        cout<<"credit_hours :"<<credit_hours<<endl;
        if(instructor){
            cout<<"instructor : "<<instructor->getName()<<endl;
        }
        cout<<"----------------------------------------"<<endl;

    }

};


void course::addcourse(teacher Teacher[],int t_count ) {
    string code, title;
    int credits;

    cout << "Enter course code: ";
    cin >> code;
    cin.ignore();
    cout << "Enter course title: ";
    getline(cin, title);
    cout << "Enter credit hours: ";
    cin >> credits;
    cin.ignore();
    int id;
    cout<<"enter instructor id :";
    cin>>id;
    for(int i=0;i<t_count;i++){
        if(Teacher[i].t_id==id){
            instructor  = &Teacher[i];
            
        }
    }

    course_code = code;
    course_title = title;
    credit_hours = credits;
    if(!instructor){
        cout<<"instructor not found !"<<endl;
    }else {
        cout<<"course added successfully !"<<endl;
    }

}

class Classrooms{

    public:
    int room_no;
    course* c;


    Classrooms(){
        room_no=0;
        c=nullptr;
    }

    Classrooms( int room_no,course* cr){

        room_no=room_no;
        c=cr;
    }

    Classrooms(const Classrooms& cr){
        room_no=cr.room_no;
        c=cr.c;;


    }
    void addclassroom(course courses[],int co_count){
        int room;
        string co_code;
        cout<<"enter the room number : ";
        cin>>room;
        cin.ignore();
        cout<<"enter the course_code :";
        cin>>co_code;
        
        room_no=room;
        for(int i=0;i<co_count;i++){
            if(courses[i].course_code==co_code){
                c=&courses[i];
            }
        }
        if(!c){
            cout<<"course not found !"<<endl;
        }
        else{
        cout<<"class room added successfully !"<<endl;
    }

    }

    void displayclassroom(){
        cout<<"----------------------------------------"<<endl;
        cout<<"room_no :"<<room_no<<endl;
        if(c){
            cout<<"course title : "<<c->course_title<<endl;
        }
        cout<<"----------------------------------------"<<endl;
    }

};





class registration{
       public:
       int registration_id;
       student* Student;
       DATE registration_date;
       course* crs;

       registration(){
        registration_id=0;
        Student=nullptr;
        crs=nullptr;
       }

       registration(int id,student* std,DATE rd,course* c){
        registration_id=id;
        Student=std;
        registration_date=rd;
        crs=c;

       }

       registration(const registration& r){
        registration_id=r.registration_id;
        Student=r.Student;
        registration_date=r.registration_date;
        crs=r.crs;

       }
       ~registration(){

       }

       void addregistration(student Students[],int st_count,course courses[],int co_count);

       void displayregistration(){
        cout<<"----------------------------------------"<<endl;
        cout<<"registration_id :"<<registration_id<<endl;
        if(Student){
            cout<<"student name : "<<Student->getName()<<endl;
        }
        registration_date.displaydate();
        if(crs){
            cout<<"course title : "<<crs->course_title<<endl;
        }
        cout<<"----------------------------------------"<<endl;
       }

};

void registration :: addregistration( student Students[],int st_count,course courses[],int co_count){
    int id;
    DATE d;
    string cc;
    int rn;

    cout<<"enter the registration id :";
    cin>>id;
    
    cout<<"add the registration date :";
    d.adddate();
    
    cout<<"enter student roll number : ";
    cin>>rn;
    for(int i=0;i<st_count;i++){
        if(Students[i].roll_number==rn){
            Student=&Students[i];
        }
    }
    cout<<"enter course code : ";
    cin>>cc;
    for(int i=0;i<co_count;i++){
        if(courses[i].course_code==cc){
            crs=&courses[i];
        }
    }
    
    registration_id=id;
    d=registration_date;
    if(!Student){
        cout<<"student not found !"<<endl;
    }
    if(!crs){
        cout<<"course not found !"<<endl;
    }
   }

int main(){

    int st_count=0;
    student Students[100];
    int t_count=0;
    teacher Teachers[100];
    int cr_count=0;
    Classrooms Classroom[100];
    course courses[100];
    int co_count=0;
    DATE date[100];
    int r_count=0;
    registration reg[100];
    int choice=0;

    do{
        cout<<"\t=================================="<<endl;
        cout<<"\t=====School Management System====="<<endl;
        cout<<"\t=================================="<<endl<<endl;
        cout<<"=================================="<<endl;
        cout<<" 1.manage students"<<endl;
        cout<<" 2.manage teachers"<<endl;
        cout<<" 3.manage courses"<<endl;
        cout<<" 4.manage classrooms"<<endl;
        cout<<" 5.manage registration"<<endl;
        cout<<" 6.Exit"<<endl;
        cout<<"=================================="<<endl;


        cout<<"enter your choice :";
        cin>>choice;

        if(choice==1){
                int ch1=0;
                do{
                    cout<<"-------------------------------"<<endl;
                    cout<<"1.add Student"<<endl;
                    cout<<"2.display students"<<endl;
                    cout<<"3.update student information"<<endl;
                    cout<<"4.remove  students"<<endl;
                    cout<<"5.find student"<<endl;
                    cout<<"6.back to main menu"<<endl;
                    cout<<"-------------------------------"<<endl;
                    cout<<"enter your choice :";
                    cin>>ch1;

                    switch(ch1){
                        case 1:

                           Students[st_count].AddStudent();
                           st_count++;
                           break;
                       case 2:
                           for(int i=0;i<st_count;i++){
                            Students[i].displaystudent();
                           }
                           break;
                       case 3:
                           cout<<"you choosed option 3"<<endl;
                           break;
                       case 4:
                           cout<<"you choosed option 4"<<endl;
                           break;
                       case 5:
                           cout<<"you choosed option 5"<<endl;
                           break;
                       default:
                           cout<<"you made invalid choice"<<endl;
                           break;

                   }
                }while(ch1!=6);
        }else if(choice==2){
            int ch2=0;
            do{
                cout<<"-------------------------------"<<endl;
                cout<<"1.add teacher"<<endl;
                cout<<"2.display teachers"<<endl;
                cout<<"3.update teacher information"<<endl;
                cout<<"4.remove teachers"<<endl;
                cout<<"5.find teacher"<<endl;
                cout<<"6.back to main menu"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"enter your choice :";
                cin>>ch2;

                switch(ch2){
                     case 1:
                     Teachers[t_count].addteacher();
                     t_count++;
                        break;
                    case 2:
                    for(int i=0;i<t_count;i++){
                        Teachers[i].displayteacher();
                       }
                        break;
                    case 3:
                        cout<<"you choosed option 3"<<endl;
                        break;
                    case 4:
                        cout<<"you choosed option 4"<<endl;
                        break;
                    case 5:
                        cout<<"you choosed option 5"<<endl;
                        break;
                     case 6:
                        cout<<"exiting"<<endl;
                        break;
                    default:
                        cout<<"you made invalid choice"<<endl;
                        break;

                }

            }while(ch2!=6);
        }else if(choice==3){
            int ch3=0;
            do{
                cout<<"-------------------------------"<<endl;
                cout<<"1.add course"<<endl;
                cout<<"2.display courses"<<endl;
                cout<<"3.update course"<<endl;
                cout<<"4.remove course"<<endl;
                cout<<"5.find course"<<endl;
                cout<<"6.back to main menu"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"enter your choice :";
                cin>>ch3;

                switch(ch3){
                    case 1:
                    courses[co_count].addcourse( Teachers , t_count);
                       co_count++;
                    cout<<"course added successfully !"<<endl;
                       break;
                   case 2:
                   for(int i=0;i<co_count;i++){
                    courses[i].displaycourse();
              }
                       break;
                   case 3:
                       cout<<"you choosed option 3"<<endl;
                       break;
                   case 4:
                       cout<<"you choosed option 4"<<endl;
                       break;
                   case 5:
                       cout<<"you choosed option 5"<<endl;
                       break;
                    case 6:
                        cout<<"exiting"<<endl;
                        break;
                   default:
                       cout<<"you made invalid choice"<<endl;
                       break;

               }
            }while(ch3!=6);
            
        }else if(choice==4){
            int ch4=0;
            do{
                cout<<"-------------------------------"<<endl;
                cout<<"1.add class room"<<endl;
                cout<<"2.display class room"<<endl;
                cout<<"3.update classroom information"<<endl;
                cout<<"4.remove all classrooms"<<endl;
                cout<<"5.find classroom"<<endl;
                cout<<"6.back to main menu"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"enter your choice :";
                cin>>ch4;

                switch(ch4){
                    case 1:
                       Classroom[cr_count].addclassroom(courses,co_count);
                       cr_count++;
                       break;
                   case 2:
                        for(int i=0;i<cr_count;i++){
                         Classroom[i].displayclassroom();
                   }
                       break;
                   case 3:
                       cout<<"you choosed option 3"<<endl;
                       break;
                   case 4:
                       cout<<"you choosed option 4"<<endl;
                       break;
                   case 5:
                       cout<<"you choosed option 5"<<endl;
                       break;
                    case 6:
                        cout<<"exiting"<<endl;
                        break;
                   default:
                       cout<<"you made invalid choice"<<endl;
                       break;

               }
            }while(ch4!=6);
            
        }else if(choice==5){
            int ch5=0;
            do{
                cout<<"-------------------------------"<<endl;
                cout<<"1.add registration"<<endl;
                cout<<"2.display registration"<<endl;
                cout<<"3.update registration"<<endl;
                cout<<"4.remove registration"<<endl;
                cout<<"5.find registration"<<endl;
                cout<<"6.back to main menu"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"enter your choice :";
                cin>>ch5;

                switch(ch5){
                    case 1:
                    reg[r_count].addregistration(Students,st_count,courses,co_count);
                    r_count++;
                       break;
                   case 2:
                   for(int i=0;i<r_count;i++){
                    reg[i].displayregistration();
              }
                       break;
                   case 3:
                       cout<<"you choosed option 3"<<endl;
                       break;
                   case 4:
                       cout<<"you choosed option 4"<<endl;
                       break;
                   case 5:
                       cout<<"you choosed option 5"<<endl;
                       break;
                    case 6:
                        cout<<"exiting"<<endl;
                        break;
                   default:
                       cout<<"you made invalid choice"<<endl;
                       break;

               }
            }while(ch5!=6);
        }
    }while(choice!=6);

    return 0;
}

