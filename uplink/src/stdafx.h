#define _ALLOW_KEYWORD_MACROS

#ifndef __STDAFX_H
#define __STDAFX_H

#ifdef WIN32
#  define VC_EXTRALEAN
#  include <windows.h>
#  include <tchar.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#ifndef OLD_HEADERS
#define _ALLOW_KEYWORD_MACROS

#  include <iostream>
#  include <strstream>
   using namespace std;

#else
#  include <iostream.h>
#  include <strstream.h>
#endif

#ifdef _DEBUG
#  define DEBUG_PRINTF(...) printf(__VA_ARGS__)
#else
#  define DEBUG_PRINTF(...)
#endif

#endif /* __STDAFX_H */
