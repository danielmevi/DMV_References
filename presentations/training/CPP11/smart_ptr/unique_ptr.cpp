/*
 */

#include <memory>

struct MyClass{
    explicit MyClass(int, bool){}
};


int main(const int, const char* const[]){
    

    int* ptr = new int(5);
    auto ptr1 = std::make_unique<int>(5);
    std::unique_ptr<int> ptr2(new int);
    
    MyClass* ptr3 = new MyClass(5,false);
    auto ptr4 = std::make_unique<MyClass>(5,false);
    std::unique_ptr<MyClass> ptr5(new MyClass(5, false));

    int* ptr6 = new int[10];
    auto ptr7 = std::make_unique<int[]>(10);
    std::unique_ptr<int[]> ptr8(new int[10]);


    return 1;


}
