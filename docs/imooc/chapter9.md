## 字符串的应用

- [判断字符的类型及原理](../../chapter9/01.character_type.c)
- [字符串与其他数值类型的转换](../../chapter9/02.convert.c)
- [字符串长度比较](../../chapter9/03.string_length_compare.c)
- [查找字符与子串](../../chapter9/04.find_char_and_substring.c)
- [字符串的拆分](../../chapter9/05.string_tokenize.c)
- [字符串的连接和复制](../../chapter9/06.string_concat_copy.c)
- [几个常见的内存操作函数](../../chapter9/07.mem_op.c)
- [C99 的 restrict]()
- [C11 安全版本的函数](../../chapter9/09.save_version.c)
- [宽字符与窄字符的转换](../../chapter9/09.save_version.c)


#### C99 的 restrict
判断指针指向的区域是否重叠。
```c
// C99 以前
void* memcpy(void *dest, const void *src, size_t count);

// C99
void* memcpy(void *restrict dest, const void *restrict src, size_t count);
```