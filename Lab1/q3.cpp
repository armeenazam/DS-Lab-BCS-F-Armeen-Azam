#include<iostream>
#include<string>
using namespace std;

class Box{
private:
    int *width;
public:
    Box(int n){
        width = new int(n);
    }    

    Box (const Box &other){
        width = new int(*other.width);
    }
/* if we comment the above copy constructor and use the default one, it will create a shallow copy and both objects will point to the same memory location.
If we modify one object, it will affect the other object as well. and when both objects are destroyed, it will lead to double deletion of the same memory location, causing undefined behavior.*/
    
    ~Box(){
        delete width;
    }

    void showWidth(){
        cout << "Width: " << *width << endl;
    }

    void modifyWidth(int w){
        *width = w;
    }
};

int main(){
    Box box1(10);
    Box box2 = box1;
    box2.modifyWidth(20);
    cout << "After modifying box2:" << endl;
    box2.showWidth();
    cout <<endl;
    box1.showWidth(); // box1 width will not be affected due to deep copy
    return 0;

}