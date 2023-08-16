cmake_minimum_required(VERSION 3.10)
project(pi_fm_rds)

set(CMAKE_C_STANDARD 99)

add_definitions(-Wall -g -O3)

# Enable ARM-specific options only on ARM, and compilation of the app only on ARM
execute_process(COMMAND uname -m OUTPUT_VARIABLE UNAME OUTPUT_STRIP_TRAILING_WHITESPACE)

# Determine the hardware platform. Below, pi1 stands for the RaspberryPi 1 (the original one),
# and pi2 stands for both the RaspberryPi 2 and 3.
if(${UNAME} STREQUAL "armv6l")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv6 -mtune=arm1176jzf-s -mfloat-abi=hard -mfpu=vfp -ffast-math -DRASPI=1")
    set(TARGET "pi1")
elseif(${UNAME} STREQUAL "armv7l")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv7-a -mtune=arm1176jzf-s -mfloat-abi=hard -mfpu=vfp -ffast-math -DRASPI=2")
    set(TARGET "pi2")
elseif(${UNAME} STREQUAL "aarch64")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv8-a -mtune=cortex-a53 -mfloat-abi=hard -mfpu=neon-fp-armv8")
    set(TARGET "aarch64")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    set(TARGET "other")
endif()

if(NOT ${TARGET} STREQUAL "other")
    add_executable(pi_fm_rds
            src/rds.c
            src/waveforms.c
            src/pi_fm_rds.c
            src/fm_mpx.c
            src/control_pipe.c
            src/mailbox.c)

    target_link_libraries(pi_fm_rds m sndfile)
endif()

add_executable(rds_wav
        src/rds.c
        src/waveforms.c
        src/rds_wav.c
        src/fm_mpx.c)

target_link_libraries(rds_wav m sndfile)
