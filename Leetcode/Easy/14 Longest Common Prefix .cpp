string longestCommonPrefix(vector<string>& strs) {
	if(strs.size() == 0) return "";
	
	int last_common_index = -2;
	int i;
	bool suc = true;
	
	while(suc)
	{
		++last_common_index;
		i = last_common_index+1;
		
		for(string &s : strs)
		{
			if(i>=s.size() || s[i]!=strs[0][i])
			{
				suc = false;
				break;
			}
		}
	}
	
	if(last_common_index == -1) return "";
	return strs[0].substr(0,last_common_index+1);
}