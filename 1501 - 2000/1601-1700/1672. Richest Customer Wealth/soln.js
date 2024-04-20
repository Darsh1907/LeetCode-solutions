var maximumWealth = function(accounts) {
    let res = 0;
    for(let i = 0; i < accounts.length; i++) {
        let temp = 0;
        for(let j = 0; j < accounts[0].length; j++) temp += accounts[i][j];
        if(temp > res) res = temp;
    }
    return res;
};