#pragma once 

/**
  * @addtogroup macro-arg
  *
  * @brief
  *   This module defines macros for parsing variadic arguments.
  *
  */


/**
  * This macro returns the first argument in a list of input arguments.
  * @note: Taked from OpenThread project
  *
  * @param[in] ...   A list of arguments (MUST contain at least one).
  * 
  * @returns The first argument in the given list of input arguments.
  *
  */
#define MACRO_FIRST_ARG(...) _MACRO_HELPER_GET_FIRST_ARG(__VA_ARGS__, JUNK)



/**
 * This macro returns the second argument in a list of input arguments if any.
 *
 * @note: This macro works when the list contains either one or two arguments. Taked from OpenThread project
 *
 * @param[in] ...   A list of arguments (MUST contain either one or two arguments).
 *
 * @returns The second argument if any.
 *
 */
#define MACRO_SECOND_ARG(...) _MACRO_GET_SECOND_ARG(_MACRO_HELPER_HAS_ONE_ARG_OR_TWO_ARGS(__VA_ARGS__), __VA_ARGS__)



// Private helpers - for use in this header only
#define _MACRO_HELPER_GET_FIRST_ARG(aFirst, ...) aFirst
#define _MACRO_HELPER_HAS_ONE_ARG_OR_TWO_ARGS(...) _MACRO_HELPER_SELECT_3(__VA_ARGS__, TWO_ARGS, ONE_ARG, JUNK)
#define _MACRO_HELPER_SELECT_3(a1, a2, a3, ...) a3
