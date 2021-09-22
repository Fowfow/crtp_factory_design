#pragma once

#include <string>
#include <memory>

#include "prototype/prototype.hpp"

// Derived class
class parent : public prototype
{
public:
    virtual ~parent(){}
    parent()                                         {m_classname = "parent"; m_id = "default parent";}
    parent(std::string const& str, double const& sz) {m_classname = "parent"; m_id = str; m_size = sz;}
};
// Derived class
class child : public prototype
{
public:
    virtual ~child(){}
    child()                       {m_classname = "child"; m_id = "default child";}
    child(std::string const& str) {m_classname = "child"; m_id = str;}    
};
