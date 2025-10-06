//
// Created by anschek on 03.10.2025.
//

#include "unique_resource.h"

void test_unique_resource() {
    UniqueResource ur(3);
    ur.print_if_alive();

    UniqueResource ur2(std::move(ur));
    ur2.print_if_alive();
    ur.print_if_alive();

    UniqueResource ur3(5);
    ur3.print_if_alive();
    ur3 = std::move(ur2);
    ur3.print_if_alive();
    ur2.print_if_alive();
}

UniqueResource::UniqueResource(size_t size): ptr_(std::make_unique<Resource>(size)) {
}