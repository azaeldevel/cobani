
AC_INIT(cobani-gui, 0.1.0-alpha)

AC_CONFIG_HEADERS([config.h])

SDL_REQUIRED=1.2.15

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CC
AC_PATH_XTRA


AC_PROG_CPP
AC_PROG_CXX



dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=cobani_gui
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
AM_GLIB_GNU_GETTEXT


LT_INIT

dnl ***************************************************************************
dnl Check for SDL
dnl ***************************************************************************
AM_PATH_SDL($SDL_REQUIRED,
            :,
	    AC_MSG_ERROR([SDL version $SDL_REQUIRED not found]))
CXXFLAGS="$CXXFLAGS $SDL_CFLAGS"
CFLAGS="$CFLAGS $SDL_CFLAGS"
CPPFLAGS="$CPPFLAGS $SDL_CFLAGS"
LIBS="$LIBS $SDL_LIBS"


dnl ***************************************************************************
dnl Check for SDL_image
dnl ***************************************************************************
AC_CHECK_LIB(SDL2_image, IMG_Load,[ LIBS="$LIBS -lSDL2_image" ],  AC_MSG_ERROR([SDL_image not found]))



dnl ***************************************************************************
dnl Check for SDL_gfx
dnl ***************************************************************************
AC_CHECK_LIB(SDL2_gfx, SDL_initFramerate, [ LIBS="$LIBS -lSDL2_gfx" ], AC_MSG_ERROR([SDL_gfx not found]))



dnl ***************************************************************************
dnl Check for SDL_ttf
dnl ***************************************************************************
AC_CHECK_LIB(SDL2_ttf, TTF_OpenFont, [ LIBS="$LIBS -lSDL2_ttf" ], AC_MSG_ERROR([SDL_ttf not found]))



dnl ***************************************************************************
dnl Check for SDL_mixer
dnl ***************************************************************************
AC_CHECK_LIB(SDL2_mixer, Mix_OpenAudio, [ LIBS="$LIBS -lSDL2_mixer" ],  AC_MSG_ERROR([SDL_mixer not found]))



dnl ***************************************************************************
dnl Check for SDL_net
dnl ***************************************************************************
AC_CHECK_LIB(SDL2_net, SDLNet_Init, [ LIBS="$LIBS -lSDL2_net" ], AC_MSG_ERROR([SDL_net not found]))


AC_OUTPUT([
Makefile
src/Makefile
po/Makefile.in
])
