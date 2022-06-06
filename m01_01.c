// 12S20010 - Suprianto Dharma Sitompul


/* strtok example */
#include <stdio.h>
#include <string.h>

struct komponen{
	char nama[20];
	int bobot;
	int nilai;
};

int main(int _argv, char **_argc) {
	//int t = 5;
	int k;
	sscanf(_argc[1], "%d", &k);
	int proposal = 0;
	int kemajuan = 0;
	struct komponen data[k];
	for(int i=0;i<k;i++){
		int MAX_LIMIT = 100;
		char str[MAX_LIMIT];
		fgets(str, MAX_LIMIT, stdin); 
		str[strcspn(str, "\r\n")] = 0;
		//printf("%s\n",str);
		
		char * kata;
  		kata = strtok (str,"#");
  		int n=0;
  		while (kata != NULL){
    		//printf ("%s\n",kata);
    		if(n==0){
				sscanf(kata, " %[^\t\n]s", data[i].nama);
    			
			}
			if(n==1){
    			sscanf(kata, "%d", &data[i].bobot); 
			}
			if(n==2){
    			sscanf(kata, "%d", &data[i].nilai); 
    			
			}
    		n++;
    		kata = strtok (NULL, "#");
  		}    	
		if(strcmp(data[i].nama,"proposal")==0){
			proposal++;
		}else if(strcmp(data[i].nama,"kemajuan")==0){
			kemajuan++;
		}
	}
	
	printf("\n");
	float nilai_akhir = 0;

	for(int i = 0; i < k; i++){
		printf ("%s;",data[i].nama);
  		printf ("%d;",data[i].bobot);
        printf ("%d\n",data[i].nilai);
		
		float persentase = (float) data[i].bobot/100;
		float nilaiSementara = persentase * data[i].nilai;
		nilai_akhir += nilaiSementara;
		nilaiSementara = 0;
	}

	printf("%.1f\n", nilai_akhir);
	
	if(nilai_akhir >= 50.0){
		printf("passed\n");
	}
	else{
		printf("failed\n");
	}
	
  return 0;
}
