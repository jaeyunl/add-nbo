#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void usage(){printf("syntax : add-nbo <file1> <file2>\n");
    printf("sample : add-nbo a.bin c.bin\n");
}

uint32_t change(uint32_t n){
    return ((n & 0xFF000000)>>24) | ((n & 0x00FF0000)>>8) | ((n & 0x0000FF00)<<8) | ((n & 0x000000FF)<<24);
}

uint32_t add_nbo(char *argv){
    uint32_t a;
    FILE *fp;
    fp=fopen(argv,"rb");
    if(fp!=NULL){
	    fread(&a,4,1,fp);
	    uint32_t* p = &a;
	    uint32_t num = change(*p);
	    return num;
    }
    else{
	   printf("Error");
	   return -1;
    }
    fclose(fp);
}

int main(int argc, char *argv[]){
    if (argc != 3){
        usage();
        return -1;
    }
    uint32_t f1, f2, sum;
    f1 = add_nbo(argv[1]);
    f2 = add_nbo(argv[2]);
    sum = f1+f2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, sum, sum);
}
