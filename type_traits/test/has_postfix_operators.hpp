//  (C) Copyright Frederic Bron 2009-2011.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef TT_HAS_POSTFIX_OPERATORS_HPP
#define TT_HAS_POSTFIX_OPERATORS_HPP

// It would be nice to get rid of the unnamed namespace here,
// but for now we just turn off inspection reporting :(
// boostinspect:nounnamed

// test with one template parameter
#define TEST_T(TYPE,RESULT) BOOST_CHECK_INTEGRAL_CONSTANT((::boost::BOOST_TT_TRAIT_NAME<TYPE>::value), RESULT)
// test with one template parameter plus return value
#define TEST_TR(TYPE,RET,RESULT) BOOST_CHECK_INTEGRAL_CONSTANT((::boost::BOOST_TT_TRAIT_NAME<TYPE,RET>::value), RESULT)

namespace {

struct without { };

struct ret { };

struct internal { ret operator BOOST_TT_TRAIT_OP (int) const; };

struct external { };
inline ret operator BOOST_TT_TRAIT_OP (const external&, int){ return ret(); }

struct comma1_ret { };
struct ret_with_comma1 { comma1_ret operator,(int); };

struct internal_comma1 { ret_with_comma1 operator BOOST_TT_TRAIT_OP (int) const; };

struct external_comma1 { };
inline ret_with_comma1 operator BOOST_TT_TRAIT_OP (const external_comma1&, int){ return ret_with_comma1(); }

struct ret_with_comma2 { void operator,(int); };

struct internal_comma2 { ret_with_comma2 operator BOOST_TT_TRAIT_OP (int) const; };

struct external_comma2 { };
inline ret_with_comma2 operator BOOST_TT_TRAIT_OP (const external_comma2&, int){ return ret_with_comma2(); }

struct returns_int { int operator BOOST_TT_TRAIT_OP (int); };

struct returns_void { void operator BOOST_TT_TRAIT_OP (int); };

struct returns_void_star { void *operator BOOST_TT_TRAIT_OP (int); };

struct returns_double { double operator BOOST_TT_TRAIT_OP (int); };

struct ret1 { };
struct convertible_to_ret1 { operator ret1 () const; };
struct returns_convertible_to_ret1 { convertible_to_ret1 operator BOOST_TT_TRAIT_OP (int); };

struct convertible_to_ret2 { };
struct ret2 { ret2(const convertible_to_ret2); };
struct returns_convertible_to_ret2 { convertible_to_ret2 operator BOOST_TT_TRAIT_OP (int); };

class Base1 { };
class Derived1 : public Base1 { };

inline bool operator BOOST_TT_TRAIT_OP (const Base1&, int) { return true; }

class Base2 { };
struct Derived2 : public Base2 {
   Derived2(int); // to check if it works with a class that is not default constructible
};

inline bool operator BOOST_TT_TRAIT_OP (const Derived2&, int) { return true; }

struct tag { };

//class internal_private { ret operator BOOST_TT_TRAIT_OP (int) const; };

void common() {
   TEST_T(void, false);
   TEST_TR(void, void, false);
   TEST_TR(void, int, false);

   TEST_T(without, false);
   TEST_T(internal, true);
   TEST_T(external, true);
   TEST_T(internal_comma1, true);
   TEST_T(external_comma1, true);
   TEST_T(internal_comma2, true);
   TEST_T(external_comma2, true);
   TEST_T(returns_int, true);
   TEST_T(returns_void, true);
   TEST_T(returns_void_star, true);
   TEST_T(returns_double, true);
   TEST_T(returns_convertible_to_ret1, true);
   TEST_T(returns_convertible_to_ret2, true);
   TEST_T(Base1, true);
   TEST_T(Derived1, true);
   TEST_T(Base2, false);
   TEST_T(Derived2, true);

   TEST_TR(without, void, false);
   TEST_TR(without, bool, false);
   TEST_TR(internal, void, false);
   TEST_TR(internal, bool, false);
   TEST_TR(internal, ret, true);
   TEST_TR(internal_comma1, void, false);
   TEST_TR(internal_comma1, bool, false);
   TEST_TR(internal_comma1, ret_with_comma1, true);
   TEST_TR(internal_comma2, void, false);
   TEST_TR(internal_comma2, bool, false);
   TEST_TR(internal_comma2, ret_with_comma2, true);
   TEST_TR(external, void, false);
   TEST_TR(external, bool, false);
   TEST_TR(external, ret, true);
   TEST_TR(returns_int, void, false);
   TEST_TR(returns_int, bool, true);
   TEST_TR(returns_int, int, true);
   TEST_TR(returns_void, void, true);
   TEST_TR(returns_void, bool, false);
   TEST_TR(returns_void_star, bool, true);
   TEST_TR(returns_double, void, false);
   TEST_TR(returns_double, bool, true);
   TEST_TR(returns_double, double, true);
   TEST_TR(returns_convertible_to_ret1, void, false);
   TEST_TR(returns_convertible_to_ret1, ret1, true);
   TEST_TR(returns_convertible_to_ret2, ret2, true);
   TEST_TR(Base1, bool, true);
   TEST_TR(Derived1, bool, true);
   TEST_TR(Base2, bool, false);
   TEST_TR(Derived2, bool, true);
// compile time error
// TEST_T(internal_private, false);
}

}

#endif

