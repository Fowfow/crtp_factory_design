#pragma once

#include <string>
#include <iostream>
#include <memory>

// pure virtual base class 
class person
{
protected:
    std::string classname;
    std::string id;
public:
    virtual ~person() = default;
    virtual std::shared_ptr<person> clone() const = 0;
    virtual void printId() const {std::cout << "ID = " << id << "\nclassname = " << classname << std::endl << std::endl;}
    inline friend std::ostream& operator<<(std::ostream& os, person const& pers);
};
// CRTP class
template<class Derived>
class person_CRTP : public person
{
private:
    Derived&       derived()       {return static_cast<Derived      &>(*this);}                    
    Derived const& derived() const {return static_cast<Derived const&>(*this);}                                 
protected:
    virtual ~person_CRTP()           = default;
    person_CRTP()                    = default;
    person_CRTP(person_CRTP const& ) = default;
    person_CRTP(person_CRTP&&)       = default;
public:
    virtual std::shared_ptr<person> clone() const override {return std::make_shared<Derived>(derived());} // return new Derived(derived());
};
// Derived class
class parent : public person_CRTP<parent>
{
public:
    virtual ~parent(){}
    parent()                       {classname = "parent"; id = "default parent";}
    parent(std::string const& str) {classname = "parent"; id = str;}
};
// Derived class
class child : public person_CRTP<child>
{
public:
    virtual ~child(){}
    child()                       {classname = "child"; id = "default child";}
    child(std::string const& str) {classname = "child"; id = str;}    
};
//
inline std::ostream& operator<<(std::ostream& os, person const& pers)
{
    os << "ID = " << pers.id << ", classname = " << pers.classname << std::endl;
    return os;
}