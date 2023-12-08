#include "test.hh"

#include <cstdlib>
#include <iostream>

using namespace std;

namespace ciex {

//============================================================================

static struct TestReport {
  TestReport() {}
  ~TestReport() {
    if (_n_tests>0) {
      if (_n_tests_failed>0) {
        cerr << ansi::r << "FAILED "
             << _n_tests_failed  << " / " << _n_tests << ansi::n
             << " tests failed.\n";

        exit(-1);
      }
      else {
        cerr << ansi::g << "PASSED ALL " << ansi::n
             << _n_tests << " tests.\n";
      }
    }
  }
} _test_report_sentinel;

//-----------------------------------------------------------------------------

int _n_tests_failed = 0;
int _n_tests = 0;

//=============================================================================
} // namespace ciex
//=============================================================================