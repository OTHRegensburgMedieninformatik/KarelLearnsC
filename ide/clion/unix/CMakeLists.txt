cmake_minimum_required(VERSION 3.6)
project(StarterProject)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES HelloKarel.c)

# Include Directories
include_directories("include")

# Executables
add_executable(StarterProject ${SOURCE_FILES})

# Linked Libraries

#target_link_libraries(StarterProject mingw32)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libkarel.a)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDLmain.a)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libfreetype-6.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libjpeg-8.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpng15-15.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libtiff-5.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libwebp-2.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/zlib1.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_image.dll)
#target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL_ttf.dll)

target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libKarel.a)
target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDLmain.a)
target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL.so)
target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL_image.so)
target_link_libraries(StarterProject ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL_ttf.so)
target_link_libraries(StarterProject pthread)

# This file has  to be in output directory
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL.so DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL_image.so DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL_ttf.so DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL-1.2.so.0.11.4 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL_ttf-2.0.so.0.10.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/libSDL_image-1.2.so.0.8.4 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set_property( TARGET StarterProject PROPERTY COMPILE_DEFINITIONS BUILD=2 )
