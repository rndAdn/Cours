#ifndef CHUNK_H
# define CHUNK_H

# include <stdlib.h>
# include "index.h"

typedef void* chunk_t;
typedef void* maybe_chunk_t;

chunk_t chunk_create (size_t s, index_t i);

uint8_t* chunk_data (chunk_t c);

size_t chunk_size (chunk_t c);

index_t chunk_index (chunk_t c);

maybe_chunk_t chunk_none ();

chunk_t chunk_for_sure (maybe_chunk_t c);

#endif /* ! CHUNK_H */
