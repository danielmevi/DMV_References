/*
 *
 */

class MyClass {
 public:
    MyClass() = default;
    MyClass(const MyClass&) = delete;
    MyClass(const MyClass&&) = delete;
    MyClass& operator=(const MyClass&) = default;
    MyClass& operator=(MyClass&&) = delete;

    MyClass(int) { MyClass(); }
    MyClass(int aa, int bb) : a(aa), b(bb) {}

    virtual void foo();
    virtual void foo2() final;

 private:
    int a = 5;
    int b = 6;
    int c = 10;
};

class Derived : MyClass {
    void foo() override;
};
