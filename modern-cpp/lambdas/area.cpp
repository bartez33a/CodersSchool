#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>

// Change function `areaLessThan20` into lambda.
// Then change it into `areaLessThanX`, which takes `x = 20` on a capture list.
// What is the problem?
// Use `std::function` to solve the problem.

using namespace std;

class Circle {
    double r_{};

public:
    Circle(double r) : r_{r} {}

    double getArea() const {
       return 3.14 * r_ * r_;
    }

    void print() const {
        std::cout << "Circle:\n"
                  << "  radius: " << r_ << '\n'
                  << "    area: " << getArea() << '\n';
    }
};

using CirclePtr = shared_ptr<Circle>;
using Collection = vector<CirclePtr>;

bool areaLessThan20(CirclePtr s) {
    return (s && s->getArea() < 20);
}

void printCollection(const Collection& collection) {
    for (const auto & it : collection) {
        if (it) {
            it->print();
        }
    }
}

void printAreas(const Collection& collection) {
    for (const auto & it : collection) {
        if (it) {
            cout << it->getArea() << std::endl;
        }
    }
}

// with pointer to function --> does not work with lambda, which caputers sth
void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::string info,
                                     bool (*predicate)(CirclePtr s)) {
    auto it = std::find_if(collection.begin(), collection.end(), predicate);
    if(it != collection.end()) {
        cout << "First shape matching predicate: " << info << endl;
        (*it)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

//  can be used with lambdas, which captures something thanks to std::function!
void findFirstShapeMatchingPredicateCaptureList(const Collection& collection,
                                     std::string info,
                                     std::function<bool(CirclePtr)> predicate) {
    auto it = std::find_if(collection.begin(), collection.end(), predicate);
    if(it != collection.end()) {
        cout << "First shape matching predicate: " << info << endl;
        (*it)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main() {
    Collection circles {
        make_shared<Circle>(4.0),
        make_shared<Circle>(3.0),
        make_shared<Circle>(2.0),
        make_shared<Circle>(4.0),
    };
    printCollection(circles);

    cout << "Areas before sort: " << std::endl;
    printAreas(circles);

    std::sort(circles.begin(), circles.end(), [](auto lhs, auto rhs) {
        if(!lhs || !rhs)
            return false;
        return (lhs->getArea() < rhs->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(circles);

    /*
    findFirstShapeMatchingPredicate(circles,
                                    "area less than 20",
                                    areaLessThan20);
    */

    // change areaLessThan20 to lambda --> this lambda converts to pointer to function 
    // (when it does not capture anything)
    findFirstShapeMatchingPredicate(circles,"area less than 20", [](CirclePtr s) {
        return (s && s->getArea() < 20); 
    });


    // lambda which captures some value --> DO NOT CONVERT TO POINTER TO FUNCTION
    auto areaLessThanX = [X = 20](CirclePtr s) {
        return (s && s->getArea() < X);
    };

    // this function uses std::function instead of raw pointer to a function
    findFirstShapeMatchingPredicateCaptureList(circles,"area less than X=20", areaLessThanX);

    return 0;
}
