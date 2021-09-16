#pragma once

template<class Derived>
class equality_CRTP
{
private:
    Derived      & derived()       {return static_cast<Derived      &>(*this);}
    Derived const& derived() const {return static_cast<Derived const&>(*this);}
public:
    template<class U>
    bool operator==(U const& u) const {return !(derived() < u) && !(u < derived());}
    //
    template<class U>
    bool operator!=(U const& u) const {return !(derived() == u);}
    //
    template<class U>
    bool operator<=(U const& u) const {return derived() < u || derived() == u;}
    //
    template<class U>
    bool operator>(U const& u) const {return !(derived() <= u);}
    //
    template<class U>
    bool operator>=(U const& u) const {return !(derived() < u);}

};
//
// template<class T, class Derived>
// bool operator<(T const& u, equality_CRTP<Derived> op)
// {
//     Derived const& d = static_cast<Derived const&>(op);
//     return (u < d);
// }