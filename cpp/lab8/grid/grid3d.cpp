#include <iostream>
#include "grid3d.h"

using namespace std;

// default constructor
grid3d::grid3d()
{
    // Implement this function
    // Remember to allocate the array data[]
    // data[0], data[1] and data[2] represent x, y, z respectively
    // It should also print "default constructor" (with newline) to cout

    data = new int[3];
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;

    cout << "default constructor" << endl;

}


// copy constructor
grid3d::grid3d(const grid3d& g)
{
    // Implement this function
    // You have to do a deep copy, not shallow copy!
    // It should also print "copy constructor" (with newline) to cout
    data = new int[3];
    data[0] = g.getx();
    data[1] = g.gety();
    data[2] = g.getz();

    cout << "copy constructor" << endl;

}


// assignment operator
grid3d& grid3d::operator=(const grid3d& g)
{
    // Implement this function
    // You have to do a deep copy, not shallow copy!
    // It is similar to copy constructor
    delete [] data;
    data = new int[3];
    data[0] = g.getx();
    data[1] = g.gety();
    data[2] = g.getz();
    cout << "copy constructor" << endl;
    return (*this);
}


// conversion constructor
// You can call it by "grid3d(2)", or by "grid3d x = 2;"
grid3d::grid3d(int X)
{
    // DO NOT MODIFY THIS FUNCTION

    data = new int[3];
    data[0] = X;
    data[1] = 0;
    data[2] = 0;
    cout << "conversion constructor" << endl;
}


// Another constructor
grid3d::grid3d(int a, int b, int c)
{
    // DO NOT MODIFY THIS FUNCTION

    data = new int[3];
    data[0] = a;
    data[1] = b;
    data[2] = c;
    cout << "typical constructor" << endl;
}


// destructor
grid3d::~grid3d()
{
    // Implement this function
    // Remember to free all dynamically allocated objects here!
    // It should also print "In destructor" (with newline) to cout
    cout << "In destructor" << endl;
    delete [] data;

}


// This function prints the point in the form of (x, y, z)
void grid3d::print() const
{
    // DO NOT MODIFY THIS FUNCTION

    cout << "(" << data[0] << ", " << data[1] << ", " << data[2] << ")";
}


// The member functions getx(), gety() and getz() return the x, y and z co-ordinates of the point.
int grid3d::getx() const
{
    // Implement this function
    return data[0];
}

int grid3d::gety() const
{
    // Implement this function
    return data[1];
}

int grid3d::getz() const
{
    // Implement this function
    return data[2];
}


// Overloaded operator >> to read from the input stream
// Three integers, x co-ordinate, y co-ordinate and z co-ordinate are read and then put to grid3d
istream& operator>>(istream& is, grid3d& g)
{
    // DO NOT MODIFY THIS FUNCTION

    for (int i = 0; i < 3; i++)
        is >> g.data[i];

    return is;
};
