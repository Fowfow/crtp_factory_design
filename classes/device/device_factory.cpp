
#include "device_factory.hpp"
#include "device.hpp"

// Instantiation of static member
template<class Object, class Key>
std::map<Key, std::shared_ptr<Object>> factory_device<Object, Key>::m_map = std::map<Key, std::shared_ptr<Object>>();

// Instantiation of template parameters
template class factory_device<device, std::string>;