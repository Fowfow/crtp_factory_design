#pragma once

#include <type_traits>

#include "prototype/prototype.hpp"

//
// CRTP class
template<class Derived>
class device_CRTP : public prototype
{
private:
    Derived&       derived()       {return static_cast<Derived      &>(*this);}
    Derived const& derived() const {return static_cast<Derived const&>(*this);}
protected:
    virtual ~device_CRTP()          = default;
    device_CRTP()                   = default;
    device_CRTP(device_CRTP const&) = default;
    device_CRTP(device_CRTP&&)      = default;
public:
    virtual std::shared_ptr<prototype> clone() const override {return std::make_shared<Derived>(derived());} 
};
// Derived class
class television : public device_CRTP<television>
{
public:
    virtual ~television(){}
    television()                                          {m_classname = "television"; m_id = "default television"; m_size = 0.;}
    television(std::string const& str, double const& sz=0){m_classname = "television"; m_id = str; m_size = sz;}
};
// Derived class
class amplifier : public device_CRTP<amplifier>
{
public:
    virtual ~amplifier(){}   
    amplifier()                                          {m_classname = "amplifier"; m_id = "default amplifier"; m_size = 0.;}
    amplifier(std::string const& str, double const& sz=0){m_classname = "amplifier"; m_id = str; m_size = sz;}
};
// Derived class
class console : public device_CRTP<console>
{
public:
    virtual ~console(){}    
    console()                                          {m_classname = "console"; m_id = "default console"; m_size = 0.;}
    console(std::string const& str, double const& sz=0){m_classname = "console"; m_id = str; m_size = sz;}
};


