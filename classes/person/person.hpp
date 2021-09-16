#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "counter/counter.hpp"
#include "operators/equality.hpp"

// pure virtual base class 
class person : public equality_CRTP<person>, public counter_CRTP<person>
{
protected:
    std::string m_classname;
    std::string m_id;
    double      m_size;
public:
    virtual ~person() = default;
    double const& get_size() const {return m_size;}
    virtual std::shared_ptr<person> clone() const = 0;
    virtual void printId() const {std::cout << "ID = " << m_id << "\nclassname = " << m_classname << std::endl << std::endl;}
    inline friend std::ostream& operator<<(std::ostream& os, person const& pers);
    inline friend bool operator<(person const&, person const&);
    template<class U>
    inline friend bool operator<(person const&, U const&);    
};
// operator <
inline bool operator<(person const& p1, person const& p2)
{
    return p1.m_size < p2.m_size;
}
template<class U>
inline bool operator<(person const& p, U const& u)
{
    return (p.m_size < u.get_size()); 
}
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
    parent()                                         {m_classname = "parent"; m_id = "default parent";}
    parent(std::string const& str, double const& sz) {m_classname = "parent"; m_id = str; m_size = sz;}
};
// Derived class
class child : public person_CRTP<child>
{
public:
    virtual ~child(){}
    child()                       {m_classname = "child"; m_id = "default child";}
    child(std::string const& str) {m_classname = "child"; m_id = str;}    
};
//
inline std::ostream& operator<<(std::ostream& os, person const& pers)
{
    os << "ID = " << pers.m_id << ", classname = " << pers.m_classname << ", size = " << pers.m_size << std::endl;
    return os;
}