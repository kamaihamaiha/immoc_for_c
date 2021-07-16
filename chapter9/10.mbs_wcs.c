/**
 * 宽字符与窄字符的转换
 * iswalpha(), iswdigit(), wchar_t, wcslen()
 * mb: multi-bytes 多字节（窄字符）
 * mbs: multi-bytes string 窄字符串
 * wc: wide character 宽字符
 * wcs: wide character string 宽字符串
 *
 */
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include "io_utils_teacher.h"
int main(){

  PRINT_BOOL(iswalpha(L'a'));
  PRINT_BOOL(iswdigit(L'2'));

  wchar_t *wcs = L"锄禾日当午";
  size_t wcs_length = wcslen(wcs);
  PRINT_INT(wcs_length);

  //等...

  return 0;
}