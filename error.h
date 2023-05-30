#ifndef __ERROR_H__
#define __ERROR_H__

void internal(const char * fmt, ...);
void fatal(const char * fmt, ...);
void error(const char * fmt, ...);
void warning(const char * fmt, ...);

#endif
