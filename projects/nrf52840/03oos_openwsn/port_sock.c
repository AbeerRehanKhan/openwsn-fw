#include "config.h"

#if OPENWSN_PORT_SOCK_C

#include "opendefs.h"
#include "port_sock.h"
#include "sock.h"
#include "async.h"
#include "openqueue.h"
#include "openserial.h"
#include "packetfunctions.h"

//=========================== variables =======================================

sock_udp_t port_sock;

//=========================== prototypes ======================================

void port_sock_handler(sock_udp_t *sock, sock_async_flags_t type, void *arg);

//=========================== public ==========================================

void port_sock_init(void) {
    // clear local variables
    memset(&port_sock, 0, sizeof(sock_udp_t));

    sock_udp_ep_t local;

    local.port = WKP_UDP_ECHO;

    if (sock_udp_create(&port_sock, &local, NULL, 0) < 0) {
        openserial_printf("Could not create socket\n");
        return;
    }

    openserial_printf("Created a UDP socket\n");

    sock_udp_set_cb(&port_sock, port_sock_handler, NULL);
}

void port_sock_handler(sock_udp_t *sock, sock_async_flags_t type, void *arg) {
    (void) arg;

    char buf[50];

    if (type & SOCK_ASYNC_MSG_RECV) {
        sock_udp_ep_t remote;
        int16_t res;

        if ((res = sock_udp_recv(sock, buf, sizeof(buf), 0, &remote)) >= 0) {
            openserial_printf("Received %d bytes from remote endpoint:\n", res);
            openserial_printf(" - port: %d", remote.port);
            openserial_printf(" - addr: ", remote.port);
            for(int i=0; i < 16; i ++)
                openserial_printf("%x ", remote.addr.ipv6[i]);

            openserial_printf("\n\n");
            openserial_printf("Msg received: %s\n\n", buf);

            if (sock_udp_send(sock, buf, res, &remote) < 0) {
                openserial_printf("Error sending reply\n");
            }
        }
    }
}
//=========================== private =========================================

#endif /* OPENWSN_UECHO_C */
