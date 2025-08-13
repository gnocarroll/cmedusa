#ifndef MACROS_H
#define MACROS_H

#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
#define M_UNIX (1)
#elif defined(_WIN32) || defined(_WIN64)
#define M_WINDOWS(1)
#else
#define M_UNKNOWN_SYSTEM (1)
#endif

#endif // MACROS_H