#ifndef CIEX_TERMINAL_HH
#define CIEX_TERMINAL_HH
//=============================================================================

namespace ciex {
/** \brief Some ANSI escape sequences.
    \ingroup ciex

    May be disabled/empty if no ANSI terminal is available.

    Use the environment variable `COLORS` with values `yes` or `no` to
    enable (i.e., force) or disable colorful output. The variable
    "overrides" detection of a terminal.
*/
namespace ansi {
//=============================================================================

extern const char* r; //!< red
extern const char* g; //!< green
extern const char* b; //!< blue
extern const char* c; //!< cyan
extern const char* m; //!< magenta
extern const char* y; //!< yellow
extern const char* k; //!< black
extern const char* w; //!< white

extern const char* R; //!< hi-red
extern const char* G; //!< hi-green
extern const char* B; //!< hi-blue
extern const char* C; //!< hi-cyan
extern const char* M; //!< hi-magenta
extern const char* Y; //!< hi-yellow
extern const char* K; //!< hi-black
extern const char* W; //!< hi-white

extern const char* bb; //!< bold
extern const char* ul; //!< underline
extern const char* ft; //!< faint
extern const char* i;  //!< inverse
extern const char* p;  //!< positive
extern const char* n; //!< normal

//=============================================================================
} // namespace ansi
} // namespace ciex
//=============================================================================
#endif // CIEX_TERMINAL_HH