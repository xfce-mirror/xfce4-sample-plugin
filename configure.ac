dnl
dnl xfce4-sample-plugin - A sample plugin for the Xfce panel
dnl
dnl 2020 John Doo <john@example.org>
dnl

dnl ***************************
dnl *** Version information ***
dnl ***************************
m4_define([sample_version_major], [0])
m4_define([sample_version_minor], [0])
m4_define([sample_version_micro], [3])
m4_define([sample_version_nano],  []) dnl leave this empty to have no nano version
m4_define([sample_version_build], [@REVISION@])
m4_define([sample_version_tag], [git])
m4_define([sample_version], [sample_version_major().sample_version_minor().sample_version_micro()ifelse(sample_version_nano(), [], [], [.sample_version_nano()])ifelse(sample_version_tag(), [git], [sample_version_tag()-sample_version_build()], [sample_version_tag()])])
m4_define([sample_default_debug], [ifelse(sample_version_tag(), [git], [yes], [minimum])])

dnl ***************************
dnl *** Initialize autoconf ***
dnl ***************************
AC_COPYRIGHT([Copyright (C) 2020
        The Xfce development team. All rights reserved.])
AC_INIT([xfce4-sample-plugin], [sample_version], [https://gitlab.xfce.org/panel-plugins/xfce4-sample-plugin], [xfce4-sample-plugin])
AC_PREREQ([2.50])
AC_REVISION([xfce4_panel_version_build])
AC_CONFIG_MACRO_DIRS([m4])

dnl ***************************
dnl *** Initialize automake ***
dnl ***************************
AM_INIT_AUTOMAKE([1.15 no-dist-gzip dist-bzip2 tar-ustar foreign])
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE()
AM_SILENT_RULES([yes])

dnl **************************
dnl *** Initialize libtool ***
dnl **************************
LT_PREREQ([2.2.6])
LT_INIT([disable-static])

dnl ********************************
dnl *** Check for basic programs ***
dnl ********************************
AC_PROG_CC()
AC_PROG_CC_C_O()
AC_PROG_INSTALL()

dnl **********************************
dnl *** Check for standard headers ***
dnl **********************************
AC_CHECK_HEADERS([stdlib.h unistd.h locale.h stdio.h errno.h time.h string.h \
                  math.h sys/types.h sys/wait.h memory.h signal.h sys/prctl.h \
                  libintl.h])
AC_CHECK_FUNCS([bind_textdomain_codeset])

dnl ******************************
dnl *** Check for i18n support ***
dnl ******************************
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], ["$PACKAGE"], [Name of default gettext domain])
AC_SUBST([GETTEXT_PACKAGE])
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.19.8])

dnl *******************************
dnl *** Check for X11 installed ***
dnl *******************************
XDT_CHECK_LIBX11_REQUIRE()

dnl ***********************************
dnl *** Check for required packages ***
dnl ***********************************
XDT_CHECK_PACKAGE([GLIB], [glib-2.0], [2.50.0])
XDT_CHECK_PACKAGE([GTK], [gtk+-3.0], [3.22.0])
XDT_CHECK_PACKAGE([LIBXFCE4UI], [libxfce4ui-2], [4.14.0])
XDT_CHECK_PACKAGE([LIBXFCE4PANEL], [libxfce4panel-2.0], [4.14.0])

dnl ***********************************
dnl *** Check for debugging support ***
dnl ***********************************
XDT_FEATURE_DEBUG([sample_default_debug])

dnl *********************************
dnl *** Substitute platform flags ***
dnl *********************************
AC_MSG_CHECKING([PLATFORM_CPPFLAGS])
AC_MSG_RESULT([$PLATFORM_CPPFLAGS])
AC_SUBST([PLATFORM_CPPFLAGS])
AC_MSG_CHECKING([PLATFORM_CFLAGS])
AC_MSG_RESULT([$PLATFORM_CFLAGS])
AC_SUBST([PLATFORM_CFLAGS])
AC_MSG_CHECKING([PLATFORM_LDFLAGS])
AC_MSG_RESULT([$PLATFORM_LDFLAGS])
AC_SUBST([PLATFORM_LDFLAGS])

AC_CONFIG_FILES([
Makefile
icons/Makefile
icons/48x48/Makefile
icons/scalable/Makefile
panel-plugin/Makefile
po/Makefile.in
])
AC_OUTPUT

dnl ***************************
dnl *** Print configuration ***
dnl ***************************
echo
echo "Build Configuration:"
echo
echo "* Debug Support:    $enable_debug"
echo
