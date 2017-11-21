// Ben Hawk
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
    new Div(new Int(10), new Int(2)),
    new Add(new Int(22), new Int(4))
  );

  EvalVisitor v;
  e->accept(v);

  std::cout << v.ret << '\n';
  std::cout << eval(e) << '\n';
}
