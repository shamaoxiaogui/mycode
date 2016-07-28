#ifdef ADRO_ERROR_FUNCTIONS_H
#define ADRO_ERROR_FUNCTIONS_H

#ifdef __GNUC__
#define NORETURN __attribute__
#else
#define NORETURN
#endif

void errMsg(const char *format, ...) NORETURN ;
void errExit(const char *format, ...) NORETURN ;

#endif
