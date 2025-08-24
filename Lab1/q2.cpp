#include <iostream>
#include<cstring>
using namespace std;

class Exam{
private:
    char *studentName;
    char *examDate;
    double *score;

public:
    Exam(){
        studentName = new char[50];
        examDate = new char[20];
        strcpy(studentName, "John Doe");
        strcpy(examDate, "24-08-2025");
        score = new double();
    }    

    void setAttributes(const char *name, const char *date, double sc){
        strcpy(studentName, name);
        strcpy(examDate, date);
        *score = sc;
    }

    void displayDetails(){
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << *score << endl;
    }

    ~Exam(){
        delete[] studentName;
        delete[] examDate;
        delete score;
    }
};

int main(){
    Exam exam1;
    exam1.setAttributes("Armeen", "15-03-2025", 95.5);
    exam1.displayDetails();
    cout << endl;
     
    Exam exam2 = exam1; 
    exam2.displayDetails();
    cout << endl;

    exam2.setAttributes("Manahil", "16-04-2025", 88.0); /*since we are not using copy constructor, 
                                                         it will create a shallow copy and both objects 
                                                         will point to the same memory location.*/
    cout << "After modifying exam2:" << endl;
    exam2.displayDetails();  /*modifying exam2 details will also modify exam1 details too due to shallo copy*/
    cout << endl;
    exam1.displayDetails(); 

    return 0;
}