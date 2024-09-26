# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "1780lab_4_autogen"
  "CMakeFiles\\1780lab_4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\1780lab_4_autogen.dir\\ParseCache.txt"
  )
endif()
