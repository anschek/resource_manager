//
// Created by anschek on 03.10.2025.
//

#include "resource.h"


Resource::Resource(size_t size) : id(++object_count_), size_(size), data_(new char[size]) {
    for (int i = 0; i < size; ++i)
        data_[i] = rand() % 5;

    std::cout << "Resource created, id= " << id << '\n';
}

Resource::Resource(Resource &&moved) noexcept
    : id(moved.id), size_(moved.size_), data_(moved.data_) {
    // Обнуляем исходный объект, чтобы его деструктор не освободил переданную память
    moved.data_ = nullptr;
    moved.size_ = 0;

    std::cout << "Resource with id=" << id << " was moved\n";
}

Resource::~Resource() {
    if (data_ != nullptr) {
        delete[] data_;
        std::cout << "Deleted resource with id= " << id << '\n';
    }
}

void Resource::print() const {
    if (data_ != nullptr) {
        std::cout << "Info about resource with id= " << id << ": ";
        std::cout << "Size= " << size_ << " ";
        std::cout << "Data= ";
        for (int i = 0; i < size_; ++i)
            std::cout << static_cast<int>(data_[i]) << ' ';
        std::cout << '\n';
    }else {
        std::cout << "Empty resource\n";
    }
}

void test_resource() {
    srand(time(nullptr));

    Resource *ptr_r = new Resource(3);
    ptr_r->print();
    delete ptr_r;

    Resource r(5);
    r.print();
    Resource r2 = std::move(r);
    r2.print();
    r.print();
}
