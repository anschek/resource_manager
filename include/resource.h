//
// Created by anschek on 03.10.2025.
//

#ifndef RESOURCE_MANAGER_RESOURCE_H
#define RESOURCE_MANAGER_RESOURCE_H
#include <iostream>

void test();
class Resource {
public:
    // Конструктор
    Resource(size_t size);
    // Конструктор копирования
    Resource(const Resource& other)= delete;
    // Оператор присваивания копированием
    Resource& operator=(const Resource& other)=delete;
    // Конструктор перемещения
    Resource(Resource&& moved) noexcept;
    // Оператор присваивания перемещением
    Resource& operator=(Resource&& moved) noexcept;
    // Деструктор
    ~Resource();

    const int id;
    void print() const;
private:
    static inline int object_count = 0;
    size_t size;
    char *data;
};

#endif //RESOURCE_MANAGER_RESOURCE_H