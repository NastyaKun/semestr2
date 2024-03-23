#include <iostream>
#include <cstring>

class String {
private:
    char* str;
public:
    String(const char* s = "") 
    {  
        str = new char[strlen(s) + 1];
        std::strcpy(str, s);
    }

    String(const String& other)
    {  
        str = new char[strlen(other.str) + 1];
        std::strcpy(str, other.str);
    }

    String& operator=(const String& other) 
    {
        if (this != &other) 
        {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    ~String()
    {
        delete[] str;
    }

    void print() 
    {
        std::cout << str << std::endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    String str1("Копирование");
    String str2 = str1;
    String str3 = str1;

    std::cout << "str1: ";
    str1.print();
    std::cout << "str2: ";
    str2.print();
    std::cout << "str3: ";
    str3.print();

    return 0;
}
