// constraint is given that s1 and s2 are of length 4 for sure

bool is_equal(char* s1, char* s2){
    for(int i=0; i<4; i++){
        if(s1[i]!=s2[i]) return false;
    }
    return true;
}

bool canBeEqual(char* s1, char* s2){
    for (int i = 0; i < 2; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] != s2[i+2] || s1[i+2] != s2[i]) return false; 
            else { //swap(s2[i], s2[i+2]);
                int temp = s2[i];
                s2[i] = s2[i+2];
                s2[i+2] = temp;
            }
        }
    }
    return is_equal(s1, s2);
}