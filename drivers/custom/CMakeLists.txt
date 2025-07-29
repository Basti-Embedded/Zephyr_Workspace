#******************************************************************************************
# @file    CmakeLists.txt
# @brief   CMakeLists.txt for a custom driver class
# @spdx_license_identifier: Apache-2.0
#******************************************************************************************

add_subdirectory_ifdef(CONFIG_CUSTOM_DEVICE custom_device)