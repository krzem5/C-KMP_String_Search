#include <stdint.h>
#include <string.h>



uint64_t kmp_search(const char* str,const char* word){
	uint32_t str_length=strlen(str);
	uint32_t word_length=strlen(word);
	uint32_t kmp_search_table[256]={0xffffffff};
	uint32_t j=0;
	for (uint32_t i=1;i<word_length;i++){
		if (word[i]==word[j]){
			kmp_search_table[i]=kmp_search_table[j];
		}
		else{
			kmp_search_table[i]=j;
			for (;j!=0xffffffff&&word[i]!=word[j];j=kmp_search_table[j]);
		}
		j++;
	}
	uint32_t match_length=0;
	uint32_t match_offset=0;
	uint32_t i=0;
	for (;i<str_length&&j<word_length;i++){
		if (str[i]==word[j]){
			j++;
			continue;
		}
		if (j>match_length){
			match_length=j;
			match_offset=i-j;
		}
		j=kmp_search_table[j];
		if (j==0xffffffff){
			j=0;
		}
		else{
			i--;
		}
	}
	if (j>match_length){
		match_length=j;
		match_offset=i-j;
	}
	return (((uint64_t)match_length)<<32)|match_offset;
}
