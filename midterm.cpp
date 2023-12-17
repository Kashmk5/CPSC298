#include <iostream>
#include <cmath>

class Shape {
public:
    Shape(double dHeight, double dWidth) : m_dHeight(dHeight), m_dWidth(dWidth), m_strType("Shape") {}
    virtual ~Shape() {}

    virtual void scale(double dScaleFactor) = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;

    void displayProperties() {
        std::cout << "Shape Type: " << m_strType << ", height: " << m_dHeight << ", width: " << m_dWidth << std::endl;
    }

protected:
    double m_dHeight;
    double m_dWidth;
    std::string m_strType;
};

class Rectangle : public Shape {
public:
    Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
        m_strType = "Rectangle";
    }

    void scale(double dScaleFactor) {
        m_dHeight *= dScaleFactor;
        m_dWidth *= dScaleFactor;
    }

    double area() {
        return m_dHeight * m_dWidth;
    }

    double perimeter() {
        return 2 * (m_dHeight + m_dWidth);
    }
};

class Circle : public Shape {
public:
    Circle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
        m_dWidth = 2 * dHeight; // Setting the width equal to the diameter
        m_strType = "Circle";
    }

    void scale(double dScaleFactor) {
        m_dHeight *= dScaleFactor;
        m_dWidth *= dScaleFactor;
    }

    double area() {
        return 0.25 * M_PI * pow(m_dWidth, 2);
    }

    double perimeter() {
        return M_PI * m_dWidth;
    }
};

int main() {
    Rectangle* P_shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* P_shapeCircle = new Circle(2.0, 2.0);
    Shape* P_shapes[2];
    P_shapes[0] = P_shapeCircle;
    P_shapes[1] = P_shapeRectangle;

    for (int i = 0; i < 2; i++) {
        P_shapes[i]->displayProperties();
        std::cout << "Area: " << P_shapes[i]->area() << ", Perimeter: " << P_shapes[i]->perimeter() << std::endl;

        P_shapes[i]->scale(2.0);

        P_shapes[i]->displayProperties();
        std::cout << "Area: " << P_shapes[i]->area() << ", Perimeter: " << P_shapes[i]->perimeter() << std::endl;
    }

    delete P_shapeRectangle;
    delete P_shapeCircle;

    return 0;
}

