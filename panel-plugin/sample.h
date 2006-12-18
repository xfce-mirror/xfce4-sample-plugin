/*  $Id$
 *
 *  Copyright (c) 2006-2007 John Doo <john@foo.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __SAMPLE_H__
#define __SAMPLE_H__

G_BEGIN_DECLS

/* dialog settings */
#define BORDER 8

/* plugin structure */
typedef struct
{
    XfcePanelPlugin *plugin;

    /* panel widgets */
    GtkWidget       *ebox;
    GtkWidget       *label;

    /* sample settings */
    gchar           *setting1;
    gint             setting2;
    gboolean         setting3;
}
SamplePlugin;



void
sample_save (XfcePanelPlugin *plugin, SamplePlugin *sample);

G_END_DECLS

#endif /* !__SAMPLE_H__ */
