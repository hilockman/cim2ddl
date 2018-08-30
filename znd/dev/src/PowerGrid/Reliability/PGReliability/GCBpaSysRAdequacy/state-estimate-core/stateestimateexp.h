#ifndef TINYXMLEXP_H
#define TINYXMLEXP_H

#if defined(WIN32) && defined(STATEESTIMATE_EXPORTS)
#define STATEESTIMATE_EXP __declspec(dllexport)
#else
#define STATEESTIMATE_EXP
#endif

#endif