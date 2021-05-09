#include <bits/stdc++.h>

using namespace std;

class Person
{
protected:
    char name[50];
    int age;

public:
    Person()
    {
        strcpy(name, "Default");
        age = 0;
    }
    Person(char *n)
    {
        strcpy(name, n);
        age = 18;
    }
    Person(char *n, int a)
    {
        strcpy(name, n);
        age = a;
    }
    Person(Person &obj)
    {
        strcpy(name, obj.name);
        age = obj.age;
    }
};

class Student : public Person
{
    float cgpa;

public:
    Student(char *name, float cg) : Person(name)
    {
        cgpa = cg;
    }
    Student(char *name, float cg, int age) : Person(name, age)
    {
        cgpa = cg;
    }
    void display()
    {
        cout << "\nName :" << this->name;
        cout << "\nCGPA :" << this->cgpa;
        cout << "\nAge:" << this->age;
        return;
    }
};

class Prof : public Person
{
    int publi;

public:
    Prof(char *name, int pub) : Person(name)
    {
        publi = pub;
    }
    Prof(char *name, int pub, int age) : Person(name, age)
    {
        publi = pub;
    }
    void display()
    {
        cout << "\nName :" << this->name;
        cout << "\nPublications :" << this->publi;
        cout << "\nAge:" << this->age;
        return;
    }
};

int main()
{
    char n1[10] = "A";
    char n2[10] = "B";
    char n3[10] = "C";
    char n4[10] = "D";
    char n5[10] = "E";
    char n6[10] = "F";
    Student s1(n1, 6.1);
    s1.display();
    Student s2(n2, 4.5, 23);
    s2.display();
    Student s3(n3, 9.9, 22);
    s3.display();
    Prof p1(n4, 5, 50);
    p1.display();
    Prof p2(n5, 10);
    p2.display();
    Prof p3(n5, 15, 60);
    p3.display();
    return 0;
}