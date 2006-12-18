# $Id$

INCLUDES =								\
	-I$(top_srcdir)							\
	-DG_LOG_DOMAIN=\"xfce4-sample-plugin\"				\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"				\
	$(PLATFORM_CPPFLAGS)

#
# Sample plugin
#
plugin_PROGRAMS =							\
	xfce4-sample-plugin

plugindir =								\
	$(libexecdir)/xfce4/panel-plugins

xfce4_sample_plugin_SOURCES =						\
	sample.c							\
	sample.h							\
	sample-dialogs.c						\
	sample-dialogs.h

xfce4_sample_plugin_CFLAGS =						\
	$(LIBXFCE4UTIL_CFLAGS)						\
	$(LIBXFCEGUI4_CFLAGS)						\
	$(LIBXFCE4PANEL_CFLAGS)						\
	$(PLATFORM_CFLAGS)

xfce4_sample_plugin_LDADD =						\
	$(LIBXFCE4UTIL_LIBS)						\
	$(LIBXFCEGUI4_LIBS)						\
	$(LIBXFCE4PANEL_LIBS)

#
# Desktop file
#
desktopdir =								\
	$(datadir)/xfce4/panel-plugins

desktop_in_in_files =							\
	sample.desktop.in.in

desktop_in_files =							\
	$(desktop_in_in_files:.desktop.in.in=.desktop.in)

%.desktop.in: %.desktop.in.in
	sed -e "s,\@libexecdir\@,$(libexecdir),g" < $< > $@

desktop_DATA =								\
	$(desktop_in_files:.desktop.in=.desktop)

@INTLTOOL_DESKTOP_RULE@

EXTRA_DIST =								\
	$(desktop_in_in_files)

CLEANFILES =								\
	$(desktop_in_files)						\
	$(desktop_DATA)

# vi:set ts=8 sw=8 noet ai nocindent syntax=automake:
