//
// Created by anschek on 06.10.2025.
//

#ifndef RESOURCE_MANAGER_WEAK_RESOURCE_H
#define RESOURCE_MANAGER_WEAK_RESOURCE_H
#include "shared_resource.h"

void test_weak_resource();

class WeakResource {
public:
    WeakResource(const SharedResource& shared);

    // Получить временный SharedResource (если ресурс жив)
    SharedResource lock() const;

    int use_count() const{ return  ptr_.use_count();}
    operator bool() const { return !ptr_.expired(); }
    void print_if_alive() const;

private:
    std::weak_ptr<Resource> ptr_;
};

#endif //RESOURCE_MANAGER_WEAK_RESOURCE_H