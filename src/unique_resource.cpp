//
// Created by anschek on 03.10.2025.
//

#include "unique_resource.h"

void test_unique_resource() {
    UniqueResource ur(3);
    ur.print();

    UniqueResource ur2(std::move(ur));
    ur2.print();
    ur.print();

    UniqueResource ur3(5);
    ur3.print();
    ur3 = std::move(ur2);
    ur3.print();
    ur2.print();
}

UniqueResource::UniqueResource(size_t size): ptr_(std::make_unique<Resource>(size)) {
}

UniqueResource::UniqueResource(UniqueResource&& moved) noexcept: ptr_(std::move(moved.ptr_)) {
    std::cout << "Unique resource with id=" << id() << " was moved\n";
}

UniqueResource &UniqueResource::operator=(UniqueResource &&moved) noexcept {
    if (this != &moved) {
        std::cout << "Unique resource with id=" << moved.id() << " was moved to " << id() << '\n';
        ptr_ = std::move(moved.ptr_);
    }
    return *this;
}
