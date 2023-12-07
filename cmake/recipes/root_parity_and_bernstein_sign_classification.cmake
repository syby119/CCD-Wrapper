# Brochu et al. [2012] and Tang et al. [2014]
if(TARGET ccd_wrapper::root_parity_and_bernstein_sign_classification)
    return()
endif()

message(STATUS "Third-party: creating target 'ccd_wrapper::root_parity_and_bernstein_sign_classification'")

include(FetchContent)
FetchContent_Declare(
    rp_and_bsc
    GIT_REPOSITORY https://github.com/syby119/Root-Parity-and-Bernstein-Sign-Classification.git
    GIT_TAG e152905c21d7d6bf01c458b32c40b3a4e1dbb651
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(rp_and_bsc)

add_library(ccd_wrapper::root_parity_and_bernstein_sign_classification ALIAS exact-ccd)
