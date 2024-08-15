bool lemonadeChange(int* bills, int billsSize) {
    int five=0, ten=0;
    for(int i=0; i<billsSize; i++) {
        int bill = bills[i];
        if(bill==5) five++;
        else if(bill==10) {
            if(five == 0) return false;
            else {
                five--;
                ten++;
            }
        }
        else { // bill == 20
            if(ten && five) {
                ten--;
                five--;
            }
            else {
                if(five < 3) return false;
                five = five - 3;
            }
        }
    }
    return true;
}