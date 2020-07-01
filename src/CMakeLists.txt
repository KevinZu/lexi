AUX_SOURCE_DIRECTORY(. DIR_LEXI_SRCS)
ADD_LIBRARY ( lexis ${DIR_LEXI_SRCS})

find_package(PkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GTK "gtk+-3.0")
  if (GTK_FOUND)    
    add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
  endif()
endif()



