//Ben Hawk
#ifndef CALC_HPP_INCLUDED
#define CALC_HPP_INCLUDED

#include <stdexcept>
#include <iostream>

struct Expr;
struct Int;
struct Add;
struct Div;
struct Mul;
struct Sub;

struct Expr
{
    virtual ~Expr() = default;

    virtual void print(std::ostream& os) const = 0;

    virtual int evaluate() const = 0;

    virtual Expr* reduce() const = 0;

    virtual bool is_value() const
    {
        return false;
    }

    virtual Expr* clone() const = 0;

    virtual bool equal(const Expr* that) const = 0;
    virtual bool equal(const Int* that) const {return false;}
    virtual bool equal(const Add* that) const {return false;}
    virtual bool equal(const Sub* that) const {return false;}
    virtual bool equal(const Mul* that) const {return false;}
    virtual bool equal(const Div* that) const {return false;}
};

bool operator == (const Expr& e1, const Expr& e2);

struct Int : Expr
{
    int val;

    Int(int n)
    : val(n)
    { }

    Int* clone() const override
    {
        return new Int(*this);
    }

    void print(std::ostream& os) const override
    {
        os << val;
    }

    int evaluate() const override
    {
        return val;
    }

    Expr* reduce() const override
    {
        throw std::runtime_error("Already reduced");
    }

    bool is_value() const override {return true;}

    bool equal(const Expr* that) const override
    {
        return that->equal(this);
    }

    bool equal(const Int* that) const override
    {
        return val == that->val;
    }
};

struct Binary : Expr
{

    Expr* e1;
    Expr* e2;

    Binary(const Binary& that)
    : e1(that.e1->clone()), e2(that.e2->clone())
    { }

    Binary(Expr* e1, Expr* e2)
    : e1(e1), e2(e2)
    { }

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

    Add* clone() const override
    {
        return new Add(*this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " + ";
        print_enclosed(os, e2);
    }

    int evaluate() const override
    {
        return e1->evaluate() + e2->evaluate();
    }

    Expr* reduce() const override
    {
        if (e1->is_value())
        {
            if (e2->is_value())
                return new Int(evaluate());
                return new Add(e1->clone(), e2->reduce());
        }
        return new Add(e1->reduce(), e2->clone());
    }

    bool equal(const Expr* that) const override
    {
        return that->equal(this);
    }

    bool equal(const Add* that) const override
    {
        return *e1 == *that->e1 && *e2 == *that->e2;
    }
};

struct Sub : Binary
{
    using Binary::Binary;

    Sub* clone() const override
    {
        return new Sub(*this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " - ";
        print_enclosed(os, e2);
    }

    int evaluate() const override
    {
        return e1->evaluate() - e2->evaluate();
    }

    Expr* reduce() const override
    {
        if (e1->is_value())
        {
            if (e2->is_value())
                return new Int(evaluate());
                return new Sub(e1->clone(), e2->reduce());
        }
        return new Sub(e1->reduce(), e2->clone());
    }

    bool equal(const Expr* that) const override
    {
        return that->equal(this);
    }

    bool equal(const Sub* that) const override
    {
        return *e1 == *that->e1 && *e2 == *that->e2;
    }
};

struct Mul : Binary
{
    using Binary::Binary;

    Mul* clone() const override
    {
        return new Mul(*this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " * ";
        print_enclosed(os, e2);
    }

    int evaluate() const override
    {
        return e1->evaluate() * e2->evaluate();
    }

    Expr* reduce() const override
    {
        if (e1->is_value())
        {
            if (e2->is_value())
                return new Int(evaluate());
                return new Mul(e1->clone(), e2->reduce());
        }
        return new Mul(e1->reduce(), e2->clone());
    }

    bool equal(const Expr* that) const override
    {
        return that->equal(this);
    }

    bool equal(const Mul* that) const override
    {
        return *e1 == *that->e1 && *e2 == *that->e2;
    }
};

struct Div : Binary
{
    using Binary::Binary;

    Div* clone() const override
    {
        return new Div(*this);
    }

    void print(std::ostream& os) const override
    {
        print_enclosed(os, e1);
        os << " / ";
        print_enclosed(os, e2);
    }

    int evaluate() const override
    {
        int d = e2->evaluate();
        if (d == 0)
            throw std::runtime_error("Division by zero");
        return e1->evaluate() / d;
    }

    Expr* reduce() const override
    {
        if (e1->is_value())
        {
            if (e2->is_value())
                return new Int(evaluate());
                return new Div(e1->clone(), e2->reduce());
        }
        return new Div(e1->reduce(), e2->clone());
    }

    bool equal(const Expr* that) const override
    {
        return that->equal(this);
    }

    bool equal(const Div* that) const override
    {
        return *e1 == *that->e1 && *e2 == *that->e2;
    }
};
#endif // CALC_HPP_INCLUDED
