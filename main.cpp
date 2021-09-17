#include <vector>
#include <iostream>

#include "device/device.hpp"
#include "device/device_factory.hpp"
#include "person/person.hpp"
#include "person/person_factory.hpp"

int main(int argc, char* argv[])
{
    using factory_device = factory_device<prototype, std::string>;  
    factory_device fac_dev;
    using factory_person = factory_person<prototype, std::string>;
    factory_person fac_per;    
    factory_device::Register("television", std::make_shared<television>("TV", 8.0)); 
    factory_person::Register("parent", std::make_shared<parent>("PAR", 9.0));
    std::shared_ptr<prototype> tv  = fac_dev.clone("television");
    std::shared_ptr<prototype> par = fac_per.clone("parent");
    factory_device::cleanRegister();
    std::cout << *(tv.get());
    std::cout << *(par.get());
    std::cout << "comparaison : " << ((*(tv.get()) <= *(par.get())) ? "True":"False") << std::endl;


    return EXIT_SUCCESS;
}
