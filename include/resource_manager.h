//
// Created by anschek on 06.10.2025.
//

#ifndef RESOURCE_MANAGER_RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_RESOURCE_MANAGER_H
#include <unordered_map>
#include <algorithm>
#include "shared_resource.h"

void test_resource_manager();

class ResourceManager {
public:
    // Получить или создать ресурс по имени
    SharedResource get_or_create(const std::string& name, size_t size);
    // Проверить наличие
    bool has(const std::string& name) const;
    // Количество кэшированных ресурсов (даже если на них нет внешних ссылок)
    size_t cached_count() const;
    // Очистка недейсствительных данных
    void cleanup();

private:
    std::unordered_map<std::string, std::weak_ptr<Resource>> cache_;
};


#endif //RESOURCE_MANAGER_RESOURCE_MANAGER_H