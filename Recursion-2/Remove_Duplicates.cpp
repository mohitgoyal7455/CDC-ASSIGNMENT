void removeConsecutiveDuplicates(char *input) {
    if(input[0] == '\0') return;  

    int j = 1; 

    for(int i = 1; input[i] != '\0'; i++) {
        if(input[i] != input[i - 1]) {
            input[j] = input[i];
            j++;
        }
    }

    input[j] = '\0';  
}
