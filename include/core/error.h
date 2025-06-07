#ifndef ASHVALE_CORE_ERROR_H
#define ASHVALE_CORE_ERROR_H

#include <assert.h>
#include <stdint.h>

/*
 * Enum for system error codes.
 *
 * Used to identify different types of errors in a consistent way.
 */
typedef enum error_code_t
{
  // General/unclassified errors.
  ERROR_UNKNOWN = 0,
  ERROR_NOT_IMPLEMENTED,
  ERROR_UNSUPPORTED,

  // Memory-related errors.
  ERROR_ALLOC_FAIL,
  ERROR_REALLOC_FAIL,
  ERROR_NULL_PTR,

  // Argument and value errors.
  ERROR_INVALID_ARG,
  ERROR_OUT_OF_RANGE,
  ERROR_OVERFLOW,
  ERROR_UNDERFLOW,

  // Sentinel: counts how many error enums exist.
  ERROR_CODE_COUNT
} error_code_t;

/*
 * Represents the source location where an error occurred.
 */
typedef struct error_loc_t
{
  const char *file;
  const char *func;
  uint32_t line;
} error_loc_t;

/*
 * Structure that describes an error.
 *
 * Includes an error code, optional cause (chained error),
 * optional context message, and source location information.
 */
typedef struct error_t
{
  error_code_t code;

  struct error_t *cause;
  char *context;

  error_loc_t loc;
} error_t;

#endif // ASHVALE_CORE_ERROR_H
