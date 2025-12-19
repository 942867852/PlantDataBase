# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PlantDatabase_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PlantDatabase_autogen.dir\\ParseCache.txt"
  "PlantDatabase_autogen"
  )
endif()
