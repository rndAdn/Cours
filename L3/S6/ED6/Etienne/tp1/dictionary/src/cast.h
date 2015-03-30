#ifndef CAST_H
# define CAST_H

/*! \def declare_as(T,x,i)
 *  \brief Abstract types refinement.
 *  This macro declares a variable [x] by casting [i] to the type [T].
 *  It is used to refine abstract types encoded by the [void*] type to
 *  the implementation type. */
#define declare_as(T,x,i) T x = (T) i

#endif /* ! CAST_H */
