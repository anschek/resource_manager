cmake_minimum_required(VERSION 4.0)
project(resource_manager)

set(CMAKE_CXX_STANDARD 20)

# Основной исполняемый файл
add_executable(resource_manager
        src/main.cpp
        include/resource.h
        src/resource.cpp
)

# Папка заголовочных файлов
target_include_directories(resource_manager PRIVATE include)
