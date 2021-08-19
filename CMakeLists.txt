cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(WriteParticlesVTP)

# Here we are not using the default system vtk library
# The address to the compiled folder of VTK (not install folder)
set(VTK_DIR "/home/sorush/apps/VTK-9.0.3/build")

find_package(VTK COMPONENTS 
  vtkCommonCore
  vtkCommonDataModel
  vtkIOXML
  QUIET
) 

if (NOT VTK_FOUND)
  message("Skipping WriteParticlesVTP: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(WriteParticlesVTP WriteParticlesVTP.cpp )
  target_link_libraries(WriteParticlesVTP PRIVATE ${VTK_LIBRARIES})
else ()
  # include all components
  add_executable(WriteParticlesVTP WriteParticlesVTP.cpp )
  target_link_libraries(WriteParticlesVTP PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS WriteParticlesVTP
    MODULES ${VTK_LIBRARIES}
    )
endif ()