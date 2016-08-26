//--------------------------------------------------------------------
#ifndef _SoEndianHelp_h_
#define _SoEndianHelp_h_
//--------------------------------------------------------------------
#include "SoIntType.h"
//--------------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32)
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
//
#define SoEndianHelp_hton16 htons
#define SoEndianHelp_ntoh16 ntohs
#define SoEndianHelp_hton32 htonl
#define SoEndianHelp_ntoh32 ntohl
#else
//
#endif
//--------------------------------------------------------------------
souint64 SoEndianHelp_hton64(souint64 Value);
souint64 SoEndianHelp_ntoh64(souint64 Value);
//--------------------------------------------------------------------
#endif //_SoEndianHelp_h_
//--------------------------------------------------------------------
