cmake_minimum_required(VERSION 3.12)

# Ptrojektatribute / Project Attributes

project( MyNameIsEarl.cc
         LANGUAGES CXX 
         DESCRIPTION "Karma-Poins balnce with CLI11"
         HOMEPAGE_URL "https://moodle.thga.de/enrol/index.php?id=2448"

)   

# CLI11 Library zum Projekt einfügen / Add CLI11 Library to Project
find_package(cli11 QUIET)
if(NOT cli11_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11
        GIT_TAG main
    )
    FetchContent_MakeAvailable(cli11)
endif()

# Lohman.json eiphlegen / Add nlohmann.json #https://json.nlohmann.me/integration/cmake/#supporting-both
find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG master
)
    FetchContent_MakeAvailable(nlohmann_json)
endif()

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/src/MyNameIsEarl.cc")
target_link_libraries(${PROJECT_NAME} CLI11:CLI11 nlohmann_json::nlohmann_json)