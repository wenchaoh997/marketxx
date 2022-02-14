cmake_minimum_required(VERSION 3.10)

# set the project name
project(Market)

set(
    SOURCES
    ${PROJECT_SOURCE_DIR}/src/tools/color.cxx
    ${PROJECT_SOURCE_DIR}/src/tools/info.cxx
    # ${PROJECT_SOURCE_DIR}/src/tools/string.cxx
    ${PROJECT_SOURCE_DIR}/src/menu.cxx
    ${PROJECT_SOURCE_DIR}/src/operation.cxx
    ${PROJECT_SOURCE_DIR}/src/utils.cxx
    ${PROJECT_SOURCE_DIR}/src/user.cxx
    ${PROJECT_SOURCE_DIR}/src/item.cxx
    ${PROJECT_SOURCE_DIR}/src/order.cxx
    ${PROJECT_SOURCE_DIR}/src/main.cxx
)

# set(
#     TEST_SOURCES
#     ${PROJECT_SOURCE_DIR}/test/example.c
#     ${PROJECT_SOURCE_DIR}/test/test.cxx
# )

# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include/tools
    ${PROJECT_SOURCE_DIR}/include
)
