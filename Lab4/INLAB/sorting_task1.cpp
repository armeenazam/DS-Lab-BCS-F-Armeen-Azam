#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"How many numbers do you want to enter? ";
    cin>>n;

    int arr[100];
    cout<<"Enter "<<n<<" numbers: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"Numbers you entered: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    for(int pass=0;pass<n-1;pass++){
        for(int j=0;j<n-pass-1;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    cout<<"Numbers arranged from biggest to smallest: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
