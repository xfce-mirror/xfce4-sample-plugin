plugindir = @XFCE4_PANEL_PLUGINSDIR@

plugin_LTLIBRARIES =							\
	libsample.la

libsample_la_LDFLAGS =							\
	-avoid-version							\
	-export-dynamic							\
	-module

libsample_la_SOURCES =							\
	sample.c

libsample_la_CFLAGS =							\
	@XFCE4_PANEL_CFLAGS@

libsample_la_LIBADD = 							\
	@XFCE4_PANEL_LIBS@
