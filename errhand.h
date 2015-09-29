#ifndef _ERRHAND_H
#define _ERRHAND_H
#ifdef _STDC_
void fatal_error(char *fmt, ...);
#else /*_STDC_*/
void fatal_error();
#endif/*_STDC_*/
#endif/*_ERRHAND_H*/

