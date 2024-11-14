cmake_minimum_required(VERSION 3.15...3.31)

set(PROJECT_NAME svnbranch)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")

project(
    ${PROJECT_NAME}
    VERSION 0.0
    DESCRIPTION "Project for creating personal svn branches"
    LANGUAGES CXX
)

add_subdirectory(external/boost EXCLUDE_FROM_ALL)
add_subdirectory(external/spdlog EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/SettingsLoader/SettingsLoader.hpp
    src/SettingsLoader/SettingsLoader.cpp
    src/LogWrapper/LogWrapper.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::regex Boost::property_tree spdlog)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_NAME}/bin/)