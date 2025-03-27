cmake_minimum_required(VERSION 3.10)
project(raygl)

set(CMAKE_CXX_STANDARD 17)

# Pridaj hlavičky
include_directories(include)

# Načítaj všetky .cpp zo src/
file(GLOB SOURCES "src/*.cpp")

# Vytvor .so knižnicu
add_library(raygl SHARED ${SOURCES})

# Nastav inštaláciu do systémových priečinkov
install(TARGETS raygl DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
