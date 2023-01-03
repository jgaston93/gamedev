add_library(Core Scene/Scene.cpp
                 FrameworkSystems/System.cpp
                 FrameworkSystems/PhysicsSystem.cpp
                 FrameworkSystems/RenderSystem.cpp
                 FrameworkSystems/InputSystem.cpp
                 FrameworkSystems/LogicSystem.cpp
                 EntityComponentSystem/Entity.cpp
                 EntityComponentSystem/Component.cpp
                 EntityComponentSystem/PositionComponent.cpp
                 EntityComponentSystem/BoundingBoxComponent.cpp
                 EntityComponentSystem/OrientationComponent.cpp
                 EntityComponentSystem/VelocityComponent.cpp
                 EntityComponentSystem/ScaleComponent.cpp
                 EntityComponentSystem/TextureComponent.cpp
                 EntityComponentSystem/LogicComponent.cpp
                 MessageBus/MessageBus.cpp)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(Core ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})