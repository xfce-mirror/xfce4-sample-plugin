/*
 * Copyright (c) 2003 Benedikt Meurer <benedikt.meurer@unix-ag.uni-siegen.de>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include <libxfce4util/i18n.h>
#include <libxfcegui4/dialogs.h>
#include <panel/plugins.h>
#include <panel/xfce.h>

typedef struct
{
	GtkWidget	*ebox;
	GtkWidget	*button;
} t_sample;

static void
clicked_cb(GtkWidget *button, gpointer data)
{
	xfce_info(_("Hello World!"));
}

static t_sample *
sample_new(void)
{
	t_sample *sample;

	sample = g_new(t_sample, 1);

	sample->ebox = gtk_event_box_new();
	gtk_widget_show(sample->ebox);

	sample->button = gtk_button_new_with_label(_("Hello World"));
	gtk_widget_show(sample->button);
	gtk_container_add(GTK_CONTAINER(sample->ebox), sample->button);

	g_signal_connect(sample->button, "clicked", G_CALLBACK(clicked_cb),
			sample);

	return(sample);
}

static gboolean
sample_control_new(Control *ctrl)
{
	t_sample *sample;

	sample = sample_new();

	gtk_container_add(GTK_CONTAINER(ctrl->base), sample->ebox);

	ctrl->data = (gpointer)sample;
	ctrl->with_popup = FALSE;

	gtk_widget_set_size_request(ctrl->base, -1, -1);

	return(TRUE);
}

static void
sample_free(Control *ctrl)
{
	t_sample *sample;

	g_return_if_fail(ctrl != NULL);
	g_return_if_fail(ctrl->data != NULL);

	sample = (t_sample *)ctrl->data;

	g_free(sample);
}

static void
sample_read_config(Control *ctrl, xmlNodePtr parent)
{
	/* do something useful here */
}

static void
sample_write_config(Control *ctrl, xmlNodePtr parent)
{
	/* do something useful here */
}

static void
sample_attach_callback(Control *ctrl, const gchar *signal, GCallback cb,
		gpointer data)
{
	t_sample *sample;

	sample = (t_sample *)ctrl->data;
	g_signal_connect(sample->ebox, signal, cb, data);
	g_signal_connect(sample->button, signal, cb, data);
}

static void
sample_set_size(Control *ctrl, int size)
{
	/* do the resize */
}

G_MODULE_EXPORT void
xfce_control_class_init(ControlClass *cc)
{
	cc->name		= "sample";
	cc->caption		= _("Sample plugin");

	cc->create_control	= (CreateControlFunc)sample_control_new;

	cc->free		= sample_free;
	cc->read_config		= sample_read_config;
	cc->write_config	= sample_write_config;
	cc->attach_callback	= sample_attach_callback;

	cc->set_size		= sample_set_size;
}

XFCE_PLUGIN_CHECK_INIT
