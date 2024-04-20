int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int size = studentsSize;
    int counts[2] = {0}; // {countof0, countof1}
    for(int i=0; i<size; i++) counts[students[i]]++;
    int remaining = size;
    for(int i=0; i<size; i++) {
        if(counts[sandwiches[i]]==0) break;
        counts[sandwiches[i]]--;
        remaining--;
    }
    return remaining;
}