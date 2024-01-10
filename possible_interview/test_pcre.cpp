#include <stdio.h>
#include <string.h>
#include <pcre.h>

#define OVECCOUNT 30    /* should be a multiple of 3 */

int main() {
    pcre *re;
    const char *error;
    int erroffset;
    int ovector[OVECCOUNT];
    int rc, i;

    const char *pattern = "(^.*.0.*$)";
    //const char *pattern = "^.*\\\\?0.*$";  /* PCRE pattern */
    const char *subject = "?0";  /* the subject string */

    /* compile the pattern */
    int option = 0;
    option |= PCRE_CASELESS;
    re = pcre_compile(pattern, 0, &error, &erroffset, NULL);
    if (re == NULL) {
        printf("pcre_compile failed (offset: %d), %s\n", erroffset, error);
        return 1;
    }

    /* match the pattern */
    rc = pcre_exec(re, NULL, subject, strlen(subject), 0, 0, ovector, 2);

    /* check the result */
    if (rc < 0) {
        printf("Match failed\n");
    } else {
        printf("Match succeeded\n");
    }

    /* clean up */
    pcre_free(re);

    return 0;
}
