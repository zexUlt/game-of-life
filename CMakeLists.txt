cmake_minimum_required(VERSION 3.23)
 
project("game-of-life" VERSION 0.1 LANGUAGES CXX)
 
set(CMAKE_INCLUDE_CURRENT_DIR ON)
 
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/forms)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


set(SOURCE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_CODE_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCE_UI_DIR ${PROJECT_SOURCE_DIR}/forms)

list(APPEND PROJECT_SOURCES main.cpp)

file(GLOB_RECURSE files
    ${SOURCE_CODE_DIR}/*.cpp
    ${SOURCE_INCLUDE_DIR}/*.hpp
    ${SOURCE_UI_DIR}/*.ui
)


foreach(file ${files})
    list(APPEND PROJECT_SOURCES ${file})
endforeach()

message(STATUS "Collected sources: ${PROJECT_SOURCES}")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${SOURCE_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
