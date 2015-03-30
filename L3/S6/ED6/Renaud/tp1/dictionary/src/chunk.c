/*
 * This module implements a data structure holding some data and
 * related to an index.
 */

#include "chunk.h"
#include "xmalloc.h"
#include "cast.h"

typedef struct chunk_implementation_s {
  int         size;
  char* data;
  index_t i;
} chunk_implementation_t;

chunk_t chunk_create (size_t s, index_t i) {chunk_implementation_t* chunk = xmalloc (chunk_implementation_t);
  chunk->size = s; chunk->data = (char*) malloc (s);
  chunk->i = i;
  return chunk;
}

uint8_t* chunk_data (chunk_t c) {declare_as (chunk_implementation_t*, chunk, c); return (chunk->data);}

size_t chunk_size (chunk_t c) {declare_as (chunk_implementation_t*, chunk, c);return (chunk->size);}

index_t chunk_index (chunk_t c) {
  declare_as (chunk_implementation_t*, chunk, c);
   
  return (chunk->i);}
