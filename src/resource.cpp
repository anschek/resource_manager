//
// Created by anschek on 03.10.2025.
//

#include "resource.h"

#include <iostream>

class Resource {
public:
    const int id;

    Resource(size_t size) : id(++object_count), size(size), data(new char[size]) {
        srand(time(nullptr));
        for (int i = 0; i < size; ++i)
            data[i] = rand() % 5;

        std::cout << "Resource created, id= " << id << '\n';
    }

    // Запрет копирования
    Resource(const Resource& other) = delete;

    // Запрет присваивания
    Resource& operator=(const Resource& other) = delete;

    // Перемещение
    Resource(Resource&& moved) noexcept: id(++object_count), size(moved.size), data(moved.data) {
        // Обнуляем исходный объект, чтобы его деструктор не освободил переданную память
        moved.data = nullptr;
        moved.size = 0;

        std::cout << "Resource created, id= " << id << " resource with id= " <<  moved.id << " was moved into it\n";
    }

    // Присваивание перемещением
    Resource& operator=(Resource&& moved) noexcept {
        if (this != &moved) {
            delete[] data;
            data = moved.data;
            size = moved.size;
            // Обнуляем исходный объект, чтобы его деструктор не освободил переданную память
            moved.data = nullptr;
            moved.size = 0;

            std::cout << "Resource with id= " << moved.id << " moved to resource with id= " << id<< '\n';
        }
        return *this;
    }

    ~Resource() {
        delete[] data;
        std::cout << "Deleted resource with id= " << id << '\n';
    }

    void print() const{
        std::cout << "Info about resource with id= " << id << ": ";
        std::cout << "Size= " << size << " ";
        std::cout << "Data= ";
        for (int i = 0; i < size; ++i)
            std::cout << static_cast<int>(data[i]) << ' ';
        std::cout << '\n';
    }
private:
    static inline int object_count = 0;
    size_t size;
    char *data;
};


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
