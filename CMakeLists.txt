cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(SmartPlanter)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

include_directories(include)

add_subdirectory (src)
#add_subdirectory (include)

#add_executable(main)
#target_include_directories(HelloWorld PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# Add pico_stdlib library which aggregates commonly used features
#target_link_libraries(HelloWorld pico_stdlib hardware_spi)
#target_link_libraries(MCP3008 pico_stdlib hardware_spi)


#pico_enable_stdio_usb(HelloWorld 1)
#pico_enable_stdio_uart(HelloWorld 0)

# create map/bin/hex/uf2 file in addition to ELF.
#pico_add_extra_outputs(main)