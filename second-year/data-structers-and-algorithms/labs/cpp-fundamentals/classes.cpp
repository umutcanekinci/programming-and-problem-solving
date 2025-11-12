#include <iostream>
#include <cmath>

using namespace std;


class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) {
        /* Since we have x as both parameter and class variable the compiler can not distinguish the difference by name.
         To be able to clarify the difference between "Point's x value" and "parameter x" we use
         "this->" which states the variable belongs to the class.
         */
        this->x = x;
        this->y = y;
    }

    void printPoint() {
        cout << "X : " << x << " Y : " << y << endl;
    }

    int getX() {
        return x;
    }

    void setX(int new_x) {
        x = new_x;
    }

    int getY() {
        return y;
    }

    void setY(int new_y) {
        y = new_y;
    }

};

class Triangle {
private:
    Point *p1;
    Point *p2;
    Point *p3;
    string name;

public:

    Triangle(Point *p1, Point *p2, Point *p3, string name) {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->name = name;
    }

    Point *getP1() {
        return p1;
    }

    void setP1(Point *new_p1) {
        p1 = new_p1;
    }

    Point *getP2() {
        return p2;
    }

    void setP2(Point *new_p2) {
        p2 = new_p2;
    }

    Point *getP3() {
        return p3;
    }

    void setP3(Point *new_p3) {
        p3 = new_p3;
    }

    string getName() {
        return name;
    }

    void setName(string new_name) {
        name = new_name;
    }

    void printTriangle() {
        cout << name << " Triangle points" << endl;
        p1->printPoint();
        p2->printPoint();
        p3->printPoint();
    }

    double distance(Point *point1, Point *point2) {
        return sqrt(pow(point1->getX() - point2->getX(), 2) + pow(point2->getY() - point2->getY(), 2));
    }

    double circumference() {
        return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
    }
};


int main() {
    cout << endl << "CLASS" << endl;
    cout << endl << "*Declaration" << endl;
    Point *p = new Point(3, 5);
    /*Since we defined Point's x and y variables as private you can not type p.x or p->x to print out their values
     You have to use provided public methods to be able to do that.
     Uncomment the line below to see the error
     */
    p->printPoint();
    cout << endl << "*Getter/Setter" << endl;
    //cout<<"Accessing pointer x values with '.'"<<p.x<<endl;
    cout << "Point x value : " << p->getX() << " y value : " << p->getY() << endl;
    cout << "Point x value changed to 10" << endl;
    p->setX(10);
    cout << "New point x value : " << p->getX() << endl;

    cout << endl << "*Class with Another Class" << endl;

    Point *p1 = new Point(3, 0);
    Point *p2 = new Point(7, 0);
    Point *p3 = new Point(3, 3);
    Triangle *triangle = new Triangle(p1, p2, p3, "3-4-5");
    triangle->printTriangle();
    cout << "The circumference of triangle is : " << triangle->circumference() << endl;
    Point *new_point_2 = new Point(8, 0);
    Point *new_point_3 = new Point(3, 12);
    triangle->setP2(new_point_2);
    triangle->setP3(new_point_3);
    triangle->setName("5-12-13");
    cout << "Triangle points are changes.New points are " << endl;
    triangle->printTriangle();
    cout << "The new circumference of triangle is : " << triangle->circumference() << endl;

    return 0;
}