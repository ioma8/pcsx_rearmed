
#ifdef __GNUC__
# define likely(x)       __builtin_expect((x),1)
# define unlikely(x)     __builtin_expect((x),0)
# define preload(addr, rw, locality) __builtin_prefetch(addr, rw, locality)
# ifdef __clang__
#  define noinline       __attribute__((noinline))
# else
#  define noinline       __attribute__((noinline,noclone))
# endif
# define attr_unused     __attribute__((unused))
# define always_inline   __attribute__((always_inline)) inline
# define hot_function    __attribute__((hot))
# define cold_function   __attribute__((cold))
# define pure_function   __attribute__((pure))
# define const_function  __attribute__((const))
# define restrict        __restrict__
#else
# define likely(x)       (x)
# define unlikely(x)     (x)
# define preload(addr, rw, locality) ((void)0)
# define noinline
# define attr_unused
# define always_inline   inline
# define hot_function
# define cold_function
# define pure_function
# define const_function
# define restrict
#endif

// doesn't work on Android, mingw...
#if defined(__GNUC__) && !defined(ANDROID) && !defined(__MINGW32__)
# define attr_weak       __attribute__((weak))
#else
# define attr_weak
#endif

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

#if __has_builtin(__builtin_add_overflow) || (defined(__GNUC__) && __GNUC__ >= 5)
#define add_overflow(a, b, r) __builtin_add_overflow(a, b, &(r))
#define sub_overflow(a, b, r) __builtin_sub_overflow(a, b, &(r))
#else
#define add_overflow(a, b, r) ({r = (u32)a + (u32)b; (a ^ ~b) & (a ^ r) & (1u<<31);})
#define sub_overflow(a, b, r) ({r = (u32)a - (u32)b; (a ^  b) & (a ^ r) & (1u<<31);})
#endif

