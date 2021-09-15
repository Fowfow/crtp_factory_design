
#include "person_factory.hpp"
#include "person.hpp"

// Instantiation of static member 
template<class Object, class Key>
std::map<Key, std::shared_ptr<Object>> factory_person<Object, Key>::m_map = std::map<Key, std::shared_ptr<Object>>();

// Instantiation of template parameters
template class factory_person<person, std::string>;