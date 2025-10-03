//
// Created by anschek on 03.10.2025.
//

#include "resource.h"


Resource::Resource(size_t size) : id(++object_count), size(size), data(new char[size]) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i)
        data[i] = rand() % 5;

    std::cout << "Resource created, id= " << id << '\n';
    std::cout << "Object count= " << object_count << '\n';
}

Resource::Resource(Resource &&moved) noexcept : id(++object_count), size(moved.size), data(moved.data) {
    // Обнуляем исходный объект, чтобы его деструктор не освободил переданную память
    moved.data = nullptr;
    moved.size = 0;

    std::cout << "Resource created, id= " << id << " resource with id= " << moved.id << " was moved into it\n";
}

Resource &Resource::operator=(Resource &&moved) noexcept {
    if (this != &moved) {
        delete[] data;
        data = moved.data;
        size = moved.size;
        // Обнуляем исходный объект, чтобы его деструктор не освободил переданную память
        moved.data = nullptr;
        moved.size = 0;

        std::cout << "Resource with id= " << moved.id << " moved to resource with id= " << id << '\n';
    }
    return *this;
}

Resource::~Resource() {
    delete[] data;
    std::cout << "Deleted resource with id= " << id << '\n';
}

void Resource::print() const {
    std::cout << "Info about resource with id= " << id << ": ";
    std::cout << "Size= " << size << " ";
    std::cout << "Data= ";
    for (int i = 0; i < size; ++i)
        std::cout << static_cast<int>(data[i]) << ' ';
    std::cout << '\n';
}

void test() {
    Resource r(5);
    r.print();
    Resource r2 = std::move(r);
    r2.print();

    Resource r3 = (7);
    r3.print();
    r2 = std::move(r3);
    r2.print();
}
