int maxSubArray(vector<int>& nums) {
	int mx_sum = nums[0];
	int cur_sum = 0;
	for(int &num : nums)
	{
		// cur_sum = max(cur_sum+num,num);
		// also a possibility is doing arithmetic to get to less mathematical compution
		// cur_sum + num >num // this what the max does
		// cur_sum > num - num
		// cur_sum > 0
		// thus not need to add num to either side
		if(cur_sum<0)
			cur_sum = num;
		else
			cur_sum +=num;

		if(cur_sum>mx_sum)
			mx_sum = cur_sum;
	}
	return mx_sum;
}