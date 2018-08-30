#ifndef PRADEQUACYBASEEXP_H
#define PRADEQUACYBASEEXP_H

#if defined(WIN32) && defined(PRADEQUACYBASE_EXPORTS)
#define PRADEQUACYBASE_EXP __declspec(dllexport)
#else
#define PRADEQUACYBASE_EXP
#endif

#endif