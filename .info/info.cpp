#include <stdio.h>
#include <openacc.h>

int main(int argc, char *argv[])
{
    printf("openACC version %d\n", _OPENACC);

    acc_device_t dev_type = acc_get_device_type();
    printf("current device type %d\n", dev_type);

    int num_devices = acc_get_num_devices(dev_type);
    printf("number of devices %d\n", num_devices);

    int dev_num = acc_get_device_num(dev_type);
    printf("current device %d\n", dev_num);

    size_t memory = acc_get_property(dev_num, dev_type, acc_property_memory); 
    printf("  size of device memory in bytes %d\n", memory); 

    size_t free_memory = acc_get_property(dev_num, dev_type, acc_property_free_memory); 
    printf("  free device memory in bytes %d\n", free_memory); 

//  // acc_property_shared_memory_support not supported by v 201711 (2.6)
//    size_t shared_memory = acc_get_property(dev_num, dev_type, acc_property_shared_memory_support); 
//    printf("  non zero if the specified device support ssharing memory with the local thread %d\n", shared_memory); 

    const char* name = acc_get_property_string(dev_num, dev_type, acc_property_name);
    printf("  device vendor %s\n", name); 

    const char* driver = acc_get_property_string(dev_num, dev_type, acc_property_driver);
    printf("  device driver version %s\n", driver); 

    return 0;
}