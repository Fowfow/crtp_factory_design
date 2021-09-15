#pragma once

#include <map>
#include <iterator>
#include <memory>

// factory
template<class Object, class Key = std::string>
class factory_person
{
public:
    static std::map<Key, std::shared_ptr<Object>> m_map;
    static void Register(Key const& key, std::shared_ptr<Object> obj)
    {
        if (m_map.find(key) == m_map.end())
        {
            m_map[key] = obj;
        }        
    }
    
    static void cleanRegister() 
    {
        m_map.clear();
    }

    std::shared_ptr<Object> clone(Key const& key)
    {
        std::shared_ptr<Object> tmp = 0;
        typename std::map<Key, std::shared_ptr<Object>>::iterator it = m_map.find(key);
        if (it != m_map.end())
        {
            tmp = ((*it).second)->clone();
        }
        return tmp;        
    }
};
