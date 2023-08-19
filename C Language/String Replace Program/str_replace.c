#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * str_replace(char str[],  char to_replace[], char replace_with[]){
    char new_str[100];

    for (int i = 0; i < strlen(str); i++){
        if (str[i] == to_replace[0]){
            char founded[strlen(to_replace)+2];
            int founded_at = 0;

            for (int j = 0; j < strlen(to_replace); j++){
                if (str[i+j] != to_replace[j]){break;}
                founded_at = i+j;
                founded[j] = to_replace[j];
                founded[j+1] = '\0';
            }

            if (!strcmp(founded, to_replace)){
                founded_at = founded_at-strlen(to_replace)+1;

                for (int k = 0; k < strlen(str); k++){
                    if (k < founded_at){
                        new_str[k] = str[k];
                    }
                    else if (k == founded_at){
                        for (int l = 0; l < strlen(replace_with); l++){
                            new_str[founded_at+l] = replace_with[l];
                            new_str[founded_at+l+1] = '\0';
                        }
                    }
                }

                int str_end = strlen(new_str);
                for (int m = 0; m < strlen(str); m++){
                    new_str[str_end+m] = str[founded_at+strlen(to_replace)+m];
                    new_str[str_end+m+1] = '\0';
                }

                break;
            }
        }
    }
    char * to_ret = (char *)malloc(101);
    strcpy(to_ret, new_str);
    return to_ret;
}

int main(){
    char para2[] = "Hello Its my para 1 none.";
    char * ret2 = str_replace(para2, "para", "GRASS");
    printf("%s\n", ret2);
    return 0;
}