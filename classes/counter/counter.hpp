#pragma once

// CRTP class : counter_CRTP
template<class T>
class counter_CRTP
{
private:
protected:
    ~counter_CRTP()
    {
        counter_alive--;
    }
public:
    static inline int counter_created = 0;
    static inline int counter_alive   = 0;
    counter_CRTP(){counter_created++; counter_alive++;}
    counter_CRTP(counter_CRTP const&) {counter_created++; counter_alive++;}
};

