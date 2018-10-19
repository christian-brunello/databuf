#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([databuf], [0.1], [BUGREPORT@ADDRESS])
AC_CONFIG_SRCDIR([src/endianness.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE

LT_INIT

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdint.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN
AC_TYPE_UINT32_T


# Checks for library functions.

AC_OUTPUT([Makefile src/Makefile])

