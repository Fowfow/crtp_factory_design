#pragma once

#include <memory>

template<class Derived>
class clonable_CRTP
{
protected:
    clonable_CRTP()                     = default;
    clonable_CRTP(clonable_CRTP const&) = default;
    clonable_CRTP(clonable_CRTP &&)     = default;
    ~clonable_CRTP(){}    
private:
    Derived      & derived()       {return static_cast<Derived      &>(*this);}
    Derived const& derived() const {return static_cast<Derived const&>(*this);}
public:
    std::shared_ptr<Derived> clone() const {return std::make_shared<Derived>(derived());}
};