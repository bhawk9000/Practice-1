// Ben Hawk

#include "calc.hpp"

bool operator == (const Expr& e1, const Expr& e2)
{
    if (&e1 == &e2)
        return true;

    return e1.equal(&e2);
}
