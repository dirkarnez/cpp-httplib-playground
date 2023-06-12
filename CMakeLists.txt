cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("cpp-httplib-playground")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

# find_package(portaudio 19 EXACT REQUIRED) # PATHS "P:\\Downloads\\cpp-libraries\\portaudio\\build\\cmake\\portaudio")
find_package(httplib 0.12.6 EXACT REQUIRED)

# if(portaudio_FOUND)
#     message(STATUS "YES")
# else()
#     message(STATUS "NO")
# endif()

if(httplib_FOUND)
    message(STATUS "httplib_FOUND: YES")
else()
    message(STATUS "httplib_FOUND: NO")
endif()


find_package(OpenSSL CONFIG REQUIRED)
if(OpenSSL_FOUND)
    message(STATUS "OpenSSL_FOUND: YES")
else()
    message(STATUS "OpenSSL_FOUND: NO")
endif()

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} httplib::httplib OpenSSL::SSL OpenSSL::Crypto)