//
//  fractions.h
//  tp3
//
//  Created by Etienne Toussaint on 12/02/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#ifndef tp3_fractions_h
#define tp3_fractions_h

#define ENTIER 1
#define FRACTION 2
#define DOUBLE 3

#include <stdio.h>

struct fraction {
	long long int num;
	long long int den;
};

typedef struct fraction fraction;

union valeur {
    long long int lngInt;
    double dble;
    fraction fraction;
};

struct num {
    union valeur valeur;
    int type;
};


void affiche_fraction(fraction f);

long long int pgcd(long long int a, long long int b);

fraction reduit(fraction f);
fraction add_frac(fraction f1,fraction f2);
fraction sub_frac(fraction f1,fraction f2);
fraction mult_frac(fraction f1,fraction f2);
fraction div_frac(fraction f1,fraction f2);
int eq_frac(fraction f1,fraction f2);

#endif
