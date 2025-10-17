#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include "four.h"

int main() {
    std::cout << "Default :";
    Four first;
    first.print(std::cout) << std::endl;

    std::cout << "With size and default value :";
    Four second(5, '2');
    second.print(std::cout) << std::endl;

    std::cout << "Initialization list :";
    Four third{'1', '3', '2', '1', '2'};
    third.print(std::cout) << std::endl;

    std::cout << "str: ";
    Four fourth{"213203"};
    fourth.print(std::cout) << std::endl;

    std::cout << "Copying :";
    Four fifth = second;
    fifth.print(std::cout) << std::endl;

    Four sixth(std::move(fourth));
    std::cout << "moving array: ";  
    sixth.print(std::cout) << std::endl;
    std::cout << "array of moving: ";
    fourth.print(std::cout) << std::endl;


    std::cout << "arithmetic operations" << std::endl;
    Four a("1132"); //94
    Four b("123"); //27

    std::cout << "addition: ";
    Four c = a.plus(b);
    c.print(std::cout) << std::endl;
    a.print(std::cout);
    std::cout << " - a didnt change" << std::endl;

    std::cout << "substration: ";
    Four d = c.minus(b);
    d.print(std::cout) << std::endl;
    c.print(std::cout);
    std::cout << " - c didnt change" << std::endl;


    std::cout << "comparison" << std::endl;
    Four e("123");
    Four f("1230");
    Four g("123");

    bool sr = e.equals(g);
    std::cout << "e == g: " << sr << std::endl;
    sr = e.more(f);
    std::cout << "e > f: " << sr << std::endl;
    sr = g.less(f);
    std::cout << "g < f: " << sr << std::endl;


    std::cout << "Exceptions" << std::endl;
    try {
        Four res = a.minus(c);
        res.print(std::cout);
    } catch (const std::logic_error& o) {
        std::cerr << "Exception was catched: substraction: " << o.what() << std::endl;
    }

    try {
        Four invalid("245");
        invalid.print(std::cout);
    } catch(const std::invalid_argument& o) {
        std::cerr << "Exception was catched: invalid argument: " << o.what() << std::endl;
    }

    std::cout << std::endl << "Exit from main: calling the destructions" << std::endl;

    

    return 0;
}
