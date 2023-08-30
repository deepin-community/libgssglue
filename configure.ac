#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([libgssglue],[0.7],[simon@josefsson.org])
AC_CONFIG_SRCDIR([src/g_accept_sec_context.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE

AC_CONFIG_HEADERS([src/gssglue/config.h])

# Checks for programs.
AC_PROG_CC
LT_INIT

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/gssglue/gssapi/gssapi.h
                 tests/Makefile])

AC_CONFIG_FILES([libgssglue.pc])
AC_OUTPUT
