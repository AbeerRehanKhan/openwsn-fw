sock_udp_t* udp_socket_list;

  // IAR's errno.h apparently doesn't define EOVERFLOW.
  #ifndef EOVERFLOW
  // There is no real good choice for what to set
  // errno to in this case, so we just pick the
  // value '1' somewhat arbitrarily.
  #define EOVERFLOW 1
  #endif

  // IAR's errno.h apparently doesn't define EINVAL.
  #ifndef EINVAL
  // There is no real good choice for what to set
  // errno to in this case, so we just pick the
  // value '1' somewhat arbitrarily.
  #define EINVAL 1
  #endif

  // IAR's errno.h apparently doesn't define ENOMEM.
  #ifndef ENOMEM
  // There is no real good choice for what to set
  // errno to in this case, so we just pick the
  // value '1' somewhat arbitrarily.
  #define ENOMEM 1
  #endif

  // IAR's errno.h apparently doesn't define EAFNOSUPPORT.
  #ifndef EAFNOSUPPORT
  // There is no real good choice for what to set
  // errno to in this case, so we just pick the
  // value '1' somewhat arbitrarily.
  #define EAFNOSUPPORT 1
  #endif

  // IAR's errno.h apparently doesn't define EADDRINUSE.
  #ifndef EADDRINUSE
  // There is no real good choice for what to set
  // errno to in this case, so we just pick the
  // value '1' somewhat arbitrarily.
  #define EADDRINUSE 1
  #endif

  // IAR's errno.h apparently doesn't define ENOTCONN.
  #ifndef ENOTCONN
  // There is no real good choice for what to set
  // errno to in this case, so we just pick the
  // value '1' somewhat arbitrarily.
  #define ENOTCONN 1
  #endif

  // IAR's errno.h apparently doesn't define ENOBUFS.
  #ifndef ENOBUFS
  // There is no real good choice for what to set
  // errno to in this case, so we just pick the
  // value '1' somewhat arbitrarily.
  #define ENOBUFS 1
  #endif

// =========================== variables =======================================
// =========================== prototypes ======================================
