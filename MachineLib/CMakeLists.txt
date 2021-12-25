project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h
        Polygon.cpp Polygon.h include/machine-api.h ActualMachine.cpp ActualMachine.h Component.cpp Component.h MachineDerived.cpp MachineDerived.h MachineFactory1.cpp MachineFactory1.h MachineFactory2.cpp MachineFactory2.h Motor.cpp Motor.h Gear.cpp Gear.h RotationSink.cpp RotationSink.h RotationSource.cpp RotationSource.h Arm.cpp Arm.h Rod.cpp Rod.h Lever.cpp Lever.h Piston.cpp Piston.h PositionSource.cpp PositionSource.h PositionSink.cpp PositionSink.h INegotiator.cpp INegotiator.h RodSink.cpp RodSink.h RodSource.cpp RodSource.h Shape.cpp Shape.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)