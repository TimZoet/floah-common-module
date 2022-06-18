set(NAME floah-common)
set(TYPE module)
set(INCLUDE_DIR "include/floah-common")
set(SRC_DIR "src")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../floah-layout")
include(floahVersionString)

set(HEADERS
    ${INCLUDE_DIR}/alignment.h
    ${INCLUDE_DIR}/bbox.h
    ${INCLUDE_DIR}/floah_error.h
    ${INCLUDE_DIR}/length.h
    ${INCLUDE_DIR}/margin.h
    ${INCLUDE_DIR}/size.h
)

set(SOURCES
    ${SRC_DIR}/alignment.cpp
    ${SRC_DIR}/bbox.cpp
    ${SRC_DIR}/floah_error.cpp
    ${SRC_DIR}/length.cpp
    ${SRC_DIR}/margin.cpp
    ${SRC_DIR}/size.cpp
)

set(DEPS_PUBLIC
)

set(DEPS_PRIVATE
)

make_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION ${FLOAH_VERSION}
    WARNINGS WERROR
    HEADERS "${HEADERS}"
    SOURCES "${SOURCES}"
    DEPS_PUBLIC "${DEPS_PUBLIC}"
    DEPS_PRIVATE "${DEPS_PRIVATE}"
)

install_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION ${FLOAH_VERSION}
    HEADERS "${HEADERS}"
)

target_compile_definitions(
    ${NAME}
    PRIVATE
        FLOAH_VERSION_MAJOR=${FLOAH_VERSION_MAJOR}
        FLOAH_VERSION_MINOR=${FLOAH_VERSION_MINOR}
        FLOAH_VERSION_PATCH=${FLOAH_VERSION_PATCH}
)