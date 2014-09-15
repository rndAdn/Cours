//
//  chaine.h
//  TP5
//
//  Created by Etienne Toussaint on 26/02/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#ifndef TP5_chaine_h
#define TP5_chaine_h

struct str_s;
typedef struct str_s str_s;

void str_print(str_s *s);
str_s* str_init(const char* s);

void str_free(str_s *s);

str_s* str_scan();
str_s* str_concat(str_s* s1,str_s *s2);

str_s* str_cpy(str_s* s);

#endif
