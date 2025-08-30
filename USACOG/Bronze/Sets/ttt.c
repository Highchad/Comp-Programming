#include <stdio.h>



int check_1(char* buf, int s1, int s2, int s3) {
    return buf[s1] == buf[s2] && buf[s1] == buf[s3];
}
int check_2(char* buf, int s1, int s2, int s3) {
    return buf[s1] == buf[s2] || buf[s1] == buf[s3] || buf[s2] == buf[s3];
}


int main() {
    int patterns[8][3] = {
        { 0, 1, 2  },
        { 4, 5, 6  },
        { 8, 9, 10 },
        { 0, 4, 8  },
        { 1, 5, 9  },
        { 2, 6, 10 },
        { 0, 5, 10 },
        { 2, 5, 8  },
    };

    char buf[11];

    FILE* in;
    in = fopen("tttt.in", "r");

    fread(buf, 1, 11, in);
    fclose(in);

    int wins_1 = 0;
    int wins_2 = 0;

    for (int i = 0; i < 8; i++) {
        int* p = patterns[i];
        wins_1 += check_1(buf, p[0], p[1], p[2]);
        wins_2 += check_2(buf, p[0], p[1], p[2]);
    }

    FILE *out;

    out = fopen("tttt.out", "w");

    fprintf(out, "%d\n%d", wins_1, wins_2 + wins_1 * 25);
    fclose(out);
}