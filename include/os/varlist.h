#ifndef _VARLIST_H_
#define _VARLIST_H_

typedef char *va_list;



#define va_arg(ap, type)    (*(type *)((ap += offset(type)) - offset(type)))

#endif
