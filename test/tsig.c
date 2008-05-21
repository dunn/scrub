/*****************************************************************************\
 *  $Id:$
 *****************************************************************************
 *  Copyright (C) 2005-2006 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Jim Garlick <garlick@llnl.gov>.
 *  UCRL-CODE-2003-006.
 *  
 *  This file is part of Scrub, a program for erasing disks.
 *  For details, see <http://www.llnl.gov/linux/scrub/>.
 *  
 *  Scrub is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *  
 *  Scrub is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with Scrub; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#if HAVE_CONFIG_H
#include "config.h"
#endif
#if HAVE_SYS_MODE_H
#include <sys/mode.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>

#include "util.h"
#include "sig.h"

char *prog;

int main(int argc, char *argv[])
{
    prog = basename(argv[0]);
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", prog);
        exit(1);
    }
    if (!checksig(argv[1], 8192)) {
        fprintf(stderr, "%s: no signature, writing one\n", prog);
        writesig(argv[1], 8192);
    } else {
        fprintf(stderr, "%s: signature present\n", prog);
    }
    exit(0);
}

/*
 * vi:tabstop=4 shiftwidth=4 expandtab
 */
