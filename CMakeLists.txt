cmake_minimum_required(VERSION 2.8)

include(FindPkgConfig)

project(litebrowser CXX)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -DDEBUG -g")
set(CMAKE_C_FLAGS_DEBUG "-O0 -DDEBUG -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_RELEASE "-O3")

set(LITEBROWSER_PATH src)
set(LITEHTML_PATH litehtml)
set(CONTAINER_PATH ${LITEHTML_PATH}/containers/haiku)

#pkg_check_modules(LB_LIBS REQUIRED fontconfig gdkmm-3.0 gtkmm-3.0 libcurl cairo)

find_package(Poco REQUIRED Foundation)

set(SOURCE  ${LITEBROWSER_PATH}/App.cpp
            ${CONTAINER_PATH}/container_haiku.cpp
            ${LITEBROWSER_PATH}/MainWindow.cpp
            ${LITEBROWSER_PATH}/LiteHtmlView.cpp
    )

set(HEADERS ${LITEBROWSER_PATH}/MainWindow.h
            ${LITEBROWSER_PATH}/App.h
            ${LITEBROWSER_PATH}/LiteHtmlView.h
            ${CONTAINER_PATH}/container_haiku.h
    )

include_directories(${LITEHTML_PATH}/include ${LB_LIBS_INCLUDE_DIRS})

add_subdirectory(${LITEHTML_PATH})

find_program(XXD_COMMAND xxd)
add_custom_command(OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/master.css.inc
                   COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/${LITEHTML_PATH}/include/master.css | xxd -i > ${CMAKE_CURRENT_SOURCE_DIR}/src/master.css.inc)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/src/master.css.inc PROPERTIES GENERATED TRUE)

add_executable(litebrowser ${SOURCE} ${HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/src/master.css.inc )

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 11
        C_STANDARD 99
        )

target_link_libraries(litebrowser litehtml be) # ${LB_LIBS_LIBRARIES}

