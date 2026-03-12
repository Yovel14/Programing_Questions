class Solution {
public:
    bool isPalindrome(string str)
    {
        int s = 0;
        int e = str.length()-1;
        while(s<e)
        {
            if(str[s]>='A' && str[s]<='Z')
                str[s]+='a'-'A';
            else if((str[s]<'a' || str[s] >'z') && !(str[s] >= '0'  && str[s] <='9') )
            {
                s++;
                continue;
            }

            if(str[e]>='A' && str[e]<='Z')
                str[e]+='a'-'A';
            else if((str[e]<'a' || str[e] >'z') && !(str[e] >= '0'  && str[e] <='9') )
            {
                e--;
                continue;
            }
            
            if(str[s] != str[e])
                return false;
            s++;
            e--;
        }

        return true;
    }
};