#include <iostream>
using namespace std;

int sumTail(int n, int total = 0) {
    if (n == 0) return total;   
    return sumTail(n - 1, total + n); 
}

int sumNonTail(int n){
    if(n==0){
        return 0;
    }
    return n + sumNonTail(n);
}

int main(){
    int n=3;
    int tailResult = sumTail(n, 0);
    int nonTailResult = sumNonTail(n);

    cout << "Sum using tail recursion: " << tailResult << endl;
    cout << "Sum using tail recursion: " << tailResult << endl;

    return 0;


}