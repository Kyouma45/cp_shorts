int mex(vector<int> nums)
{
  set<int>uset;
  vector<int>::iterator itr=nums.begin();
  while(itr!=nums.end())
  {
    uset.insert(*itr);
    itr++;
  }
  set<int>::iterator temp=uset.begin();
  int k=1;  //set k=0 if you want to include 0
  while(temp!=uset.end())
  {
    if(*temp!=k)
      break;
    temp++;
    k++;
  }
  if(temp==uset.end())
    return k+1;
  else
    return k;
}
