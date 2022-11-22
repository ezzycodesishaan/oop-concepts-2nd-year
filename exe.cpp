#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

class Account
{
public:
    int amt;
    int damt;
    int wamt;
    int camt;
    int wcamt;

    void virtual Deposit(Account){};
    void virtual Withdraw(Account){};
};
class Savings : public Account
{
public:
    void Deposit(Account a)
    {

        cout << "Enter the amount to be deposited" << endl;
        cin >> a.damt;
        a.amt = a.amt + a.damt;
        cout << "balance:" << a.amt;
    }
    void Withdraw(Account a)
    {

        cout << "Enter the amount to be withdrawn" << endl;
        cin >> a.wamt;
        if (a.wamt > a.amt)
        {
            cout << "amount cannot be withdrawn ";
        }
        else
        {
            cout << "amount with drawn";
        }
        a.amt = a.amt - a.wamt;
        cout << "balance:" << a.amt;
    }
};

class Current : public Account

{
public:
    void Deposit(Account a)
    {

        cout << "Enter the amount to be deposited" << endl;
        cin >> a.camt;
        a.amt = a.amt + a.camt;
        cout << "balance:" << a.amt;
    }
    void Withdraw(Account a)
    {

        cout << "Enter the amount to be withdrawn" << endl;
        cin >> a.wcamt;
        if (a.wcamt > a.amt)
        {
            cout << "amount cannot be withdrawn ";
        }
        else
        {
            cout << "amount with drawn";
        }
        a.amt = a.amt - a.wcamt;
        cout << "balance:" << a.amt;
    }
};

class f
{
public:
    int rea;
    int vir;

    void get(f b)
    {
        cout << "enter real" << endl;

        cin >> b.rea;
        cout << "enter vir" << endl;
        cin >> b.vir;
    }
    friend void addcomplex(f b, f c);
};
void addcomplex(f b, f c)
{
    cout << "the imaginery real no.\n"
         << b.rea << "+i" << b.vir << endl;
    cout << "the imaginery real no.\n"
         << c.rea << "+i" << c.vir << endl;
    cout << "the sum" << b.rea + c.rea << "+i" << b.vir + c.vir << endl;
}
class base
{
public:
    int var1;
    void display()
    {
        cout << "var base" << var1 << endl;
    }
};
class derive : public base
{
public:
    int var2;
    void display()
    {
        cout << "var base" << var1 << endl;
        cout << "var base" << var2 << endl;
    }
};
class point;
class calculator
{
public:
    int sumreal(point, point);
};
class point
{
    int x, y;

public:
    void pointxy(int a, int b)
    {
        x = a;
        y = b;
    }
    void displaythepoint()
    {
        cout << "the coordinates are" << x << " , " << y << endl;
    }
    friend class calculator;
};
int calculator::sumreal(point o1, point o2)
{
    return sqrt(((o2.x * o2.x) - (o1.x * o1.x)) + ((o2.y * o2.y) - (o1.y * o1.y)));
}
int count = 0;
class x
{
    int a;

public:
    x()
    {
        count++;
        cout << "counstructor is called no. of constructor" << count;
    }
    ~x()
    {

        cout << "destructor destroyed no. of destructor " << count;
        count--;
    }
};
class XYZ
{
    int x;
    int r;

public:
    XYZ(){};
    XYZ(int p)
    {
        x = p;
    }
    void operator*(XYZ p)
    {

        r = x * p.x;
    }
    void display()
    {
        cout << r << endl;
    }
};

template <class T1, class T2>
float funcAverage(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;
    return avg;
}

int main()
{

    int choice;
    cout << "enter your choice what you wanna do" << endl;
    cout << "1.your bank account status using vf polymosrphism" << endl;
    cout << "2.Tips to save money in a different text file" << endl;
    cout << "3.complex no. using friend function" << endl;
    cout << "4.displaying inheritance" << endl;
    cout << "5.show distance using friend class" << endl;
    cout << "6.show destructor and constructor" << endl;
    cout << "7.show template" << endl;
    cout << "8.show operator overloading" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Account a;
        Account *tuts[2];
        cout << "Enter the balance amount" << endl;
        cin >> a.amt;
        Savings b;
        Current c;
        tuts[0] = &b;
        tuts[1] = &c;
        tuts[0]->Deposit(a);
        tuts[0]->Withdraw(a);
        tuts[1]->Deposit(a);
        tuts[1]->Withdraw(a);
        cout << "virtual function" << endl;
        break;
    }

    case 2:
    {
        ofstream out;
        out.open("money.txt");
        out << "These are some tips to save money" << endl;
        out << "1.you should always have a budget" << endl;
        out << "2.try to spend carefully" << endl;
        out.close();
        cout << "file" << endl;
        break;
    }
    case 3:
    {
        f j;
        f e;
        j.get(j);
        e.get(e);
        addcomplex(j, e);
        cout << "friend function" << endl;
        break;
    }
    case 4:
    {

        base *basepointer;
        derive *derivepointer;
        base obj1;
        derive obj2;
        basepointer = &obj2;
        basepointer->var1 = 34;
        basepointer->display();

        derivepointer = &obj2;
        derivepointer->var2 = 3554;
        basepointer->var1 = 32564;

        derivepointer->display();
        cout << "inheritance" << endl;
        break;
    }
    case 5:
    {

        calculator d;
        point c1;
        point c2;
        c1.pointxy(1, 0);
        c2.pointxy(70, 0);
        c1.displaythepoint();
        c2.displaythepoint();
        float res = d.sumreal(c1, c2);
        cout << "the distance " << res << endl;
        cout << "the friend class " << endl;
        break;
    }
    case 6:
    {
        cout << "creating the object" << endl;
        x n1;
        {
            cout << "2 objects" << endl;
            x n2, n3;
            cout << "wait n see" << endl;
        }
        cout << "constructor and destructor" << endl;
        break;
    }
    case 7:
    {
        float m;
        m = funcAverage(5, 3);
        printf("the average is %f", m);
        cout << "template";
        break;
    }
    case 8:
    {
        XYZ x1(1);
        XYZ x2(2);

        x1 *x2;

        x1.display();
        cout<<"operator overloading"<<endl;
    }
    default:
        break;
    }

    return 0;
}