#pragma once

#include <string>
#include <memory>

#include "prototype/prototype.hpp"

// Derived class
class television : public prototype
{
public:
    virtual ~television(){}
    television()                                          {m_classname = "television"; m_id = "default television"; m_size = 0.;}
    television(std::string const& str, double const& sz=0){m_classname = "television"; m_id = str; m_size = sz;}
};
// Derived class
class amplifier : public prototype
{
public:
    virtual ~amplifier(){}   
    amplifier()                                          {m_classname = "amplifier"; m_id = "default amplifier"; m_size = 0.;}
    amplifier(std::string const& str, double const& sz=0){m_classname = "amplifier"; m_id = str; m_size = sz;}
};
// Derived class
class console : public prototype
{
public:
    virtual ~console(){}    
    console()                                          {m_classname = "console"; m_id = "default console"; m_size = 0.;}
    console(std::string const& str, double const& sz=0){m_classname = "console"; m_id = str; m_size = sz;}
};


