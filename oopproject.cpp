#include<iostream>
#include<string>
#include<fstream>
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

    void setname(string n){
        name=n;
    }

    string getcontact() {
        return contact;
    }

    void setcontact(string c){
        contact=c;
    }

    string getaddress() {
        return address;
    }

    void setaddress(string n){
        address=n;
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

class Admin : public person {
    public:
        string username;
        string password;
    
        Admin() : person() {
            username = "";
            password = "";
        }
    
        Admin(string n, string c, string ad, string user, string pass) : person(n, c, ad) {
            username = user;
            password = pass;
        }
    
        bool login(string inputUsername, string inputPassword) {
            return (username == inputUsername && password == inputPassword);
        }
    
        void registerAdmin() {
            cout << "Enter Admin Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Contact: ";
            getline(cin, contact);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Admin registered successfully!" << endl;

            
        }


    
        void displayAdmin() {
            cout << "----------------------------------------" << endl;
            cout << "Admin Name: " << name << endl;
            cout << "Contact: " << contact << endl;
            cout << "Address: " << address << endl;
            cout << "Username: " << username << endl;
            cout << "----------------------------------------" << endl;
        }
    };


 class AdminCollection {
        public:
            Admin admins[100];
            int adminCount;
        
            AdminCollection() {
                adminCount = 0;
            }
        
            void addAdmin(Admin admin) {
                admins[adminCount] = admin;
                adminCount++;
                savedatatofile();
            }
        
            bool authenticateAdmin(string username, string password) {
                for (int i = 0; i < adminCount; i++) {
                    if (admins[i].login(username, password)) {
                        return true;
                    }
                }
                return false;
            }
        
            void registerNewAdmin() {
                Admin newAdmin;
                newAdmin.registerAdmin();
                addAdmin(newAdmin);
            }
        
            void displayAllAdmins() {
                for (int i = 0; i < adminCount; i++) {
                    admins[i].displayAdmin();
                }
            }

            void savedatatofile(){
                ofstream file("ADMIN.txt",ios::app);
                if(file.is_open()){
                    for(int i=0;i<adminCount;i++){
                        file<<admins[i].getName()<<endl;
                        file<<admins[i].getcontact()<<endl;
                        file<<admins[i].getaddress()<<endl;
                        file<<admins[i].username<<endl;
                        file<<admins[i].password<<endl;
                    }
                    file.close();
                }else{
                    cout<<"file not found !"<<endl;
                }
            }

            void loaddatafromfile() {
                ifstream file("ADMIN.txt");
                if (file.is_open()) {
                    while (true) {
                        Admin a;
                        string name, contact, address, username, password;
            
                        // Attempt to read all five lines
                        if (!getline(file, name)) break;
                        if (!getline(file, contact)) break;
                        if (!getline(file, address)) break;
                        if (!getline(file, username)) break;
                        if (!getline(file, password)) break;
            
                        a.setname(name);
                        a.setcontact(contact);
                        a.setaddress(address);
                        a.username = username;
                        a.password = password;
            
                        admins[adminCount] = a;
                        adminCount++;
                    }
                    file.close(); // Always good practice to close the file
                } else {
                    cerr << "Failed to open ADMIN.txt" << endl;
                }
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

class studentcollection{
    public:
    student Students[100];
    int count;
    studentcollection(){
        count=0;
    }

    void addstudenttocol(student s){
        Students[count]=s;
        count++;
        savestudenttofile();
    }

    void displayallstudents(){
        for(int i=0;i<count;i++){
            Students[i].displaystudent();
        }
    }

    void findstudent(int id){
        for(int i=0;i<count;i++){
            if(Students[i].roll_number == id){
                Students[i].displaystudent();
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void updatestudent(const int &roll_number) {
        for (int i = 0; i < count; i++) {
            if (Students[i].roll_number == roll_number) {
                cout << "Student found. Enter new details:" << endl;
                cout<<"enter the roll no or press 0:";
                int n_roll;
                cin>>n_roll;
                if(n_roll!=0){
                    Students[i].roll_number=n_roll;
                }
                cout<<"enter the name or press enter :";
                string sname;
                cin.ignore();
                getline(cin,sname);
                if(!sname.empty()){
                    Students[i].setname(sname);
                }
                cout<<"enter the contact or press enter :";
                string scontact;
                getline(cin,scontact);
                if(!scontact.empty()){
                    Students[i].setcontact(scontact);
                }
                cout<<"enter the address or press enter :";
                string saddress;
                getline(cin,saddress);
                if(!saddress.empty()){
                    Students[i].setaddress(saddress);
                }

                cout << "Student information updated successfully!" << endl;
                savestudenttofile();
                return;
            }
        }
        cout << "Student with roll number " << roll_number << " not found." << endl;
    }

    student* getstudentbyroll(int roll_number){
        for(int i=0;i<count;i++){
            if(Students[i].roll_number==roll_number){
                return &Students[i];
            }
        }
        return NULL;
    }
    void removestudent(){
        int id;
        cout<<"enter the student id to be removed : ";
        cin>>id;
        for(int i=0;i<count;i++){
            if(Students[i].roll_number==id){
                for(int j=i;j<count-1;j++){
                    Students[j]=Students[j+1];
                }
                count--;
                cout<<"student removed successfully !"<<endl;
                savestudenttofile();
                return;
            }
        }
        cout<<"student not found !"<<endl;
    }

    void savestudenttofile(){
        ofstream file("student.txt");
        if(file.is_open()){
            for(int i=0;i<count;i++){
                file<<Students[i].roll_number<<endl;
                file<<Students[i].getName()<<endl;
                file<<Students[i].getcontact()<<endl;
                file<<Students[i].getaddress()<<endl;
            }
            file.close();
        }
    }

    void loadstudentfromfile() {
        ifstream file("student.txt");
        if (file.is_open()) {
            while (true) {
                student s;
                int roll;
                string name, contact, address;
    
                // Read roll number
                if (!(file >> roll)) break;
                file.ignore(); // Ignore newline after reading roll
    
                // Read the remaining lines
                if (!getline(file, name)) break;
                if (!getline(file, contact)) break;
                if (!getline(file, address)) break;
    
                s.roll_number = roll;
                s.setname(name);
                s.setcontact(contact);
                s.setaddress(address);
    
                Students[count] = s;
                count++;
            }
            file.close();
        } else {
            cout << "File not found!" << endl;
        }
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

class teachercollection{
    public:
    teacher Teachers[100];
    int count;
    teachercollection(){
        count=0;
    }

    void addteachertocol(teacher t){
        Teachers[count]=t;
        count++;
        saveteachertofile();
    }

    void displayallteachers(){
        for(int i=0;i<count;i++){ 
            Teachers[i].displayteacher();
        }
    }

    void findteacher(int id){
        for(int i=0;i<count;i++){
            if(Teachers[i].t_id==id){
                Teachers[i].displayteacher();
                return;
            }
        }
        cout << "Teacher not found." << endl;
    }

    void updateteacher(const int &teacher_id) {
        for (int i = 0; i < count; i++) {
            if (Teachers[i].t_id == teacher_id) {
                cout << "Teacher found. Enter new details:" << endl;
                cout << "Enter new teacher ID or press 0 to skip: ";
                int new_id;
                cin >> new_id;
                if (new_id != 0) {
                    Teachers[i].t_id = new_id;
                }
                cin.ignore();
                cout << "Enter new name or press Enter to skip: ";
                string new_name;
                getline(cin, new_name);
                if (!new_name.empty()) {
                    Teachers[i].setname(new_name);
                }
                cout << "Enter new contact or press Enter to skip: ";
                string new_contact;
                getline(cin, new_contact);
                if (!new_contact.empty()) {
                    Teachers[i].setcontact(new_contact);
                }
                cout << "Enter new address or press Enter to skip: ";
                string new_address;
                getline(cin, new_address);
                if (!new_address.empty()) {
                    Teachers[i].setaddress(new_address);
                }
                cout << "Teacher information updated successfully!" << endl;
                saveteachertofile();
                return;
            }
        }
        cout << "Teacher with ID " << teacher_id << " not found." << endl;
    }

    teacher* getteacherbyid(int id){
        for(int i=0;i<=count;i++){
            if(Teachers[i].t_id==id){
                return &Teachers[i];
            }
        }
        return NULL;
    }
    void removeteacher(){
        int id;
        cout<<"enter the teacher id to be removed : ";
        cin>>id;
        for(int i=0;i<count;i++){
            if(Teachers[i].t_id==id){
                for(int j=i;j<count-1;j++){
                    Teachers[j]=Teachers[j+1];
                }
                count--;
                cout<<"teacher removed successfully !"<<endl;
                saveteachertofile();
                return;
            }
        }
        cout<<"teacher not found !"<<endl;
    }

    void saveteachertofile(){
        ofstream file("teacher.txt");
        if(file.is_open()){
            for(int i=0;i<count;i++){
                file<<Teachers[i].t_id<<endl;
                file<<Teachers[i].getName()<<endl;
                file<<Teachers[i].getcontact()<<endl;
                file<<Teachers[i].getaddress()<<endl;
            }
            file.close();
        }
    }
    void loadteacherfromfile() {
        ifstream file("teacher.txt");
        if (file.is_open()) {
            while (true) {
                teacher t;
                int id;
                string name, contact, address;
    
                // Read teacher ID
                if (!(file >> id)) break;
                file.ignore(); // Ignore newline after reading ID
    
                // Read the remaining lines
                if (!getline(file, name)) break;
                if (!getline(file, contact)) break;
                if (!getline(file, address)) break;
    
                t.t_id = id;
                t.setname(name);
                t.setcontact(contact);
                t.setaddress(address);
    
                Teachers[count] = t;
                count++;
            }
            file.close();
        } else {
            cout << "File not found!" << endl;
        }
    }
};

class course {
    public :
    string course_code;
    string course_title;
    int credit_hours;

    course(){
        course_code="";
        course_title="";
        credit_hours=0;
    }

    course(string code,string title,int credits){
        course_code=code;
        course_title=title;
        credit_hours=credits;

    }

    course(const course& crs){
        course_code=crs.course_code;
        course_title=crs.course_title;
        credit_hours=crs.credit_hours;
    }

    ~course(){

    }



    void displaycourse(){
        cout<<"----------------------------------------"<<endl;
        cout<<"course_code : "<<course_code<<endl;
        cout<<"course_title :"<<course_title<<endl;
        cout<<"credit_hours :"<<credit_hours<<endl;
        cout<<"----------------------------------------"<<endl;

    }


};

class coursecollection{
    public:
    course courses[100];
    int Ccount;
    coursecollection(){
        Ccount=0;
    }
    void addcourse(course c){
        courses[Ccount]=c;
        Ccount++;
        savecourse();
    }
    void displayallcourses(){
        for(int i=0;i<Ccount;i++){
            courses[i].displaycourse();   
        }
    }
    void findcourse(string code){
        for(int i=0;i<Ccount;i++){
            if(courses[i].course_code==code){
                courses[i].displaycourse();
                return;
            }
        }
        cout << "Course not found." << endl;
    }

    course* getcoursebycode(string code){
        for(int i=0;i<Ccount;i++){
            if(courses[i].course_code==code){
                return &courses[i];
            }
        }
        return NULL;
    }

    void removecourse(){
        string code;
        cout<<"enter the course code to be removed : ";
        cin>>code;
        for(int i=0;i<Ccount;i++){
            if(courses[i].course_code==code){
                for(int j=i;j<Ccount-1;j++){
                    courses[j]=courses[j+1];
                }
                Ccount--;
                cout<<"course removed successfully !"<<endl;
                savecourse();
                return;
            }
        }
        cout<<"course not found !"<<endl;
    }

    void savecourse(){
        ofstream file("course.txt");
        if(file.is_open()){
            for(int i=0;i<Ccount;i++){
                file<<courses[i].course_code<<endl;
                file<<courses[i].course_title<<endl;
                file<<courses[i].credit_hours<<endl;
            }
            file.close();
        }
    }
    void loadcoursefromfile() {
        ifstream file("course.txt");
        if (file.is_open()) {
            while (true) {
                course c;
                string code, title;
                int credits;
    
                // Read course code
                if (!getline(file, code)) break;
    
                // Read the remaining lines
                if (!getline(file, title)) break;
                if (!(file >> credits)) break;
                file.ignore(); // Ignore newline after reading credits
    
                c.course_code = code;
                c.course_title = title;
                c.credit_hours = credits;
    
                courses[Ccount] = c;
                Ccount++;
            }
            file.close();
        } else {
            cout << "File not found!" << endl;
        }
    }
};

class courseregistration{
    public:
    int reg_id;
    char section;
    course* crs;
    teacher* instructor;

    courseregistration(){
        section=' ';
        crs=nullptr;
        instructor=nullptr;
        reg_id=0;
    }

    courseregistration(char s,course* c,teacher* t, int id){
        section=s;
        crs=c;
        instructor=t;
        reg_id=id;
    }

    courseregistration(const courseregistration& cr){
        section=cr.section;
        crs=cr.crs;
        instructor=cr.instructor;
        reg_id=cr.reg_id;
    }

    ~courseregistration(){

    }

    void displayregcourse(){
        cout<<"----------------------------------------"<<endl;
        cout<<"course registration id :"<<reg_id<<endl;
        cout<<"section : "<<section<<endl;
        if(crs){
            cout<<"course title : "<<crs->course_title<<endl;
        }

        if(instructor){
            cout<<"instructor : "<<instructor->getName()<<endl;
        }
        cout<<"----------------------------------------"<<endl;
        
    }

    void displayregcoursename(){
        cout<<crs->course_title<<"-"<<section<<"("<<instructor->getName()<<")"<<endl;
    }



};

    teachercollection tcoll;
    coursecollection ccollection;

class courseregistrationcollection {
    public:
    courseregistration crsreg[100];
    int count;
    
    courseregistrationcollection(){
        count=0;
    }
    
    void addcrsregistration(courseregistration reg){
        crsreg[count] = reg;
        count++;
        savecrsregistrationtofile();
    }
    
    void displayallcrsregistrations(){
        for(int i=0; i<count; i++){
            crsreg[i].displayregcourse();
        }
    }
    
    void findcrsregistration(int reg_id){
        for(int i=0; i<count; i++){
            if(crsreg[i].reg_id == reg_id){
                crsreg[i].displayregcourse();
                return;
            }
        }
        cout << "Registration not found." << endl;
    }
    
    void removecrsregistration(int reg_id) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (crsreg[i].reg_id == reg_id) {
                found = true;
                for (int j = i; j < count - 1; j++) {
                    crsreg[j] = crsreg[j + 1];
                }
                count--;
                cout << "Course registration with ID " << reg_id << " removed successfully!\n";
                savecrsregistrationtofile();
                break;
            }
        }
        if (!found) {
            cout << "Course registration with ID " << reg_id << " not found.\n";
        }
    }

    courseregistration* getcrsregistrationbyid(int reg_id){
        for(int i=0;i<count;i++){
            if(crsreg[i].reg_id==reg_id){
                return &crsreg[i];
            }
        }
        return NULL;
    }

    void savecrsregistrationtofile(){
        ofstream file("courseregistration.txt");
        if(file.is_open()){
            for(int i=0;i<count;i++){
                file<<crsreg[i].reg_id<<endl;
                file<<crsreg[i].section<<endl;
                file<<crsreg[i].crs->course_code<<endl;
                file<<crsreg[i].instructor->t_id<<endl;
            }
            file.close();
        }
    }

    void loadcrsregistrationfromfile() {
        ifstream file("courseregistration.txt");
        if (file.is_open()) {
            while (true) {
                courseregistration cr;
                int reg_id, instructor_id;
                string section, course_code;
    
                // Read registration ID
                if (!(file >> reg_id)) break;
                file.ignore(); // Ignore newline after reading reg_id
    
                // Read the remaining lines
                if (!getline(file, section)) break;
                if (!getline(file, course_code)) break;
                if (!(file >> instructor_id)) break;
                file.ignore(); // Ignore newline after reading instructor_id
    
                cr.reg_id = reg_id;
                cr.section = section[0]; // Assuming section is a single character
                
                
                 cr.crs = ccollection.getcoursebycode(course_code); 
                 cr.instructor =tcoll.getteacherbyid(instructor_id); 
    
                crsreg[count] = cr;
                count++;
            }
            file.close();
        } else {
            cout << "File not found!" << endl;
        }
    }
};

class Classrooms{

    public:
    int room_no;
    courseregistration* c;


    Classrooms(){
        room_no=0;
        c=nullptr;
    }

    Classrooms( int room,courseregistration* cr){

        room_no=room_no;
        c=cr;
    }

    Classrooms(const Classrooms& cr){
        room_no=cr.room_no;
        c=cr.c;;


    }



    void displayclassroom(){
        cout<<"----------------------------------------"<<endl;
        cout<<"room_no :"<<room_no<<endl;
        if(c){
            cout << "registered course  : ";
            c->displayregcoursename();
            cout << endl;
        }
        cout<<"----------------------------------------"<<endl;
    }

};
courseregistrationcollection crsregcoll;
class classroomcollection{
    public:
    Classrooms Classroom[100];
    int count;
    classroomcollection(){
        count=0;
    }
    void addclassroom(Classrooms cr){
        Classroom[count]=cr;
        count++;
        saveclassroomtofile();
    }
    void displayallclassrooms(){
        for(int i=0;i<count;i++){
            Classroom[i].displayclassroom();
        }
    }
    void findclassroom(int room_no){
        for(int i=0;i<count;i++){
            if(Classroom[i].room_no==room_no){
                Classroom[i].displayclassroom();
                return;
            }
        }
        cout << "Classroom not found." << endl;
    }
    Classrooms* getclassroombyroomno(int room_no){
        for(int i=0;i<count;i++){
            if(Classroom[i].room_no==room_no){
                return &Classroom[i];
            }
        }
        return NULL;
    }

    void removeclassroom(int room_no) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (Classroom[i].room_no == room_no) {
                found = true;
                for (int j = i; j < count - 1; j++) {
                    Classroom[j] = Classroom[j + 1];
                }
                count--;
                cout << "Classroom with room number " << room_no << " removed successfully!\n";
                saveclassroomtofile();
                break;
            }
        }
        if (!found) {
            cout << "Classroom with room number " << room_no << " not found.\n";
        }
    }

    void saveclassroomtofile(){
        ofstream file("classroom.txt");
        if(file.is_open()){
            for(int i=0;i<count;i++){
                file<<Classroom[i].room_no<<endl;
                file<<Classroom[i].c->reg_id<<endl;
            }
            file.close();
        }
    }
    void loadclassroomfromfile() {
        ifstream file("classroom.txt");
        if (file.is_open()) {
            while (true) {
                Classrooms cr;
                int room_no, reg_id;
    
                // Read room number
                if (!(file >> room_no)) break;
                file.ignore(); // Ignore newline after reading room_no
    
                // Read the remaining lines
                if (!(file >> reg_id)) break;
                file.ignore(); // Ignore newline after reading reg_id
    
                cr.room_no = room_no;
                cr.c = crsregcoll.getcrsregistrationbyid(reg_id); 
    
                Classroom[count] = cr;
                count++;
            }
            file.close();
        } else {
            cout << "File not found!" << endl;
        }
    }

};



class registration{
       public:
       int registration_id;
       student* Student;
       DATE registration_date;
       courseregistration* crs;

       registration(){
        registration_id=0;
        Student=nullptr;
        crs=nullptr;
       }

       registration(int id,student* std,DATE rd,courseregistration* c){
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
       void displayregistration(){
        cout<<"----------------------------------------"<<endl;
        cout<<"registration_id :"<<registration_id<<endl;
        if(Student){
            cout<<"student name : "<<Student->getName()<<endl;
        }
        registration_date.displaydate();
        if(crs){
            cout<<"course registration :";
            crs->displayregcoursename();
            cout<<endl;
        }
        cout<<"----------------------------------------"<<endl;
       }

};

studentcollection stcoll;

class registrationcollection{
    public:
    registration rarray[100];
    int count;
    registrationcollection(){
        count=0;
    }
    void addregistrationtocol(registration r){
            rarray[count] = r;
            count++;
            cout << "Registration added successfully!" << endl;
            saveregistrationtofile();
    }
    void displayallregistrations(){
        for(int i=0;i<count;i++){
            rarray[i].displayregistration();
        }
    }
    void findregistration(int id){
        for(int i=0;i<count;i++){
            if(rarray[i].registration_id==id){
                rarray[i].displayregistration();
                return;
            }
        }
        cout << "Registration not found." << endl;
    }
    void remove_registration(int id) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (rarray[i].registration_id == id) {
                found = true;
                for (int j = i; j < count - 1; j++) {
                    rarray[j] = rarray[j + 1];
                }
                count--;
                cout << "Registration with ID " << id << " removed successfully!\n";
                saveregistrationtofile();
                break;
            }
        }
        if (!found) {
            cout << "Registration with ID " << id << " not found.\n";
        }
    }
    registration* getregistrationbyid(int id){
        for(int i=0;i<count;i++){
            if(rarray[i].registration_id==id){
                return &rarray[i];
            }
        }
        return NULL;
    }
    void saveregistrationtofile(){
        ofstream file("registration.txt");
        if(file.is_open()){
            for(int i=0;i<count;i++){
                file<<rarray[i].registration_id<<endl;
                file<<rarray[i].Student->roll_number<<endl;
                file<<rarray[i].registration_date.dd<<endl;
                file<<rarray[i].registration_date.mm<<endl;
                file<<rarray[i].registration_date.yyyy<<endl;
                file<<rarray[i].crs->reg_id<<endl;
            }
            file.close();
        }
    }
    void loadregistrationfromfile() {
        ifstream file("registration.txt");
        if (file.is_open()) {
            while (true) {
                registration r;
                int reg_id, student_roll, crs_reg_id;
                DATE reg_date;
    
                // Read registration ID
                if (!(file >> reg_id)) break;
                file.ignore(); // Ignore newline after reading reg_id
    
                // Read the remaining lines
                if (!(file >> student_roll)) break;
                if (!(file >> reg_date.dd)) break;
                if (!(file >> reg_date.mm)) break;
                if (!(file >> reg_date.yyyy)) break;
                if (!(file >> crs_reg_id)) break;
    
                r.registration_id = reg_id;
                r.Student = stcoll.getstudentbyroll(student_roll); 
                r.registration_date = reg_date;
                r.crs = crsregcoll.getcrsregistrationbyid(crs_reg_id); 
    
                rarray[count] = r;
                count++;
            }
            file.close();
        } else {
            cout << "File not found!" << endl;
        }
    }


};

    AdminCollection adminCollection;
    
    
    classroomcollection crcollection;
    registrationcollection regcoll;
    

int main(){
    
    adminCollection.loaddatafromfile();
    stcoll.loadstudentfromfile();
    tcoll.loadteacherfromfile();
    ccollection.loadcoursefromfile();
    crsregcoll.loadcrsregistrationfromfile();
    crcollection.loadclassroomfromfile();
    
    

    int adminChoice;
    do{
        cout << "===== Admin System =====" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register New Admin" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;

        if (adminChoice == 1) {
            if (adminCollection.adminCount == 0) {
                cout << "No admins registered. Please register an admin first." << endl;
                continue;
            }

            string username, password;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            if (adminCollection.authenticateAdmin(username, password)) {
                cout << "Login successful! Welcome, " << username << "." << endl;

    
    int choice=0;

    do{
        system("cls");
        cout<<"\t=================================="<<endl;
        cout<<"\t=====School Management System====="<<endl;
        cout<<"\t=================================="<<endl<<endl;
        cout<<"=================================="<<endl;
        cout<<" 1.manage students"<<endl;
        cout<<" 2.manage teachers"<<endl;
        cout<<" 3.manage courses"<<endl;
        cout<<" 4.manage course registration"<<endl;
        cout<<" 5.manage classrooms"<<endl;
        cout<<" 6.manage student registration"<<endl;
        cout<<" 7.Exit"<<endl;
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
                        {
                            student s;
                            s.AddStudent();
                            stcoll.addstudenttocol(s);}
                           break;

                       case 2:
                           stcoll.displayallstudents();
                           break;
                       case 3:
                       {
                            int id;
                            cout << "Enter Student ID to update: ";
                            cin >> id;
                           stcoll.updatestudent(id);
                          }
                           break;
                       case 4:
                           stcoll.removestudent();
                           break;
                       case 5:
                           {
                            int id;
                            cout<<"enter id to be searched :";
                            cin>>id;
                            stcoll.findstudent(id);
                           }
                           break;
                        case 6:
                            cout<<"exiting"<<endl;
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
                    { teacher t;
                     t.addteacher();
                     tcoll.addteachertocol(t);}
                        break;
                    case 2:
                    tcoll.displayallteachers();
                        break;
                    case 3:
                        {
                            int id;
                            cout << "Enter Teacher ID to update: ";
                            cin >> id;
                            tcoll.updateteacher(id);
                        }
                        break;
                    case 4:
                        tcoll.removeteacher();
                        break;
                    case 5:
                        {
                            int id;
                            cout<<"enter id to be searched :";
                            cin>>id;
                            tcoll.findteacher(id);
                        }
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
                    {
                      course c;
                      cout<<"=========== ADD COURSE=======\n";
                      cout<<"Enter course code:";
                      cin>>c.course_code;
                      cin.ignore();
                      cout<<"Enter course title:";
                        getline(cin,c.course_title);
                        cout<<"Enter credit hours:";
                        cin>>c.credit_hours;
                        ccollection.addcourse(c);
                        
                    }
                       break;
                   case 2:
                          ccollection.displayallcourses();
                       break;
                   case 3:
                   {
                        string code;
                        cout << "Enter course code to update: ";
                        cin>>code;
                        cin.ignore();
                        course* crs=ccollection.getcoursebycode(code);
                        if(crs != NULL){
                            cout << "Enter new course title or press enter to skip: ";
                            string title;
                            getline(cin,title);
                            if(!title.empty()){
                                crs->course_title=title;
                            }
                            cout << "Enter new credit hours or press 0 to skip: ";
                            int hrs;
                            if(hrs!=0){
                                cin >> hrs;
                                crs->credit_hours=hrs;
                            }
                            cin.ignore();
                            cout << "Course updated successfully!" << endl;
                            ccollection.savecourse();
                        }else{
                            cout << "Course not found." << endl;
                        }
                   }
                       break;
                   case 4:
                         ccollection.removecourse();
                        break;
                   case 5:
                        {
                            string code;
                            cout<<"enter course code to be searched :";
                            cin>>code;
                            ccollection.findcourse(code);
                        }
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
                cout<<"1.add course registration"<<endl;
                cout<<"2.display course registration"<<endl;
                cout<<"3.update course registration"<<endl;
                cout<<"4.remove course registration"<<endl;
                cout<<"5.find course registration"<<endl;
                cout<<"6.back to main menu"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"enter your choice :";
                cin>>ch4;

                switch(ch4){
                    case 1:
                    {
                        courseregistration c;
                      cout<<"=========== ADD COURSE REGISTRATION ==========\n";
                      cout<<"Enter course registration id:";
                        cin>>c.reg_id;
                        cin.ignore();
                      cout<<"Enter section:";
                      cin>>c.section;
                      cout<<"Enter course code:";
                        string code;
                        cin>>code;
                        course* crs=ccollection.getcoursebycode(code);
                        if(crs != NULL){
                            c.crs = crs;
                        }else{
                            cout<<"Course not found."<<endl;
                        }
                        int tid;
                        cout<<"enter instructor id :";
                        cin>>tid;
                        teacher* teacher_ptr = tcoll.getteacherbyid(tid);
                        
                        if(teacher_ptr != NULL){
                            c.instructor = teacher_ptr;
                        }else{
                            cout<<"invalid id !"<<endl;
                        }
                        crsregcoll.addcrsregistration(c);
                        cout<<"course registered successfully !"<<endl;
                        
                    }
                       break;
                   case 2:
                            crsregcoll.displayallcrsregistrations();
                       break;
                   case 3:
                   {
                        int id;
                        cout << "Enter course registration ID to update: ";
                        cin >> id;
                        courseregistration* crs=crsregcoll.getcrsregistrationbyid(id);
                        if(crs != NULL){
                            cout << "Enter new section or press space to skip: ";
                            char section;
                            cin >> section;
                            if(section != ' '){
                                crs->section = section;
                            }
                            cout << "Enter new course code or press enter to skip: ";
                            string code;
                            cin.ignore();
                            getline(cin, code);
                            if(!code.empty()){
                                course* c = ccollection.getcoursebycode(code);
                                if(c != NULL){
                                    crs->crs = c;
                                    
                                }else{
                                    cout << "Course not found." << endl;
                                }
                            }
                            cout << "Enter new instructor ID or press 0 to skip: ";
                            int t_id;
                            cin>>t_id;
                            if(t_id!=0){
                                teacher* teacher_ptr = tcoll.getteacherbyid(t_id);
                                if(teacher_ptr != NULL){
                                    crs->instructor = teacher_ptr;

                                }else{
                                    cout<<"instructor not found !"<<endl;
                                }
                            }
                            cout << "Course registration updated successfully!" << endl;
                            crsregcoll.savecrsregistrationtofile();
                        }
                   }
                       break;
                   case 4:
                        {
                            int id;
                            cout<<"enter course registration id to be removed :";
                            cin>>id;
                            crsregcoll.removecrsregistration(id);
                        }
                        break;
                   case 5:
                        {
                            int id;
                            cout<<"enter course registration id to be searched :";
                            cin>>id;
                            crsregcoll.findcrsregistration(id);
                        }
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
                cout<<"1.add class room"<<endl;
                cout<<"2.display class room"<<endl;
                cout<<"3.update classroom information"<<endl;
                cout<<"4.remove all classrooms"<<endl;
                cout<<"5.find classroom"<<endl;
                cout<<"6.back to main menu"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"enter your choice :";
                cin>>ch5;

                switch(ch5){
                    case 1:
                       {
                        Classrooms cl;
                        cout<<"=========== ADD CLASSROOM=======\n";
                      cout<<"Enter room no:";
                      cin>>cl.room_no;
                      cout<<"Enter course registration id:";
                        int id;
                        cin>>id;
                        courseregistration* crs=crsregcoll.getcrsregistrationbyid(id);
                        if(crs != NULL){
                            cl.c = crs;
                        }else{
                            cout << "Course registration not found." << endl;
                        }
                       
                          crcollection.addclassroom(cl);
                          cout<<"class room added successfully !"<<endl;
                          }
                       break;
                   case 2:
                          crcollection.displayallclassrooms();
                       break;
                   case 3:
                        {
                            int room_no;
                            cout << "Enter room number to update: ";
                            cin >> room_no;
                            Classrooms* crs=crcollection.getclassroombyroomno(room_no);
                            if(crs != NULL){
                                cout << "Enter new registration id or press 0 to skip : ";
                                int id;
                                cin >> id;
                                if(id != 0){
                                    courseregistration* c = crsregcoll.getcrsregistrationbyid(id);
                                    if(c != NULL){
                                        crs->c = c;
                                        cout << "Classroom updated successfully!" << endl;
                                        crcollection.saveclassroomtofile();
                                    }else{
                                        cout << "Course registration not found." << endl;
                                    }
                                }else{
                                    cout << "Classroom not found." << endl;
                                }

                            }
                        }
                       break;
                   case 4:
                          {
                            int room_no;
                            cout<<"enter room number to be removed :";
                            cin>>room_no;
                            crcollection.removeclassroom(room_no);
                          }
                       break;
                   case 5:
                          {
                            int room_no;
                            cout<<"enter room number to be searched :";
                            cin>>room_no;
                            crcollection.findclassroom(room_no);
                          }
                       break;
                    case 6:
                        cout<<"exiting"<<endl;
                        break;
                   default:
                       cout<<"you made invalid choice"<<endl;
                       break;

               }

            }while(ch5!=6);
        }else if(choice==6){
            int ch6=0;
            do{
                cout<<"-------------------------------"<<endl;
                cout<<"1.add  student registration"<<endl;
                cout<<"2.display student registration"<<endl;
                cout<<"3.update student registration"<<endl;
                cout<<"4.remove student registration"<<endl;
                cout<<"5.find student registration"<<endl;
                cout<<"6.back to main menu"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"enter your choice :";
                cin>>ch6;

                switch(ch6){
                    case 1:
                        {
                            registration r;
                            cout<<"=========== ADD  STUDENT REGISTRATION=======\n";
                            cout<<"Enter student registration id:";
                            cin>>r.registration_id;
                                cout<<"Enter student roll number:";
                                int roll_number;
                                cin>>roll_number;
                                student* student_ptr = stcoll.getstudentbyroll(roll_number);
                            if(student_ptr != NULL){
                                r.Student = student_ptr;
                            }else{
                                cout << "Student not found." << endl;
                            }
                            DATE d;
                            cout<<"Enter registration date (dd mm yyyy): ";
                            d.adddate();

                            cout<<"Enter course registration id:";
                            int id;
                            cin>>id;
                            courseregistration* crs=crsregcoll.getcrsregistrationbyid(id);
                            if(crs != NULL){
                                r.crs = crs;
                                
                            }else{
                                cout << "Course not found." << endl;
                            }
                            r.registration_date = d;
                            regcoll.addregistrationtocol(r);
                            }
                       break;
                   case 2:
                    regcoll.displayallregistrations();
                       break;
                   case 3:
                            {
                                int id;
                                cout << "Enter registration ID to update: ";
                                cin >> id;
                                registration* reg=regcoll.getregistrationbyid(id);
                                if(reg!=NULL){
                                    cout<<"enter new roll number or press 0 to skip :";
                                    int roll_number;
                                    cin>>roll_number;
                                    if(roll_number!=0){
                                        student* student_ptr = stcoll.getstudentbyroll(roll_number);
                                        if(student_ptr != NULL){
                                            reg->Student = student_ptr;   
                                        }else{
                                            cout << "Student not found." << endl;
                                        }
                                    }
                                    DATE d;
                                    cout<<"Enter registration date (dd mm yyyy): ";
                                    d.adddate();
                                    cout<<"Enter new course registration id or press 0 to skip:";
                                    int id;
                                    cin>>id;
                                    if(id!=0){
                                    courseregistration* crs=crsregcoll.getcrsregistrationbyid(id);
                                    if(crs != NULL){
                                        reg->crs = crs;
                                       
                                    }else{
                                        cout << "Course not found." << endl;
                                    }
                                    }
                                    reg->registration_date = d;
                                    cout << " student Registration updated successfully!" << endl;
                                    regcoll.saveregistrationtofile();
                                }else{
                                    cout << "student Registration not found." << endl;

                                }
                            }
                       break;
                   case 4:
                          {
                             int id;
                             cout<<"enter registration id to be removed :";
                             cin>>id;
                             regcoll.remove_registration(id);
                              }
                       break;
                   case 5:
                            {
                                int id;
                                cout<<"enter registration id to be searched :";
                                cin>>id;
                                regcoll.findregistration(id);
                            }
                       break;
                    case 6:
                        cout<<"exiting"<<endl;
                        break;
                   default:
                       cout<<"you made invalid choice"<<endl;
                       break;

               }
            }while(ch6!=6);
        }else if (choice ==7){
            cout<<"program terminating ..... !"<<endl;
        }
    }while(choice!=7);

} else {
    cout << "Invalid username or password. Try again." << endl;
}
} else if (adminChoice == 2) {
adminCollection.registerNewAdmin();
} else if (adminChoice == 3) {
cout << "Exiting Admin System..." << endl;
} else {
cout << "Invalid choice. Please try again." << endl;
}
} while (adminChoice != 3);

    return 0;
}



