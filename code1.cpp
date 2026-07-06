#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number  of Subjects "<<endl;
    cin>>n;
    string subname[n];
    float grades [n];
    int credits  [n];

    float totalgrades = 0;
    int totalcredits = 0;

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Subject Name: ";
        cin>> subname[i];

        cout<<"Enter Credit: ";
        cin>> credits[i];

        cout<<"Enter Grade Point: ";
        cin>> grades[i];

        totalgrades= totalgrades + grades[i] * credits[i]; 
        totalcredits += credits[i];
    }
    
    float SGPA = totalgrades / totalcredits;
    
    float cgpa = SGPA ; 
    cout<<"\nSubjects Entered:"<<endl;  

    for(int i = 0; i < n; i++){
        cout<< subname[i] <<endl;
    }

    cout<<"\n CGPA = " <<cgpa;

}