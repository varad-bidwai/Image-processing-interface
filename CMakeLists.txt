cmake_minimum_required(VERSION 3.16)
project(opencvtest VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt features
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Qt Components
find_package(Qt5 REQUIRED COMPONENTS 
    Widgets 
    Core 
    Gui
)

# OpenCV Configuration (Update path to your OpenCV build)
set(OpenCV_DIR "D:/opencv/build")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add all source files
add_executable(opencvtest
    main.cpp
    NodeEditor.cpp
     NodeEditor.h
    NodeCanvas.cpp 
    NodeCanvas.h
    NodeBase.cpp
     NodeBase.h
    Socket.cpp 
    Socket.h
    Connection.cpp 
    Connection.h
    InputNode.cpp 
    InputNode.h
    BlurNode.cpp 
    BlurNode.h
    OutputNode.cpp 
    OutputNode.h
)

# Link libraries
target_link_libraries(opencvtest
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    ${OpenCV_LIBS}
)

# Windows-specific DLL copy (adjust paths if needed)
if(WIN32)
    add_custom_command(TARGET opencvtest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${Qt5_DIR}/../../../bin/Qt5Core.dll"
            $<TARGET_FILE_DIR:opencvtest>
        COMMAND ${CMAKE_COMMAND} -E copy
            "${Qt5_DIR}/../../../bin/Qt5Widgets.dll"
            $<TARGET_FILE_DIR:opencvtest>
        COMMAND ${CMAKE_COMMAND} -E copy
            "${Qt5_DIR}/../../../bin/Qt5Gui.dll"
            $<TARGET_FILE_DIR:opencvtest>
    )
endif()

# # cmake_minimum_required(VERSION 3.16) 
# # project (opencvtest VERSION 0.1.0)

# # include(CTest) 
# # enable_testing()

# # set(OpenCV_DIR "D:/opencv/build")
# # find_package( OpenCV REQUIRED )
# # include_directories( ${OpenCV_INCLUDE_DIRS})

# # add_executable (opencvtest main.cpp)

# # target_link_libraries( opencvtest ${OpenCV_LIBS} )

# # set (CPACK_PROJECT_NAME ${PROJECT_NAME})
# # set (CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# # include(CPack)
# cmake_minimum_required(VERSION 3.16)
# project(opencvtest VERSION 0.1.0)

# set(CMAKE_CXX_STANDARD 17)

# # Enable Qt features
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)

# # Qt
# find_package(Qt5 REQUIRED COMPONENTS Widgets)  # or Qt5 if you're using that

# # OpenCV
# set(OpenCV_DIR "D:/opencv/build")  # adjust this path to your setup
# find_package(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})

# # Add source files
# add_executable(opencvtest
#     main.cpp
#     mainwindow.cpp
#     mainwindow.h
#     mainwindow.ui
# )

# target_link_libraries(opencvtest
#     ${OpenCV_LIBS}
#     Qt5::Widgets  # or Qt5::Widgets
# )