#ifndef ENIGMA_GLOBAL_H
#define ENIGMA_GLOBAL_H

#ifdef _MSC_VER
#pragma warning(disable: 4251)
#ifdef ENIGMA_SHARED
#ifdef ENIGMA_EXPORT
#define ENIGMA_API __declspec(dllexport)
#else
#define ENIGMA_API __declspec(dllimport)
#endif
#else
#define ENIGMA_API
#endif
#else
#define ENIGMA_API
#endif

#endif // ENIGMA_GLOBAL_H
