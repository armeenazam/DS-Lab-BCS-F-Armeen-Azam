#include <iostream>
using namespace std;

class SafePointer{
private:
    int* ptr;
public:
    SafePointer() {
        ptr = new int(0);
    }
    
    ~SafePointer() {
        delete ptr;
    }

    void setValue(int value) {
        *ptr = value;
    }

    int getValue() const {
        if(ptr == nullptr) 
            return 0;
        return *ptr;
    }
    
    void release() {
        delete ptr;
        ptr = nullptr;
    }

};

int main(){
    SafePointer *sp = new SafePointer[5];
    sp[0].setValue(42);
    sp[1].setValue(84);
    sp[2].setValue(90);
    sp[3].setValue(100);
    sp[4].setValue(75);

    for (int i = 0; i < 5; i++) {
        cout << "Value at sp[" << i << "] = " << sp[i].getValue() << endl;
    }
    
    for (int i = 0; i < 5; i++) {
        sp[i].release();
    }
    
    delete[] sp;
    return 0;   


}