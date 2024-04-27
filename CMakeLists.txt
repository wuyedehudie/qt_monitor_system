cmake_minimum_required(VERSION 3.5)

project(monitor_system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Core Gui Widgets)

qt_standard_project_setup()

set(CONTROLLER
    controller/controller.h
)
set(MODEL
    model/model.h
)
set(VIEW
    view/mainview.cpp
    view/mainview.h
    view/mainview.ui
)
qt_add_executable(monitor_system
    MANUAL_FINALIZATION
    main.cpp
    src.qrc
    ${CONTROLLER}
    ${MODEL}
    ${VIEW}
)


#qt6_add_resources(RESOURCE_FILES src.qrc)
#qt_add_qml_module(monitor_system
#    URI monitor_system
#    VERSION 1.0
#    ##QML_FILES
#    RESOURCES README.md
#    RESOURCES ${RESOURCE}
#)
find_package(QT NAMES Qt6 Widgets Core Network QEQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt5 COMPONENTS Core Network REQUIRED)
find_package(Qt6 COMPONENTS Widgets Core Network REQUIRED)


set_target_properties(monitor_system PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(monitor_system
    PRIVATE
    Qt6::Quick
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS monitor_system
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

