#include "terminal.hh"

#include <cstdlib>
#include <cstring>

#if !defined(_WIN32) && !defined(_WN64)
# include <unistd.h>
#endif

#include <iostream>

using namespace std;

//============================================================================
namespace ciex {
namespace ansi {
//============================================================================

static int is_env_enabled(const char* _name) {
  const char* value=getenv("COLORS");
  if (value==nullptr)
    return 0;

  if (strcmp(value,"yes")==0)
    return 1;
  else if (strcmp(value,"no")==0)
    return -1;

  std::cerr << "WARN   unexpected value of environment variable '"
            << _name
            << "'\n       Expect {'yes','no'} got '"
            << value << "'\n";

  return -1;
}

//-----------------------------------------------------------------------------

static struct InitalizeANSISeq {
  InitalizeANSISeq() {
# if !defined(_WIN32) && !defined(_WIN64)
    int colors=is_env_enabled("COLORS");
    if ((isatty(2) && colors>=0) || colors>0) {
      r="\x1b[31m";
      g="\x1b[32m";
      b="\x1b[34m";
      c="\x1b[36m";
      m="\x1b[35m";
      y="\x1b[33m";
      k="\x1b[30m";
      w="\x1b[37m";

      R="\x1b[91m";
      G="\x1b[92m";
      B="\x1b[94m";
      C="\x1b[96m";
      M="\x1b[95m";
      Y="\x1b[99m";
      K="\x1b[90m";
      W="\x1b[97m";

      bb="\x1b[1m";
      ul="\x1b[4m";
      ft="\x1b[2m";
      i="\x1b[7m";
      p="\x1b[27m";
      n="\x1b[0m";
    }
# endif
  }
} _initialize_ansi_seqences;



//-----------------------------------------------------------------------------

const char* r="";
const char* g="";
const char* b="";
const char* c="";
const char* m="";
const char* y="";
const char* k="";
const char* w="";

const char* R="";
const char* G="";
const char* B="";
const char* C="";
const char* M="";
const char* Y="";
const char* K="";
const char* W="";

const char* bb="";
const char* ul="";
const char* ft="";
const char* i="";
const char* p="";
const char* n="";

//=============================================================================
} // namespace ansi
} // namespace ciex
//=============================================================================