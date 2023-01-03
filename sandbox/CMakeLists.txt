add_executable(SandBox main.cpp
                       PlayerLogicComponent.cpp)

target_include_directories(SandBox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}../core ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(SandBox LINK_PUBLIC Core)