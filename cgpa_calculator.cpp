#include <iostream>
#include <vector>
using namespace std;
        // Subject class 
class Subject
{
public:
        string subjectname;
        int credit;
        float gradepoint;

        // constructor

        Subject(string name , int cr , float gp)
        {
            subjectname = name ;
            credit = cr;
            gradepoint = gp;
        }      
};

        //Student class 
class Student{
 private:
         string studentname;
        vector <Subject>subjects; //(Here the subjects is object of vectore class) 

public:
        // constructor
        Student(string name)
        {
                studentname = name;
        }
        // Function to add subject 

        void addSubject(
                string subname,
                int credit,
                float gradepoint
                        ) 
        {
                subjects.push_back( // (And here vector class ke object me hum function bnate h jo we needed...)
                        Subject(subname, credit, gradepoint)
                );
        }

        // Function to calculate CGPA 
        float calculatecgpa(){

        float totalpoints = 0;
        int totalcredits = 0;

        for(int i = 0; i<subjects.size(); i++)
        {
                totalpoints += subjects[i].credit * subjects[i].gradepoint;
                totalcredits += subjects[1].credit;
         }

         if (totalcredits == 0)
         {
                return 0;
         }

          float cgpa = totalpoints / totalcredits;
          return cgpa;
}

// Function to Display Result 
void displaycgpa()
{
        cout<<"\nStudent Name :"<<studentname <<endl;

        cout<<"\nSubjects Entered :\n";

        for (int i = 0; i < subjects.size(); i++)
        {
                cout<<subjects[i].subjectname 
                << "(Credit: "
                << subjects[i].credit
                << " , Grade point: "
                << subjects[i].gradepoint
                << ") "<<endl;
        }

        cout<< "\nCGPA :" <<calculatecgpa()<<endl;
        
}
};


int main()
{
        string studentname;
        cout<<"Enter Student Name: ";
        cin>>studentname;
        // Student Object
        Student student(studentname) ;

        int n;
        cout<<"Enter Number of Subjects :";
        cin>> n;

        for (int i = 0; i < n; i++)
        {
                string subname;
                int credit;
                float gradepoint;

                cout<<"\nEnter Subject Name :";
                cin>>subname;

                cout<<"\n Enter Credit :";
                cin>> credit;

                cout<<"\n Enter Grade point :";
                cin>> gradepoint;

                // Add Subjects 
                student.addSubject(
                        subname,
                        credit,
                        gradepoint
                );
        }

        // Display CGPA
        student.displaycgpa();
         
        return 0;
        
}
