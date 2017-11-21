#include "calc.hpp"
#include <iostream>

std::ostream& operator << (std::ostream& os, const Expr* e)
{
    e->print(os);
    return os;
}

int main()
{
    Expr* e = new Mul(
        new Div(new Int(8), new Int(2)),
        new Add(new Int(9), new Int(2))
    );

    std::cout << e << " == " << e->evaluate() << '\n';

    Expr* e2 = e->reduce();

    delete e;
    delete e2;
}
