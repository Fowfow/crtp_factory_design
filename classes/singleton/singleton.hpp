#pragma once

template<class T>
class singleton
{
public:
    singleton& operator=(singleton const&) = delete;
    singleton& operator=(singleton&&) = delete;

    static T& get_instance()
    {
        if (!instance)
        {
            instance = new T_instance();
        }
        return *instance;
    }
protected:
    singleton(){}    
private:
    struct T_instance : public T
    {
        T_instance():T(){}
    };
    static inline T* instance = nullptr;

    
};