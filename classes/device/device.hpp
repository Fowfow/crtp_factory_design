#pragma once

#include <string>
#include <iostream>
#include <memory>

// pure virtual base class : device
class device
{
protected:
    std::string classname;
    std::string id;
public:
    virtual ~device(){}
    virtual std::shared_ptr<device> clone() const = 0;
    virtual void  printId() const {std::cout << "ID = " << id << "\nclassname = " << classname << std::endl << std::endl;}
    inline friend std::ostream& operator<<(std::ostream& os, device const& dev);
};
// CRTP class
template<class Derived>
class device_CRTP : public device
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
    virtual std::shared_ptr<device> clone() const override {return std::make_shared<Derived>(derived());} 
};
// Derived class
class television : public device_CRTP<television>
{
public:
    virtual ~television(){}
    television()                      {classname = "television"; id = "default television";}
    television(std::string const& str){classname = "television"; id = str;}
};
// Derived class
class amplifier : public device_CRTP<amplifier>
{
public:
    virtual ~amplifier(){}   
    amplifier()                      {classname = "amplifier"; id = "default amplifier";}
    amplifier(std::string const& str){classname = "amplifier"; id = str;}
};
// Derived class
class console : public device_CRTP<console>
{
public:
    virtual ~console(){}    
    console()                        {classname = "console"; id = "default console";}
    console(std::string const& str)  {classname = "console"; id = str;}
};
//
inline std::ostream& operator<<(std::ostream& os, device const& dev)
{
    os << "ID = " << dev.id << ", classname = " << dev.classname << std::endl;
    return os;
} 
