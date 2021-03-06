/*
    =========================================================================
    zproxy - work with zmq_proxy_steerable instances

    -------------------------------------------------------------------------
    Copyright (c) 1991-2014 iMatix Corporation <www.imatix.com>
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of CZMQ, the high-level C binding for 0MQ:
    http://czmq.zeromq.org.

    This is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the 
    Free Software Foundation; either version 3 of the License, or (at your 
    option) any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABIL-
    ITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
    Public License for more details.

    You should have received a copy of the GNU Lesser General Public License 
    along with this program. If not, see <http://www.gnu.org/licenses/>.
    =========================================================================
*/

#ifndef __ZPROXY_H_INCLUDED__
#define __ZPROXY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
typedef struct _zproxy_t zproxy_t;

//  @interface

//  Constructor
//  Create a new zproxy object. You must create the frontend and backend
//  sockets, configure them, and connect or bind them, before you pass them
//  to the constructor. Do NOT use the sockets again, after passing them to
//  this method.
CZMQ_EXPORT zproxy_t *
    zproxy_new (zctx_t *ctx, void *frontend, void *backend);

//  Destructor
//  Destroy a zproxy object; note this first stops the proxy.
CZMQ_EXPORT void
    zproxy_destroy (zproxy_t **self_p);

//  Copy all proxied messages to specified endpoint; if this is NULL, any
//  in-progress capturing will be stopped. You must already have bound the
//  endpoint to a PULL socket.
CZMQ_EXPORT void
    zproxy_capture (zproxy_t *self, char *endpoint);

//  Pauses a zproxy object; a paused proxy will cease processing messages,
//  causing them to be queued up and potentially hit the high-water mark on
//  the frontend socket, causing messages to be dropped, or writing
//  applications to block.
CZMQ_EXPORT void
    zproxy_pause (zproxy_t *self);

//  Resume a zproxy object
CZMQ_EXPORT void
    zproxy_resume (zproxy_t *self);

// Self test of this class
CZMQ_EXPORT void
    zproxy_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
