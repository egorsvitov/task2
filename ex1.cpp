#include <iostream>
#include <cmath>

class MathMixin {
public:
	const double pi() const {
		return std::acos(-1);
	}

	double approximate_ellipse_perimeter(double a, double b) const {
		return pi() * std::sqrt(2 * (a * a + b * b)); 
	}

    double geron_area(double a, double b, double c) const {
        double p = (a + b + c)/2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Figure {
public:
	virtual double perimeter() const = 0;
	virtual double square() const = 0;
};

class Ellipse: public Figure, private MathMixin {
public:
	Ellipse(double a, double b): a(a), b(b) {}

	double perimeter() const override {
		return approximate_ellipse_perimeter(a, b);
	}

	double square() const override {
		return pi() * a * b;
	}	
private:
	double a, b;
};

class Circle: public Ellipse {
public:
	Circle(double r): Ellipse(r, r) {}
};

class Triangle: public Figure, private MathMixin {
public:
    Triangle(double a, double b, double c) {
        if (a <= b + c && b <= c + b && c <= b + a) {
            this->a = a;
            this->b = b;
            this->c = c;
        } else {
            std::cout << "A triangle can't have these sides" << std::endl;
            this->a = 0;
            this->b = 0;
            this->c = 0;
        }
    }

    double perimeter() const override {
        return a + b + c;
    }

    double square() const override {
        return geron_area(a, b, c);
    }
private:
    double a, b, c;
};

class isoscelesTriangle: public Triangle {
public:
    isoscelesTriangle(double base, double side): Triangle(base, side, side) {}
};

class equilateralTriangle: public Triangle {
public:
    equilateralTriangle(double side):  Triangle(side, side, side) {}
};

class Rectangle: public Figure {
public:
    Rectangle(double a, double b): a(a), b(b) {}

    double perimeter() const override {
        return 2 * (a + b);
    }

    double square() const override {
        return a * b;
    }
private:
    double a, b;
};

class Square: public Rectangle {
public:
    Square(double a): Rectangle(a, a) {}
};

int main() {
	Ellipse ellipse(4, 5);
	std::cout << ellipse.perimeter() << std::endl;
	std::cout << ellipse.square() << std::endl;

	Circle circle(3);
	std::cout << circle.perimeter() << std::endl;
	std::cout << circle.square() << std::endl;

    Triangle nonexistent_triangle(10, 1, 2);

    Triangle triangle(3, 4, 5);
    std::cout << triangle.perimeter() << std::endl;
    std::cout << triangle.square() << std::endl;

    isoscelesTriangle isos(3, 4);
    std::cout << isos.perimeter() << std::endl;
    std::cout << isos.square() << std::endl;

    equilateralTriangle equil(3);
    std::cout << equil.perimeter() << std::endl;
    std::cout << equil.square() << std::endl;

    Rectangle rectangle(3, 5);
    std::cout << rectangle.perimeter() << std::endl;
    std::cout << rectangle.square() << std::endl;

    Square square(5);
    std::cout << square.perimeter() << std::endl;
    std::cout << square.square() << std::endl;
}	
