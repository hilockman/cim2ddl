#ifndef DCNETWORKEXP_H
#define DCNETWORKEXP_H

#if defined(WIN32) && defined(DCNETWORK_EXPORTS)
#define DCNETWORK_EXP __declspec(dllexport)
#else
#define DCNETWORK_EXP
#endif

#endif