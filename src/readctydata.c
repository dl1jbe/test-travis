/*
 * Tlf - contest logging program for amateur radio operators
 * Copyright (C) 2001-2002-2003 Rein Couperus <pa0rct@amsat.org>
 * 		 2011, 2013, 2016 Thomas Beierlein <tb@forth-ev.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
	/* ------------------------------------------------------------
	 *
	 *              Read country data  from disk file cty.dat
	 *--------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <glib.h>

#include "dxcc.h"
#include "tlf.h"
#include "tlf_curses.h"


int readctydata(void)
{
    gchar *filename;

    if (load_ctydata("cty.dat") == -1) {
	filename = g_strconcat(PACKAGE_DATA_DIR, G_DIR_SEPARATOR_S,
		    "cty.dat", NULL);
	if (load_ctydata(filename) == -1) {
	    g_free(filename);
	    mvprintw(4, 0, "Error opening cty.dat file.\n");
	    refreshp();
	    sleep(5);
	    endwin();
	    exit(1);
	}
	g_free(filename);
    }

    return (0);
}
