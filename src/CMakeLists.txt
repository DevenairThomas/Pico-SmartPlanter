#src CMakeLists
#Handles Main Functionality

add_executable (main main.cpp MCP3008.cpp)

target_link_libraries(main 
    pico_stdlib
    hardware_spi
)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)