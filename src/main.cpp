#include <iostream>
#include "resource.h"
#include "resource_manager.h"
#include "shared_resource.h"
#include "unique_resource.h"
#include "weak_resource.h"

int main() {
    test_resource();
    std::cout << std::endl;

    test_unique_resource();
    std::cout << std::endl;

    test_shared_resource();
    std::cout << std::endl;

    test_weak_resource();
    std::cout << std::endl;

    test_resource_manager();
    return 0;
}