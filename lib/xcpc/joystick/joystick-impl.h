/*
 * joystick-impl.h - Copyright (c) 2001-2021 - Olivier Poncet
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
#ifndef __XCPC_JOYSTICK_IMPL_H__
#define __XCPC_JOYSTICK_IMPL_H__

#include <xcpc/libxcpc.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _XcpcJoystickIface XcpcJoystickIface;
typedef struct _XcpcJoystickState XcpcJoystickState;
typedef struct _XcpcJoystick      XcpcJoystick;

#ifndef XCPC_JOYSTICK_IFACE
#define XCPC_JOYSTICK_IFACE(instance, field) instance->iface.field
#endif

#ifndef XCPC_JOYSTICK_STATE
#define XCPC_JOYSTICK_STATE(instance, field) instance->state.field
#endif

struct _XcpcJoystickIface
{
    void* user_data;
};

struct _XcpcJoystickState
{
    void* reserved;
};

struct _XcpcJoystick
{
    XcpcJoystickIface iface;
    XcpcJoystickState state;
};

#ifdef __cplusplus
}
#endif

#endif /* __XCPC_JOYSTICK_IMPL_H__ */
