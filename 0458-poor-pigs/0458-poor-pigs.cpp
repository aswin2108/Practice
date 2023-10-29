class Solution {
public:

int poorPigs(int buckets, int poisonTime, int totalTime) {
    int pig = 0;
        while(pow(((totalTime/poisonTime) +1),pig) < buckets ) pig++;
        return pig;
}
};
