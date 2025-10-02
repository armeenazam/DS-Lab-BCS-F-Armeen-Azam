#include <iostream>
using namespace std;

int ackermann(int m, int n){
    if (m == 0) return n+1;

    if(m > 0 && n == 0 ) return ackermann(m-1, 1);

    if (m > 0 && n > 0) return ackermann(m-1, ackermann(m, n-1));


}

int main(){
    int m, n;
    cout << "Enter two non-negative integers (m and n): ";
    cin >> m >> n;

    if (m < 0 || n < 0) {
        cout << "Please enter non-negative integers only." << endl;
        return 1;
    }

    int result = ackermann(m, n);
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;

}