/*
 * monitor-impl.h - Copyright (c) 2001-2021 - Olivier Poncet
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __XCPC_MONITOR_IMPL_H__
#define __XCPC_MONITOR_IMPL_H__

#include <xcpc/libxcpc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define XCPC_MONITOR_WIDTH  768
#define XCPC_MONITOR_HEIGHT 576

typedef struct _XcpcMonitorIface XcpcMonitorIface;
typedef struct _XcpcMonitorState XcpcMonitorState;
typedef struct _XcpcMonitor      XcpcMonitor;
typedef struct _XcpcScanline     XcpcScanline;

struct _XcpcMonitorIface
{
    void* user_data;
};

struct _XcpcMonitorState
{
    Display* display;
    Screen*  screen;
    Visual*  visual;
    XImage*  image;
    GC       gc;
    Window   window;
    Colormap colormap;
    int      depth;
    int      px;
    int      py;
    Bool     try_xshm;
    Bool     has_xshm;
    Bool     use_xshm;
    XColor   palette[32];
};

struct _XcpcMonitor
{
    XcpcMonitorIface iface;
    XcpcMonitorState state;
};

struct _XcpcScanline
{
    uint8_t mode;
    struct {
        uint8_t  value;
        uint32_t pixel;
    } ink[17];
};

#ifdef __cplusplus
}
#endif

#endif /* __XCPC_MONITOR_IMPL_H__ */
