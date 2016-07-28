#ifndef ADRO_SYS_VERSION_H
#define ADRO_SYS_VERSION_H
// copied from qsystemdetection.h
/*
   The operating system, must be one of: (ADRO_OS_x)

     DARWIN   - Any Darwin system
     MAC      - OS X and iOS
     OSX      - OS X
     IOS      - iOS
     MSDOS    - MS-DOS and Windows
     OS2      - OS/2
     OS2EMX   - XFree86 on OS/2 (not PM)
     WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)
     WINCE    - WinCE (Windows CE 5.0)
     WINRT    - WinRT (Windows 8 Runtime)
     CYGWIN   - Cygwin
     SOLARIS  - Sun Solaris
     HPUX     - HP-UX
     ULTRIX   - DEC Ultrix
     LINUX    - Linux [has variants]
     FREEBSD  - FreeBSD [has variants]
     NETBSD   - NetBSD
     OPENBSD  - OpenBSD
     BSDI     - BSD/OS
     IRIX     - SGI Irix
     OSF      - HP Tru64 UNIX
     SCO      - SCO OpenServer 5
     UNIXWARE - UnixWare 7, Open UNIX 8
     AIX      - AIX
     HURD     - GNU Hurd
     DGUX     - DG/UX
     RELIANT  - Reliant UNIX
     DYNIX    - DYNIX/ptx
     QNX      - QNX [has variants]
     QNX6     - QNX RTP 6.1
     LYNX     - LynxOS
     BSD4     - Any BSD 4.4 system
     UNIX     - Any UNIX BSD/SYSV system
     ANDROID  - Android platform
     HAIKU    - Haiku

   The following operating systems have variants:
     LINUX    - both ADRO_OS_LINUX and ADRO_OS_ANDROID are defined when building for Android
              - only ADRO_OS_LINUX is defined if building for other Linux systems
     QNX      - both ADRO_OS_QNX and ADRO_OS_BLACKBERRY are defined when building for Blackberry 10
              - only ADRO_OS_QNX is defined if building for other QNX targets
     FREEBSD  - ADRO_OS_FREEBSD is defined only when building for FreeBSD with a BSD userland
              - ADRO_OS_FREEBSD_KERNEL is always defined on FreeBSD, even if the userland is from GNU
*/

#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
#  define ADRO_OS_DARWIN
#  define ADRO_OS_BSD4
#  ifdef __LP64__
#    define ADRO_OS_DARWIN64
#  else
#    define ADRO_OS_DARWIN32
#  endif
#elif defined(ANDROID)
#  define ADRO_OS_ANDROID
#  define ADRO_OS_LINUX
#elif defined(__CYGWIN__)
#  define ADRO_OS_CYGWIN
#elif !defined(SAG_COM) && (!defined(WINAPI_FAMILY) || WINAPI_FAMILY==WINAPI_FAMILY_DESKTOP_APP) && (defined(WIN64) || defined(_WIN64) || defined(__WIN64__))
#  define ADRO_OS_WIN32
#  define ADRO_OS_WIN64
#elif !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
#  if defined(WINCE) || defined(_WIN32_WCE)
#    define ADRO_OS_WINCE
#  elif defined(WINAPI_FAMILY)
#    if defined(WINAPI_FAMILY_PHONE_APP) && WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
#      define ADRO_OS_WINPHONE
#      define ADRO_OS_WINRT
#    elif WINAPI_FAMILY==WINAPI_FAMILY_APP
#      define ADRO_OS_WINRT
#    else
#      define ADRO_OS_WIN32
#    endif
#  else
#    define ADRO_OS_WIN32
#  endif
#elif defined(__sun) || defined(sun)
#  define ADRO_OS_SOLARIS
#elif defined(hpux) || defined(__hpux)
#  define ADRO_OS_HPUX
#elif defined(__ultrix) || defined(ultrix)
#  define ADRO_OS_ULTRIX
#elif defined(sinix)
#  define ADRO_OS_RELIANT
#elif defined(__native_client__)
#  define ADRO_OS_NACL
#elif defined(__linux__) || defined(__linux)
#  define ADRO_OS_LINUX
#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#  ifndef __FreeBSD_kernel__
#    define ADRO_OS_FREEBSD
#  endif
#  define ADRO_OS_FREEBSD_KERNEL
#  define ADRO_OS_BSD4
#elif defined(__NetBSD__)
#  define ADRO_OS_NETBSD
#  define ADRO_OS_BSD4
#elif defined(__OpenBSD__)
#  define ADRO_OS_OPENBSD
#  define ADRO_OS_BSD4
#elif defined(__bsdi__)
#  define ADRO_OS_BSDI
#  define ADRO_OS_BSD4
#elif defined(__sgi)
#  define ADRO_OS_IRIX
#elif defined(__osf__)
#  define ADRO_OS_OSF
#elif defined(_AIX)
#  define ADRO_OS_AIX
#elif defined(__Lynx__)
#  define ADRO_OS_LYNX
#elif defined(__GNU__)
#  define ADRO_OS_HURD
#elif defined(__DGUX__)
#  define ADRO_OS_DGUX
#elif defined(__QNXNTO__)
#  define ADRO_OS_QNX
#elif defined(_SEQUENT_)
#  define ADRO_OS_DYNIX
#elif defined(_SCO_DS) /* SCO OpenServer 5 + GCC */
#  define ADRO_OS_SCO
#elif defined(__USLC__) /* all SCO platforms + UDK or OUDK */
#  define ADRO_OS_UNIXWARE
#elif defined(__svr4__) && defined(i386) /* Open UNIX 8 + GCC */
#  define ADRO_OS_UNIXWARE
#elif defined(__INTEGRITY)
#  define ADRO_OS_INTEGRITY
#elif defined(VXWORKS) /* there is no "real" VxWorks define - this has to be set in the mkspec! */
#  define ADRO_OS_VXWORKS
#elif defined(__HAIKU__)
#  define ADRO_OS_HAIKU
#elif defined(__MAKEDEPEND__)
#else
#  error "what the hell OS are you using??"
#endif

#if defined(ADRO_OS_WIN32) || defined(ADRO_OS_WIN64) || defined(ADRO_OS_WINCE) || defined(ADRO_OS_WINRT)
#  define ADRO_OS_WIN
#endif

#if defined(ADRO_OS_DARWIN)
#  define ADRO_OS_MAC
#  if defined(ADRO_OS_DARWIN64)
#     define ADRO_OS_MAC64
#  elif defined(ADRO_OS_DARWIN32)
#     define ADRO_OS_MAC32
#  endif
#  if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#     define ADRO_OS_IOS
#  elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
#     define ADRO_OS_OSX
#     define ADRO_OS_MACX // compatibility synonym
#  endif
#endif

#if defined(ADRO_OS_WIN)
#  undef ADRO_OS_UNIX
#elif !defined(ADRO_OS_UNIX)
#  define ADRO_OS_UNIX
#endif

#ifdef Q_OS_DARWIN
#  // Numerical checks are preferred to named checks, but to be safe
#  // we define the missing version names in case Qt uses them.
#
#  if !defined(__MAC_10_7)
#       define __MAC_10_7 1070
#  endif
#  if !defined(__MAC_10_8)
#       define __MAC_10_8 1080
#  endif
#  if !defined(__MAC_10_9)
#       define __MAC_10_9 1090
#  endif
#  if !defined(__MAC_10_10)
#       define __MAC_10_10 101000
#  endif
#  if !defined(__MAC_10_11)
#       define __MAC_10_11 101100
#  endif
#  if !defined(MAC_OS_X_VERSION_10_7)
#       define MAC_OS_X_VERSION_10_7 1070
#  endif
#  if !defined(MAC_OS_X_VERSION_10_8)
#       define MAC_OS_X_VERSION_10_8 1080
#  endif
#  if !defined(MAC_OS_X_VERSION_10_9)
#       define MAC_OS_X_VERSION_10_9 1090
#  endif
#  if !defined(MAC_OS_X_VERSION_10_10)
#       define MAC_OS_X_VERSION_10_10 101000
#  endif
#  if !defined(MAC_OS_X_VERSION_10_11)
#       define MAC_OS_X_VERSION_10_11 101100
#  endif
#
#  if !defined(__IPHONE_4_3)
#       define __IPHONE_4_3 40300
#  endif
#  if !defined(__IPHONE_5_0)
#       define __IPHONE_5_0 50000
#  endif
#  if !defined(__IPHONE_5_1)
#       define __IPHONE_5_1 50100
#  endif
#  if !defined(__IPHONE_6_0)
#       define __IPHONE_6_0 60000
#  endif
#  if !defined(__IPHONE_6_1)
#       define __IPHONE_6_1 60100
#  endif
#  if !defined(__IPHONE_7_0)
#       define __IPHONE_7_0 70000
#  endif
#  if !defined(__IPHONE_7_1)
#       define __IPHONE_7_1 70100
#  endif
#  if !defined(__IPHONE_8_0)
#       define __IPHONE_8_0 80000
#  endif
#  if !defined(__IPHONE_8_1)
#       define __IPHONE_8_1 80100
#  endif
#  if !defined(__IPHONE_8_2)
#       define __IPHONE_8_2 80200
#  endif
#  if !defined(__IPHONE_8_3)
#       define __IPHONE_8_3 80300
#  endif
#  if !defined(__IPHONE_8_4)
#       define __IPHONE_8_4 80400
#  endif
#  if !defined(__IPHONE_9_0)
#       define __IPHONE_9_0 90000
#  endif
#endif

#endif
