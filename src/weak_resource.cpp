//
// Created by anschek on 06.10.2025.
//

#include "weak_resource.h"

void test_weak_resource() {
    SharedResource sr(5);
    sr.print_if_alive();
    WeakResource wr = sr;
    {
        SharedResource sr2 = sr;
        std::cout << "use count: " << wr.use_count() << " available " << (bool)wr << std::endl;
    }
    std::cout << "use count: " << wr.use_count() << " available " << (bool)wr << std::endl;
    {
        SharedResource sr3 = std::move(sr);
    }
    std::cout << "use count: " << wr.use_count() << " available " << (bool)wr << std::endl;

}

WeakResource::WeakResource(const SharedResource &shared):ptr_(shared.ptr_) {
}
SharedResource WeakResource::lock() const {
    if (auto sp = ptr_.lock()) {
        return SharedResource(sp);
    }
    return SharedResource();
}

void WeakResource::print_if_alive() const {
    if (std::shared_ptr<Resource> sp = ptr_.lock()) {
        sp->print();
    }
}

