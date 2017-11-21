// Ben Hawk
#ifndef CALC_HPP_INCLUDED
#define CALC_HPP_INCLUDED

#include <stdexcept>
#include <iostream>

struct Expr;
struct Int;
struct Add;
struct Sub;
struct Mul;
struct Div;

struct Visitor
{
    virtual void visit(Int* e) = 0;
    virtual void visit(Add* e) = 0;
    virtual void visit(Sub* e) = 0;
    virtual void visit(Mul* e) = 0;
    virtual void visit(Div* e) = 0;
};

struct EvalVisitor : Visitor
{
    int ret;

    void visit(Int* e) override;
    void visit(Add* e) override;
    void visit(Sub* e) override;
    void visit(Mul* e) override;
    void visit(Div* e) override;
};

int eval(Expr* e);

struct Expr
{
    virtual ~Expr() = default;

    virtual void print(std::ostream& os) const = 0;

    virtual Expr* clone() const = 0;

    virtual void accept(Visitor& v) = 0;
};

struct Int : Expr
{
    Int(int n) : val(n) { }

     Int* clone() const override
    {
      return new Int(*this);
    }

    void print(std::ostream& os) const override
    {
        os << val;
    }

    void accept(Visitor& v) override
    {
        v.visit(this);
    }

    int val;
};

struct Binary : Expr
{
    Expr* e1;
    Expr* e2;

    Binary(Expr *e1, Expr* e2) : e1(e1), e2(e2) { }

    ~Binary() override
    {
        delete e1;
        delete e2;
    }

    static void print_enclosed(std::ostream& os, const Expr* e)
    {
        os << '(';
        e->print(os);
        os << ')';
    }
};

struct Add : Binary
{
    using Binary::Binary;

    void accept(Visitor& v) override
    {
        v.visit(this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " + ";
        print_enclosed(os, e2);
    }

    Add* clone() const override
    {
        return new Add(*this);
    }
};

struct Sub : Binary
{
    using Binary::Binary;

    void accept(Visitor& v) override
    {
        v.visit(this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " - ";
        print_enclosed(os, e2);
    }

    Sub* clone() const override
    {
        return new Sub(*this);
    }
};

struct Mul : Binary
{
    using Binary::Binary;

    void accept(Visitor& v) override
    {
        v.visit(this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " * ";
        print_enclosed(os, e2);
    }

    Mul* clone() const override
    {
        return new Mul(*this);
    }
};

struct Div : Binary
{
    using Binary::Binary;

    void accept(Visitor& v) override
    {
        v.visit(this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " / ";
        print_enclosed(os, e2);
    }

    Div* clone() const override
    {
        return new Div(*this);
    }
};

#endif // CALC_HPP_INCLUDED
