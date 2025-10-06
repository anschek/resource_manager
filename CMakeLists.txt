cmake_minimum_required(VERSION 4.0)
project(resource_manager)

set(CMAKE_CXX_STANDARD 20)

## Подключаем FetchContent
#include(FetchContent)
#
## Объявляем зависимость от googletest
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
#)
#
## Загружаем и делаем доступным
#FetchContent_MakeAvailable(googletest)

# Основной исполняемый файл
add_executable(resource_manager
        src/main.cpp
        src/resource.cpp
        src/unique_resource.cpp
        src/shared_resource.cpp
        src/weak_resource.cpp
)

# Папка заголовочных файлов
target_include_directories(resource_manager PRIVATE include)

## Тесты
#add_executable(tests
#        tests/tests.cpp
#        src/resource.cpp
#)
#
## Подключаем заголовки и линкуем с gtest
#target_link_libraries(tests PRIVATE gtest_main gtest)
#target_include_directories(tests PRIVATE include)