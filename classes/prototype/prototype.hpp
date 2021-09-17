#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "operators/equality.hpp"
#include "counter/counter.hpp"

template<class T>
class has_get_size;

// pure virtual base class : prototype
class prototype : public equality_CRTP<prototype>, public counter_CRTP<prototype>
{
protected:
    std::string m_classname;
    std::string m_id;
    double      m_size;
public:
    virtual ~prototype(){}
    double const& get_size() const {return m_size;}
    virtual std::shared_ptr<prototype> clone() const = 0;
    virtual void  printId() const {std::cout << "ID = " << m_id << "\nclassname = " << m_classname << std::endl << std::endl;}
    inline friend std::ostream& operator<<(std::ostream& os, prototype const& dev);
    inline friend bool operator<(prototype const&, prototype const&);
    template<class U>
    // typename std::enable_if<has_get_size<U>::value, bool>::type
    inline friend bool operator<(prototype const&, U const&);
};
// operator <
bool operator<(prototype const& d1, prototype const& d2)
{
    return (d1.m_size < d2.m_size);
}
template<class U>
// typename std::enable_if<has_get_size<U>::value, bool>::type
bool operator<(prototype const& d, U const& u)
{
    return (d.m_size < u.get_size());
}

//
inline std::ostream& operator<<(std::ostream& os, prototype const& dev)
{
    os << "ID = " << dev.m_id << ", classname = " << dev.m_classname << ", size = " << dev.m_size << std::endl;
    return os;
} 

//
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
