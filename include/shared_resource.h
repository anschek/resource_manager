//
// Created by anschek on 06.10.2025.
//

#ifndef RESOURCE_MANAGER_SHARED_RESOURCE_H
#define RESOURCE_MANAGER_SHARED_RESOURCE_H
#include <memory>
#include "resource.h"

void test_shared_resource();

class SharedResource {
    friend class WeakResource;

public:
    SharedResource();
    SharedResource(size_t size);
    SharedResource(std::shared_ptr<Resource> ptr);

    // Конструктор копирования
    SharedResource(const SharedResource &other) = default;
    // Оператор присваивания копированием
    SharedResource &operator=(const SharedResource &other) = default;
    // Конструктор перемещения
    SharedResource(SharedResource &&moved) = default;
    // Оператор присваивания перемещением
    SharedResource &operator=(SharedResource &&moved) = default;

    int use_count() const { return ptr_.use_count(); }
    int id() const { return ptr_->id; }
    operator bool() const { return static_cast<bool>(ptr_); }
    void print_if_alive() const { if (ptr_) ptr_->print(); }

private:
    std::shared_ptr<Resource> ptr_;
};


#endif //RESOURCE_MANAGER_SHARED_RESOURCE_H