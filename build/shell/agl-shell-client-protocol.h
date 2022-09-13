/* Generated by wayland-scanner 1.18.0 */

#ifndef AGL_SHELL_CLIENT_PROTOCOL_H
#define AGL_SHELL_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_agl_shell The agl_shell protocol
 * @section page_ifaces_agl_shell Interfaces
 * - @subpage page_iface_agl_shell - user interface for weston-ivi
 * @section page_copyright_agl_shell Copyright
 * <pre>
 *
 * Copyright Â© 2019 Collabora, Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct agl_shell;
struct wl_output;
struct wl_surface;

/**
 * @page page_iface_agl_shell agl_shell
 * @section page_iface_agl_shell_desc Description
 *
 * @section page_iface_agl_shell_api API
 * See @ref iface_agl_shell.
 */
/**
 * @defgroup iface_agl_shell The agl_shell interface
 *
 */
extern const struct wl_interface agl_shell_interface;

#ifndef AGL_SHELL_ERROR_ENUM
#define AGL_SHELL_ERROR_ENUM
enum agl_shell_error {
	AGL_SHELL_ERROR_INVALID_ARGUMENT = 0,
	AGL_SHELL_ERROR_BACKGROUND_EXISTS = 1,
	AGL_SHELL_ERROR_PANEL_EXISTS = 2,
};
#endif /* AGL_SHELL_ERROR_ENUM */

#ifndef AGL_SHELL_EDGE_ENUM
#define AGL_SHELL_EDGE_ENUM
enum agl_shell_edge {
	AGL_SHELL_EDGE_TOP = 0,
	AGL_SHELL_EDGE_BOTTOM = 1,
	AGL_SHELL_EDGE_LEFT = 2,
	AGL_SHELL_EDGE_RIGHT = 3,
};
#endif /* AGL_SHELL_EDGE_ENUM */

#define AGL_SHELL_READY 0
#define AGL_SHELL_SET_BACKGROUND 1
#define AGL_SHELL_SET_PANEL 2
#define AGL_SHELL_ACTIVATE_APP 3


/**
 * @ingroup iface_agl_shell
 */
#define AGL_SHELL_READY_SINCE_VERSION 1
/**
 * @ingroup iface_agl_shell
 */
#define AGL_SHELL_SET_BACKGROUND_SINCE_VERSION 1
/**
 * @ingroup iface_agl_shell
 */
#define AGL_SHELL_SET_PANEL_SINCE_VERSION 1
/**
 * @ingroup iface_agl_shell
 */
#define AGL_SHELL_ACTIVATE_APP_SINCE_VERSION 1

/** @ingroup iface_agl_shell */
static inline void
agl_shell_set_user_data(struct agl_shell *agl_shell, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) agl_shell, user_data);
}

/** @ingroup iface_agl_shell */
static inline void *
agl_shell_get_user_data(struct agl_shell *agl_shell)
{
	return wl_proxy_get_user_data((struct wl_proxy *) agl_shell);
}

static inline uint32_t
agl_shell_get_version(struct agl_shell *agl_shell)
{
	return wl_proxy_get_version((struct wl_proxy *) agl_shell);
}

/** @ingroup iface_agl_shell */
static inline void
agl_shell_destroy(struct agl_shell *agl_shell)
{
	wl_proxy_destroy((struct wl_proxy *) agl_shell);
}

/**
 * @ingroup iface_agl_shell
 *
 * Tell the server that this client is ready to be shown. The server
 * will delay presentation during start-up until all shell clients are
 * ready to be shown, and will display a black screen instead.
 * This gives the client an oppurtunity to set up and configure several
 * surfaces into a coherent interface.
 *
 * The client that binds to this interface must send this request, otherwise
 * they may stall the compositor unnecessarily.
 *
 * If this request is called after the compositor has already finished
 * start-up, no operation is performed.
 */
static inline void
agl_shell_ready(struct agl_shell *agl_shell)
{
	wl_proxy_marshal((struct wl_proxy *) agl_shell,
			 AGL_SHELL_READY);
}

/**
 * @ingroup iface_agl_shell
 *
 * Set the surface to act as the background of an output. After this
 * request, the server will immediately send a configure event with
 * the dimensions the client should use to cover the entire output.
 *
 * The surface must have a "desktop" surface role, as supported by
 * libweston-desktop.
 *
 * Only a single surface may be the background for any output. If a
 * background surface already exists, a protocol error is raised.
 */
static inline void
agl_shell_set_background(struct agl_shell *agl_shell, struct wl_surface *surface, struct wl_output *output)
{
	wl_proxy_marshal((struct wl_proxy *) agl_shell,
			 AGL_SHELL_SET_BACKGROUND, surface, output);
}

/**
 * @ingroup iface_agl_shell
 *
 * Set the surface to act as a panel of an output. The 'edge' argument
 * says what edge of the output the surface will be anchored to.
 * After this request, the server will send a configure event with the
 * correponding width/height that the client should use, and 0 for the
 * other dimension. E.g. if the edge is 'top', the width will be the
 * output's width, and the height will be 0.
 *
 * The surface must have a "desktop" surface role, as supported by
 * libweston-desktop.
 *
 * The compositor will take the panel's window geometry into account when
 * positioning other windows, so the panels are not covered.
 *
 * XXX: What happens if e.g. both top and left are used at the same time?
 * Who gets to have the corner?
 *
 * Only a single surface may be the panel for an output's edge. If a
 * surface already exists on an edge, a protocol error is raised.
 */
static inline void
agl_shell_set_panel(struct agl_shell *agl_shell, struct wl_surface *surface, struct wl_output *output, uint32_t edge)
{
	wl_proxy_marshal((struct wl_proxy *) agl_shell,
			 AGL_SHELL_SET_PANEL, surface, output, edge);
}

/**
 * @ingroup iface_agl_shell
 *
 * Ask the compositor to make a toplevel to become the current/focused
 * window for window management purposes.
 *
 * See xdg_toplevel.set_app_id from the xdg-shell protocol for a
 * description of app_id.
 *
 * If multiple toplevels have the same app_id, the result is unspecified.
 *
 * XXX: Do we need feedback to say it didn't work? (e.g. client does
 * not exist)
 */
static inline void
agl_shell_activate_app(struct agl_shell *agl_shell, const char *app_id, struct wl_output *output)
{
	wl_proxy_marshal((struct wl_proxy *) agl_shell,
			 AGL_SHELL_ACTIVATE_APP, app_id, output);
}

#ifdef  __cplusplus
}
#endif

#endif
