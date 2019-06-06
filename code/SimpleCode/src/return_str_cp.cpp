#include <string>
#include <iostream>

std::string foo(const unsigned a)
{
    int b = 0;
    if (a)
        b = 1;
    else
        return "error";

    return "";
}

std::string foo2(const unsigned a)
{
    int b = 0;
    if (a)
        b = 1;
    else
        return "error";

    return "";
}

class theclass {
  public:
    void ref(std::string*& member) { member = &_member; }
    std::string read(const int member)
    {
        if (member)
            return _member;
        else
            return "";
    }

  private:
    std::string _member;
};

int main(const int, const char* [])
{
    std::string value("value");
    theclass     myclass;
    std::string* P = NULL;
    myclass.ref(P);
    myclass.read(0);

    *P = value;

    std::cout << *P << std::endl;
}
