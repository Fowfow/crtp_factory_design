#include <vector>
#include <iostream>

#include "device/device.hpp"
#include "device/device_factory.hpp"
#include "person/person.hpp"
#include "person/person_factory.hpp"

int main(int argc, char* argv[])
{
    using factory_device = factory_device<device, std::string>;  
    factory_device fac_dev;
    factory_device::Register("television", std::make_shared<television>("TV")); 
    std::shared_ptr<device> tv = fac_dev.clone("television");
    // tv->printId();
    std::cout << *(tv.get());

    using factory_person = factory_person<person, std::string>;
    factory_person fac_per;
    factory_person::Register("default_parent", std::make_shared<parent>());
    std::shared_ptr<person> default_parent = fac_per.clone("default_parent");
    // default_parent->printId();
    std::cout << *(default_parent.get());

    return EXIT_SUCCESS;
}
