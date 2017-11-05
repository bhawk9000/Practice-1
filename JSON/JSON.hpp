// Ben Hawk
#ifndef JSON_HPP_INCLUDED
#define JSON_HPP_INCLUDED

#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

struct Value
{
    virtual ~Value() {}

    virtual void print() const = 0;
};

struct Null : Value
{
    Null()
    { }

    void print() const
    {
        std::cout << "Null";
    }
};

struct Bool : Value
{
    bool Val;

    Bool(bool val)
        : Val(val)
    { }

    void print() const
    {
        if (Val == true)
        {
            std::cout << "true";
        }
        if (Val == false)
        {
            std::cout << "false";
        }
    }
};

struct Number : Value
{
    double Val;

    Number(double num)
        : Val(num)
    { }

    void print() const
    {
        std::cout << Val;
    }
};

struct String : Value
{
    std::string str;

    String(const std::string& val)
        : str(val)
    { }

    String(const char* first, const char* limit)
        : str(first, limit)
    { }

    void print() const
    {
        std::cout << str;
    }
};

struct Array : Value
{
    std::vector<Value*> val;

    Array() = default;

    Array(std::initializer_list<Value*> list)
        : val(list)
    { }

    ~Array()
    {
        for (Value* v : val)
            delete v;
    }

    void add(Value* v)
    {
        val.push_back(v);
    }

    void print() const
    {
        std::cout << '[';
        for (auto iter = val.begin(); iter != val.end(); ++iter)
        {
            (*iter)->print();
            if (std::next(iter) != val.end())
            {
                std::cout << ", ";
            }
            std::cout << "]";
        }
    }
};

struct Object : Value
{
    std::map<String*, Value*> fields;

    Object() = default;

    ~Object()
    {
        for (auto i : fields)
        {
            delete i.first;
            delete i.second;
        }
    }

    void print() const
    {
        std::cout << '{';
        for (auto iter = fields.begin(); iter != fields.end(); ++iter)
        {
            iter->first->print();
            std::cout << " : ";
            iter->second->print();
            if (std::next(iter) != fields.end())
            {
                std::cout << ", ";
            }
        }
        std::cout << "}";
    }

    void add(String* str, Value* val)
    {
        fields.emplace(str, val);
    }
};

//void print_to_file(std::ostream& out, Value*& val) {out << val << std::endl;}

Value* parse(const std::string& str);

#endif // JSON_HPP_INCLUDED
