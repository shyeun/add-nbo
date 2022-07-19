#include <stdio.h>
#include <stdint.h>


uint32_t my_ntohl(uint32_t n){
    uint32_t n1=(n&0xff000000)>>24;
    uint32_t n2=(n&0x00ff0000)>>8;
    uint32_t n3=(n&0x0000ff00)<<8;
    uint32_t n4=(n&0x000000ff)<<24;
    return n1|n2|n3|n4;
}


int main(int argc, char* argv[])
{
	FILE* fp1 = fopen(argv[1],"rb");
	FILE* fp2 = fopen(argv[2],"rb");
	uint32_t a;
	uint32_t b;
	uint32_t after_a;
	uint32_t after_b;
	uint32_t sum;
	if(fp1 == NULL && fp2 == NULL)
		return 0;
	fread(&a, 1, 4, fp1);
	fread(&b, 1, 4, fp2);
	after_a=my_ntohl(a);
	after_b=my_ntohl(b);
	sum=after_a+after_b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",after_a,after_a,after_b,after_b,sum,sum);
	
	fclose(fp1);
	fclose(fp2);
	return 0;
}
