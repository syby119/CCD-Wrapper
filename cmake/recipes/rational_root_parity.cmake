# Rational Root Parity CCD (rational version of [Brochu et al. 2012])
if(TARGET ccd_wrapper::rational_root_parity)
    return()
endif()

message(STATUS "Third-party: creating target 'ccd_wrapper::rational_root_parity'")

include(FetchContent)
FetchContent_Declare(
    rational_root_parity
    GIT_REPOSITORY https://github.com/syby119/Rational-Root-Parity.git
    GIT_TAG 1a44ccd642dae045906fd89b71dbc89c6f1b9ba7
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(rational_root_parity)

add_library(ccd_wrapper::rational_root_parity ALIAS RationalCCD)
