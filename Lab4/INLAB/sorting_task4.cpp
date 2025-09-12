#include <iostream>
#include <string>
using namespace std;
int getRank(string d) {
    if(d=="CEO") return 1;
    else if(d=="CTO") return 2;
    else if(d=="CFO") return 3;
    else if(d=="VP")  return 4;
    else if(d=="MGR") return 5;
    else return 6;
}
int main() {
    int total;
    cout<<"How many employees are in the list? ";
    cin>>total;

    string seat[100]; 
    cout<<"Enter the designations (CEO, CTO, CFO, VP, MGR, EMP): "<<endl;
    for(int i=0;i<total;i++) {
        cout<<"Employee "<<i+1<<": ";
        cin>>seat[i];
    }
    cout<<"\nEmployee order before sorting: ";
    for(int i=0;i<total;i++) cout<<seat[i]<<" ";
    cout<<endl;
    for(int i=1;i<total;i++){
        string current = seat[i];
        int j = i - 1;
        while(j >= 0 && getRank(seat[j]) > getRank(current)){
            seat[j+1] = seat[j];
            j--;
        }
        seat[j+1] = current;
    }
    cout<<"Employee order after sorting by priority: ";
    for(int i=0;i<total;i++) cout<<seat[i]<<" ";
    cout<<endl;

    return 0;
}
