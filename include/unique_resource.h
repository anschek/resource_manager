//
// Created by anschek on 03.10.2025.
//

#ifndef RESOURCE_MANAGER_UNIQUE_RESOURCE_H
#define RESOURCE_MANAGER_UNIQUE_RESOURCE_H
#include <iostream>
#include <memory>

#include "resource.h"

void test_unique_resource();

class UniqueResource {
    public:
    UniqueResource(size_t size);

    // Конструктор копирования
    UniqueResource(const UniqueResource& other) = delete;
    // Оператор присваивания копированием
    UniqueResource& operator=(const UniqueResource& other) = delete;
    // Конструктор перемещения
    UniqueResource(UniqueResource&& moved) noexcept;
    // Оператор присваивания перемещением
    UniqueResource& operator=(UniqueResource&& moved) noexcept;

    Resource* release() { return ptr_.release(); }
    int id() const { return ptr_->id; }
    operator bool() const { return ptr_ != nullptr; }
    void print() const { if (*this) ptr_->print(); }

private:
    std::unique_ptr<Resource> ptr_;
};

#endif //RESOURCE_MANAGER_UNIQUE_RESOURCE_H