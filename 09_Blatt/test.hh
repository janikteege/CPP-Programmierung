#ifndef CIEX_TEST_HH
#define CIEX_TEST_HH
//=============================================================================

// colorful output ,e.g., ansi::r switches to red, ansi::n back to "normal"
#include "terminal.hh"

/** \defgroup ciex_test A very simple test framework.
    \ingroup ciex
*/

/** \def EXPECT
    \brief Test boolean `condition` and report success
    \ingroup ciex_test

    If any test is conducted, a test summary will be output on exit.
    If any test fails, the process will exit with exit code `-1`.
 */
# define EXPECT(cond,description)                                       \
  do {                                                                  \
    if (!(cond)) {                                                      \
      std::cerr << ciex::ansi::r << "FAILED " << ciex::ansi::n          \
                << description << std::endl                             \
                << ciex::ansi::c << "       " << #cond << ciex::ansi::n \
                << std::endl                                            \
                << "       " << __FILE__ << ':' << __LINE__             \
                << std::endl;                                           \
      ++ciex::_n_tests_failed;                                          \
    }                                                                   \
    else {                                                              \
      std::cerr << ciex::ansi::g << "PASSED " << ciex::ansi::n          \
                << description << std::endl;                            \
    }                                                                   \
    ++ciex::_n_tests;                                                   \
  } while (false)

# define EXPECT_RELOP(a,op,b,description)                               \
  do {                                                                  \
    if (!((a) op (b))) {                                                \
      std::cerr << ciex::ansi::r << "FAILED " << ciex::ansi::n          \
                << description << std::endl                             \
                << ciex::ansi::bb << "       expect "                   \
                << ciex::ansi::n << ciex::ansi::c                       \
                << #a #op #b                                            \
                << ciex::ansi::n << std::endl                           \
                << ciex::ansi::bb << "       got    "                   \
                << ciex::ansi::n << ciex::ansi::c                       \
                << (a) << #op << (b)                                    \
                << ciex::ansi::n << std::endl                           \
                << "       " << __FILE__ << ':' << __LINE__             \
                << std::endl;                                           \
      ++ciex::_n_tests_failed;                                          \
    }                                                                   \
    else {                                                              \
      std::cerr << ciex::ansi::g << "PASSED " << ciex::ansi::n          \
                << description << std::endl;                            \
    }                                                                   \
    ++ciex::_n_tests;                                                   \
  } while (false);                                                      \


/** \def EVAL_TEST_WITH_ASSETS
    \brief Test equality `a == b`.
    \ingroup ciex_test
    \see EXPECT
 */

# define EXPECT_EQ(a,b,description) EXPECT_RELOP(a,==,b,description)

/** \def EVAL_TEST_WITH_ASSETS
    \brief Test inequality `a != b`.
    \ingroup ciex_test
    \see EXPECT
 */
# define EXPECT_NEQ(a,b,description) EXPECT_RELOP(a,!=,b,description)

/** \def EVAL_TEST_WITH_ASSETS
    \brief Test "less than" `a < b`.
    \ingroup ciex_test
    \see EXPECT
 */
# define EXPECT_LT(a,b,description) EXPECT_RELOP(a,<,b,description)

/** \def EVAL_TEST_WITH_ASSETS
    \brief Test "greater than" `a > b`.
    \ingroup ciex_test
    \see EXPECT
 */
# define EXPECT_GT(a,b,description) EXPECT_RELOP(a,>,b,description)

/** \def EVAL_TEST_WITH_ASSETS
    \brief Test "less or equal" `a <= b`.
    \ingroup ciex_test
    \see EXPECT
 */
# define EXPECT_LEQ(a,b,description) EXPECT_RELOP(a,<=,b,description)

/** \def EVAL_TEST_WITH_ASSETS
    \brief Test "greater or equal" `a >= b`.
    \ingroup ciex_test
    \see EXPECT
 */
# define EXPECT_GEQ(a,b,description) EXPECT_RELOP(a,>=,b,description)


/** \def EVAL_TEST_WITH_ASSETS
    \brief Evaluate test as lambda.
    \ingroup ciex_test

    The block after EVAL_TEST_WITH_ASSETS defines the body of a lambda
    expression that is evaluated and whose return value is tested by
    EXPECT_RETURNS().

    The parameter `assets` defines the closure of the lambda, i.e.,
    which data should be available and whether it is copied per value
    or passed by reference.

    The EVAL_TEST macro uses `=` ("copy all") for `assets`.

    Use pattern:

    \code
    const vector<int> assets {1,2,3};

    EVAL_TEST_WITH_ASSETS("check sum",assets) {
      auto sum=0;
      for (auto i : assets)
        sum+=i;
      return sum;
    } EXPECT_RETURNS(6);
    \endcode
 */
# define EVAL_TEST_WITH_ASSETS(description,assets)                      \
  {                                                                     \
    auto const& _desc=description;                                      \
    auto _test=[assets]()

/** \def EXPECT_RETURNS
    \brief Check value returned by lambda in EVAL_TEST_WITH_ASSETS.
    \ingroup ciex_test

    \sa EVAL_TEST_WITH_ASSETS
 */
# define EXPECT_RETURNS(value)                                          \
  ;                                                                     \
  auto result=_test();                                                  \
  EXPECT_EQ(result,value,_desc);                                        \
  } do {} while (false);

/** \def EVAL_TEST
    \brief Same as EVAL_TEST_WITH_ASSETS with default assets ("copy all").
    \ingroup ciex_test

    \sa EVAL_TEST_WITH_ASSETS
 */
# define EVAL_TEST(description) EVAL_TEST_WITH_ASSETS(description,=)


//-----------------------------------------------------------------------------

namespace ciex {

// don't use these directly
extern int         _n_tests, _n_tests_failed;

//=============================================================================
} // namespace ciex
//=============================================================================
#endif // CIEX_TEST_HH