// Time O(n)
// Space O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo=0;
        int hi=letters.size()-1;
        if(letters[hi]<=target) return letters[lo];
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(letters[mid]>target) hi = mid ;
            else lo = mid + 1;
        }
        return letters[lo];

    }
};


// Time O(log(n))
// Space O(1);
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int start = 0;
        int end = letters.size()-1;
        char found = letters[0];

        while(start<=end)
        {
            int middle = (start+end)>>1;
            if(letters[middle]>target)
            {
                found = letters[middle];
                end = middle-1;
            }
            else
            {
                start = middle+1;
            }
        }

        return found;
    }
};