#include <stdbool.h>
#include <string.h>

bool isValidString(char* s, int len)
{
  bool isValid = true ;
  int s_len = strlen(s);
  int i = 0;

  if ((s_len < len) ||
      (s[i] != 'a'))
    return false;

  for (i = 1; (i < len) && isValid; i++) {
     if ((s[i] != 'b') && (s[i] != 'c'))
	isValid = false;
  }
  if (isValid && (i < s_len))
    isValid = isValid && (s[i] == 'x');

  return isValid;
}

