#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "counter/counter.hpp"
#include "operators/equality.hpp"
#include "prototype/prototype.hpp"

// CRTP class
template<class Derived>
class person_CRTP : public prototype
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
    virtual std::shared_ptr<prototype> clone() const override {return std::make_shared<Derived>(derived());} // return new Derived(derived());
    
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
