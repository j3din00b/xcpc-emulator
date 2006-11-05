/*
 * upd765.h - Copyright (c) 2001, 2006 Olivier Poncet
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef __GDEV_UPD765_H__
#define __GDEV_UPD765_H__

#include <dev/device.h>

G_BEGIN_DECLS

#define GDEV_TYPE_UPD765            (gdev_upd765_get_type())
#define GDEV_UPD765(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), GDEV_TYPE_UPD765, GdevUPD765))
#define GDEV_UPD765_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), GDEV_TYPE_UPD765, GdevUPD765Class))
#define GDEV_IS_UPD765(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), GDEV_TYPE_UPD765))
#define GDEV_IS_UPD765_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GDEV_TYPE_UPD765))
#define GDEV_UPD765_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), GDEV_TYPE_UPD765, GdevUPD765Class))

typedef struct _GdevUPD765      GdevUPD765;
typedef struct _GdevUPD765Class GdevUPD765Class;

struct _GdevUPD765 {
  GdevDevice device;
  GdevDevice *fdd[4];   /* floppy disc drives      */
  guint8 cur_fdd;       /* current floppy drive    */
  guint8 reg_msr;       /* main status register    */
  guint8 reg_st0;       /* ST0 status register     */
  guint8 reg_st1;       /* ST1 status register     */
  guint8 reg_st2;       /* ST2 status register     */
  guint8 reg_st3;       /* ST3 status register     */
  guint8 cmd_buffer[9]; /* command buffer          */
  guint8 cmd_buflen;    /* command buffer length   */
  guint8 cmd_bufpos;    /* command buffer position */
  guint8 res_buffer[7]; /* result buffer           */
  guint8 res_buflen;    /* result buffer length    */
  guint8 res_bufpos;    /* result buffer position  */
  guint8 state;
  guint8 data;
};

struct _GdevUPD765Class {
  GdevDeviceClass parent_class;
};

extern GType       gdev_upd765_get_type (void);
extern GdevUPD765 *gdev_upd765_new      (void);
extern guint8      gdev_upd765_rd_ctrl  (GdevUPD765 *upd765);
extern void        gdev_upd765_wr_ctrl  (GdevUPD765 *upd765, guint8 data);
extern guint8      gdev_upd765_rd_data  (GdevUPD765 *upd765);
extern void        gdev_upd765_wr_data  (GdevUPD765 *upd765, guint8 data);

G_END_DECLS

#endif /* __GDEV_UPD765_H__ */
