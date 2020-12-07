

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = libcobani-core.la


libcobani_core_la_SOURCES = entities.cc contexts.cc Dust.cc
libcobani_core_la_LDFLAGS = -shared -fPIC
libcobani_core_la_LIBADD = $(SDL_LIBS)
libcobani_core_la_CXXFLAGS = $(SDL_CFLAGS)


include_HEADERS = entities.hh contexts.hh Dust.hh

octetos_cobani_includedir = $(includedir)/octetos/cobani
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = cobani-core.pc

EXTRA_DIST = cobani-core.pc.in
