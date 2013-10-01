#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // tolower

typedef short boolean;
#define true 1
#define false 0


boolean startsWith (const char* base,const char* str);
boolean endsWith (const char* base,const char* str);
int indexOf (const char* base,const  char* str);
int indexOf_shift (const char* base,const char* str, int startIndex);
int lastIndexOf (const char* base,const  char* str);
char * str_tolower(char *string);
char * str_replace ( const char *string, const char *substr, const char *replacement );



char * str_tolower(char *string){
	int i;
	printf("ici");
	for(i=0;i<=strlen(string);i++){
		if(string[i]>=65&&string[i]<=90)
			string[i]=string[i]+32;
		printf("%d",i);
	}
	return string;
}

char * str_replace ( const char *string, const char *substr, const char *replacement ){
	char *tok = NULL;
	char *newstr = NULL;
	char *oldstr = NULL;
	/* if either substr or replacement is NULL, duplicate string a let caller handle it */
	if ( substr == NULL || replacement == NULL ) return strdup (string);
	newstr = strdup (string);
	while ( (tok = strstr ( newstr, substr ))){
		oldstr = newstr;
		newstr = malloc ( strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) + 1 );
		/*failed to alloc mem, free old string and return NULL */
		if ( newstr == NULL ){
			free (oldstr);
			return NULL;
		}
		memcpy ( newstr, oldstr, tok - oldstr );
		memcpy ( newstr + (tok - oldstr), replacement, strlen ( replacement ) );
		memcpy ( newstr + (tok - oldstr) + strlen( replacement ), tok + strlen ( substr ), strlen ( oldstr ) - strlen ( substr ) - ( tok - oldstr ) );
		memset ( newstr + strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) , 0, 1 );
		free (oldstr);
	}
	return newstr;
}

/** detecting whether base is starts with str
 */
boolean startsWith (const char* base, const char* str) {
    return (strstr(base, str) - base) == 0;
}
/** detecting whether base is ends with str
 */
boolean endsWith (const char* base,const char* str) {
    int blen = strlen(base);
    int slen = strlen(str);
    return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}
/** getting the first index of str in base
 */
int indexOf (const char* base,const char* str) {
    return indexOf_shift(base, str, 0);
}
int indexOf_shift (const char* base,const char* str, int startIndex) {
    int result;
    int baselen = strlen(base);
    // str should not longer than base
    if (strlen(str) > baselen || startIndex > baselen) {
        result = -1;
    } else {
        if (startIndex < 0 ) {
            startIndex = 0;
        }
        char* pos = strstr(base+startIndex, str);
        if (pos == NULL) {
            result = -1;
        } else {
            result = pos - base;
        }
    }
    return result;
}
/** use two index to search in two part to prevent the worst case
 * (assume search 'aaa' in 'aaaaaaaa', you cannot skip three char each time)
 */
int lastIndexOf (const char* base,const char* str) {
    int result;
    // str should not longer than base
    if (strlen(str) > strlen(base)) {
        result = -1;
    } else {
        int start = 0;
        int endinit = strlen(base) - strlen(str);
        int end = endinit;
        int endtmp = endinit;
        while(start != end) {
            start = indexOf_shift(base, str, start);
            end = indexOf_shift(base, str, end);

            // not found from start
            if (start == -1) {
                end = -1; // then break;
            } else if (end == -1) {
                // found from start
                // but not found from end
                // move end to middle
                if (endtmp == (start+1)) {
                    end = start; // then break;
                } else {
                    end = endtmp - (endtmp - start) / 2;
                    if (end <= start) {
                        end = start+1;
                    }
                    endtmp = end;
                }
            } else {
                // found from both start and end
                // move start to end and
                // move end to base - strlen(str)
                start = end;
                end = endinit;
            }
        }
        result = start;
    }
    return result;
}