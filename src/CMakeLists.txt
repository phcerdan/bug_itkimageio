cmake_minimum_required(VERSION 3.5)
project(ITKreadTiffTest)

option(USE_ITKIMAGEIO "Use ITKImageIO --available since ITK4.13" ON)
# Following: https://discourse.itk.org/t/find-all-available-modules-from-groupio/351/5
# Since ITK4.13, ITKImageIO
if (USE_ITKIMAGEIO) # All available IO
    set(use_itk_modules
        IsotropicWavelets
        ITKVtkGlue
        ITKImageIO
        )
else (USE_ITKIMAGEIO) # Only a few IO
    set(use_itk_modules
        IsotropicWavelets
        ITKVtkGlue
        ITKIOImageBase
        ITKIOPNG ITKIOJPEG
        ITKIOTIFF
        ITKIONRRD
        )
endif (USE_ITKIMAGEIO)
find_package(ITK COMPONENTS ${use_itk_modules} REQUIRED)
include(${ITK_USE_FILE})
message(status "** ITK Libraries:  ${ITK_LIBRARIES}")
message(status "** ITK Includes:  ${ITK_INCLUDE_DIRS}")

include_directories("./include")

add_executable(readTiff3D readTiff3D.cxx)
target_link_libraries(readTiff3D ${Boost_LIBRARIES} ${ITK_LIBRARIES} ${VTK_LIBRARIES})

enable_testing()
add_test(NAME readTiff3DTest
    COMMAND readTiff3D ${CMAKE_SOURCE_DIR}/collagen_64x64x16.tiff)
