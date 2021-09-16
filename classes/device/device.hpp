#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <type_traits>

#include "counter/counter.hpp"
#include "operators/equality.hpp"

template<class T>
class has_get_size;

// pure virtual base class : device
class device : public equality_CRTP<device>, public counter_CRTP<device>
{
protected:
    std::string m_classname;
    std::string m_id;
    double      m_size;
public:
    virtual ~device(){}
    double const& get_size() const {return m_size;}
    virtual std::shared_ptr<device> clone() const = 0;
    virtual void  printId() const {std::cout << "ID = " << m_id << "\nclassname = " << m_classname << std::endl << std::endl;}
    inline friend std::ostream& operator<<(std::ostream& os, device const& dev);
    inline friend bool operator<(device const&, device const&);
    template<class U>
    // typename std::enable_if<has_get_size<U>::value, bool>::type
    inline friend bool operator<(device const&, U const&);
};
// operator <
bool operator<(device const& d1, device const& d2)
{
    return (d1.m_size < d2.m_size);
}
template<class U>
// typename std::enable_if<has_get_size<U>::value, bool>::type
bool operator<(device const& d, U const& u)
{
    return (d.m_size < u.get_size());
}
//
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
//
inline std::ostream& operator<<(std::ostream& os, device const& dev)
{
    os << "ID = " << dev.m_id << ", classname = " << dev.m_classname << ", size = " << dev.m_size << std::endl;
    return os;
} 



template <class T>
class has_get_size
{
private:
    typedef char YesType[1];
    typedef char NoType[2];

    template <class C> 
    static YesType& test( decltype(&C::ToString) ) ;
    template <class C> 
    static NoType& test(...);
public:
    static constexpr bool value{sizeof(test<T>(0)) == sizeof(YesType)};
    // enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
};
