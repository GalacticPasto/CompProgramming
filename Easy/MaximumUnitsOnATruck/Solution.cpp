#inlcude <vector>

static bool customCompare(std::vector<int>& a , std::vector<int>& b){
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
    int max = 0;
    int i = 0; 
    std::sort(boxTypes.begin(),boxTypes.end(),customCompare);
    while(truckSize > 0 && i < boxTypes.size()){
        if(truckSize - boxTypes[i][0] > 0){
            truckSize -= boxTypes[i][0];
            max += boxTypes[i][0]*boxTypes[i][1];
        }
        else{
            max += truckSize*boxTypes[i][0];
            truckSize = 0;
        }
        i++;
    }
    return max;
}

