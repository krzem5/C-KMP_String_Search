#include <kmp/kmp.h>
#include <stdint.h>
#include <stdio.h>



int main(void){
	const char* str="AA~AbAbcd!";
	const char* word="Abcdef";
	uint64_t match=kmp_search(str,word);
	if (match>>32){
		printf("Match: [%lu:%lu] %.*s\n",match&0xffffff,(match&0xffffff)+(match>>32),(int)(match>>32),str+(match&0xffffff));
	}
	else{
		printf("No match\n");
	}
	return 0;
}
