//
// Created by anschek on 06.10.2025.
//

#include "shared_resource.h"

void test_shared_resource() {
    SharedResource sr1(4);
    sr1.print_if_alive();
    std::cout << "use count: " << sr1.use_count() << " available " << (bool)sr1 << std::endl;

    SharedResource sr2 = sr1;
    sr2.print_if_alive();
    std::cout << "use count: " << sr1.use_count() << " available " << (bool)sr1 << std::endl;

    {
        SharedResource sr3 = std::move(sr2);
        sr3.print_if_alive();
        std::cout << "use count: " << sr1.use_count() << " available " << (bool)sr1 << std::endl;
    }
    sr2.print_if_alive();
    std::cout << "use count: " << sr2.use_count() << " available " << (bool)sr2 << std::endl;

    std::cout << "use count: " << sr1.use_count() << " available " << (bool)sr1 << std::endl;
}

SharedResource::SharedResource():ptr_(nullptr) {

}

SharedResource::SharedResource(size_t size):ptr_(std::make_shared<Resource>(size)) {
}

SharedResource::SharedResource(std::shared_ptr<Resource> ptr) : ptr_(std::move(ptr)) {
};