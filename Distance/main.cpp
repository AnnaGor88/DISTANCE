//
//  main.cpp
//  Distance
//
//  Created by Анна Горячева on 30.03.2021.
//

#include <iostream>
using namespace std;
#define tab "\t"
#define DISTANCE
class Point {
    double x;
    double y;
public:
    double get_x()const
    {
        return x;
    }
    double get_y()const
    {
        return y;
    }
    void set_y(double x){
        this->x=x;
    }
    void set_x(double y){
        this->y=y;
    }
    
    //Constructors:
//    Point()
//    {
//        x = y = 0;
//        cout << "DefConstructor:\t" << this << endl;
//    }
//    Point(double x)
//    {
//        this->x=x;
//        this->y=0;
//        cout << "SingleArgumentConstructer: " << this << endl;
//        //конструктор содним параметром отвечает за преобразование типов
//    }
    Point (double x=0, double y=0)
    {
        this ->x =x;
        this ->y =y;
        cout << "Constructor:\t" << this << endl;
    }
    Point (const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        cout << "CopyConstructor:" << this << endl;
    }
    ~Point()
    {
        cout << "Destructor:\t" << this << endl;
    }
    // Operators:
    Point& operator=(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        cout << "CopyAssignment:\t"<< this << endl;
        return *this;
    }
    Point& operator+=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        cout << "Operator+=\t" << this << endl;
        return *this;
    }
    // Increment/Decrement

    Point& operator++()  //Prefix increment
    {
        this->x++;
        this->y++;
        return *this;
    }
    Point operator++(int) // Postfix increment
    {
        Point old= *this;
        this->x++;
        this->y++;
        return old;
    }
//    Point operator+(const Point& other)const
//    {
//        Point result;
//        result.x=this->x + other.x;
//        result.y=this->y + other.y;
//        cout << "Operator + " << this << endl;
//        return result;
//    }
 
    //Methods
    void print()const
    {
        cout << "X = " << x << tab << "Y = " << y << endl;
    }
#ifdef DISTANCE
    float distance()
    {
        double distance;
        distance=sqrt(x*x+y*y);
        return distance;
    }
    float distance(Point point)
    {
        double distance;
        double track1=point.get_x()-x;
        double track2=point.get_y()-y;
        distance=sqrt(track1*track1+track2*track2);
        return distance;
    }
#endif
};
Point operator+(const Point& left, const Point& right)
{
Point result;
result.set_x(left.get_x() + right.get_x());
result.set_y(left.get_y() + right.get_y());
cout << "Global plus" << endl;
    return result;
}
Point operator-(const Point& left, const Point& right)
{
Point result
    (
     left.get_x() - right.get_x(), left.get_y() - right.get_y());
cout << "Global minus" << endl;
    return result;
}
Point operator*(const Point& left, const Point& right)
{
    cout << "Global multiply" << endl;
    return Point
    (
     left.get_x()*right.get_x(),
     left.get_y()*right.get_y()
     );
}
Point operator/(const Point& left, const Point& right)
{
    cout << "Global divide" << endl;
    return Point
    (
     left.get_x()/right.get_x(),
     left.get_y()/right.get_y()
     );
}

ostream& operator<<(ostream& os, const Point& obj)
{
    return os << "X= " << obj.get_x() << tab << "Y= " << obj.get_y();
}
void function (Point* p)
{
    cout << p->get_x() << tab << p->get_y() << endl;
}
void function (Point obj)
{
    cout << obj.get_x() << tab << obj.get_y() << endl;
}

//#define INTRO
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS

int main() {
    setlocale (LC_ALL, "");
#ifdef INTRO
    Point A; //создаем объект(экземпляр) А структуры  Point
    A.set_x(2);
    A.set_y(3);
    cout << A.get_x()<< tab << A.get_y() << endl;
    Point* pA = &A;
    cout << pA->get_x()<< tab << pA->get_y() << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(pA) << endl;
#endif
#ifdef CONSTRUCTORS_CHECK
    Point A;
    A.print();
    Point B(2,3);
    B.print();
    
    Point C=5; //Single argumeyr constructor
    C.print();
    Point D(8); // Single argument constructor
    D.print();
    int b(3); // Якобы для типа int вызывается конструктор с 1 параметром
    cout << int() << endl; // якобы вызывается конструктор по умолчанию для типо int и возвращает значение по умолчанию для типа int
    // так можно получить значение по умолчанию для любого типа
    Point E{13}; // Single argument constructor
    E.print();
    int c{5};
    cout << c << endl;
    cout << int{} << endl; //значение по умолчанию
    Point F =B;
    F.print();
    Point G; // Default constructor
    G=F; // CopyAssignment (operator=)
#endif
#ifdef ASSIGNMENT_CHECK
    int a,b,c;
    a=b=c=0;
    Point A, B, C;
    A = B = C = Point();
#endif
//    int a=2;
//    int b=3;
//    int c=a+b;
#ifdef ARITHMETICAL_OPERATORS
    Point A(2,3);
    Point B(3,4);
    A.print();
    B.print();
    Point C=A+B;
    C.print();
    (A-B).print();
    (A*B).print();
    (A/B).print();
    A.print();
    B.print();
#endif
    Point A(2,3);
    Point B(3,4);
    A+=B; // Неявный вызов оператора
    A.operator+=(B);
    A.print();
    operator/(A,B).print(); // Явный вызов глобального оператора
    A++;
    A.print();
    cout << A << endl;
    A.distance(B);
    A.print();
    return 0;
}
