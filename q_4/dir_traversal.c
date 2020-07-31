#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int display_info(const char *fpath, 
const struct stat *sb, int tflag, struct FTW *ftwbuf) {
    if ( tflag == FTW_SL || tflag == FTW_SLN ) return 0;
     printf("%-3s %jd %s\n",
        (tflag == FTW_D) ? "D" : (tflag == FTW_DNR) ? "D" :
        (tflag == FTW_DP) ? "D" : (tflag == FTW_F) ? "F" : 
        (tflag == FTW_SL) ? "SL" : (tflag == FTW_SLN) ? "SL" : "???",
        (ino_t) sb->st_ino, 
        fpath + ftwbuf->base);
    
    return 0;           /* To tell nftw() to continue */
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("error\n");
        exit (1);
    }

    int ret = nftw(argv[1],display_info, 20, FTW_PHYS);

    if (ret == -1) {
        perror("nftw");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}