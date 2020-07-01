PROJECT(lexi)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

include_directories(include)
add_subdirectory(src)

ADD_EXECUTABLE(lexi ${DIR_SRCS})


find_package(PkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GTK "gtk+-3.0")
  if (GTK_FOUND)    
    target_link_libraries(lexi lexis ${GTK_LIBRARIES})
    add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
  endif()
endif()



