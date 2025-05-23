#ifndef LIBUVC_CONFIG_H
#define LIBUVC_CONFIG_H

#define LIBUVC_VERSION_MAJOR 0
#define LIBUVC_VERSION_MINOR 0
#define LIBUVC_VERSION_PATCH 7
#define LIBUVC_VERSION_STR "0.0.7"
#define LIBUVC_VERSION_INT                      \
  ((LIBUVC_VERSION_MAJOR << 16) |             \
   (LIBUVC_VERSION_MINOR << 8) |              \
   (LIBUVC_VERSION_PATCH))

/** @brief Test whether libuvc is new enough
 * This macro evaluates true if and only if the current version is
 * at least as new as the version specified.
 */
#define LIBUVC_VERSION_GTE(major, minor, patch)                         \
  (LIBUVC_VERSION_INT >= (((major) << 16) | ((minor) << 8) | (patch)))

//#cmakedefine LIBUVC_HAS_JPEG 1

#endif // !def(LIBUVC_CONFIG_H)
