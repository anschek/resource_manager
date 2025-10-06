//
// Created by anschek on 06.10.2025.
//

#include "resource_manager.h"


void test_resource_manager() {
    ResourceManager rm;

    {
        SharedResource s1 = rm.get_or_create("data", 3);
        s1.print_if_alive();
        std::cout << "In scope: cached_count=" << rm.cached_count() << "\n"; // 1
    } // s1 уничтожен → ресурс больше не нужен

    std::cout << "After scope: cached_count=" << rm.cached_count() << "\n"; // 0!
    std::cout << "Has 'data'? " << rm.has("data") << "\n"; // false

    // Запросим снова — создастся новый ресурс (возможно, с другим id)
    auto s2 = rm.get_or_create("data", 3);
    s2.print_if_alive();
}

SharedResource ResourceManager::get_or_create(const std::string &name, size_t size) {
    auto it = cache_.find(name);
    // найти
    if (it != cache_.end()) {
        if (auto sp = it->second.lock()) {
            return SharedResource(sp);
        }// ресурс мертв, удаляем
        cache_.erase(it);
    }
    // добавить
    auto shared = std::make_shared<Resource>(size);
    cache_[name] = shared;
    return SharedResource(shared);
}

bool ResourceManager::has(const std::string &name) const {
    auto it = cache_.find(name);
    if (it == cache_.end()) return false;
    return !it->second.expired();
}

size_t ResourceManager::cached_count() const {
    return std::ranges::count_if(cache_,
    [](const auto& pair) {return !pair.second.expired();}
    );
}

void ResourceManager::cleanup() {
    for (auto it = cache_.begin(); it != cache_.end();) {
        if (it->second.expired()) {
            it = cache_.erase(it);
        } else {
            ++it;
        }
    }
}
