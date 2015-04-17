#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_INIT([vsurface], [0.1], [fls@rendera.com.br])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
#AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([GTK], [gtk+-3.0 >= 3])
PKG_CHECK_MODULES([ALSA],[alsa >= 1.0.0])
# Checks for header files.

AC_CHECK_HEADERS(alsa/asoundlib.h)
AC_CHECK_HEADERS(gtk/gtk.h)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
