#pragma once

template<class T>
class singleton_CRTP
{
public:
    singleton_CRTP& operator=(singleton_CRTP const&) = delete;
    singleton_CRTP& operator=(singleton_CRTP&&)      = delete;

    static T& get_instance()
    {
        if (!instance)
        {
            instance = new T_instance();
        }
        return *instance;
    }
protected:
    // default construcor of singleton_crtp implicitely deletes other constructors.
    singleton_CRTP(){}    
private:
    // nested struct to access derived class's protected constructor.
    struct T_instance : public T
    {
        // constructor of derived class T has to be protected to prevent instantiation
        T_instance():T(){}
    };
    static inline T* instance = nullptr;
};