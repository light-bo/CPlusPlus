/************************************************************************
 *采用递归的方法求出集合的所有的子集：先求出包含n (n > 0) 个*************
 *元素的集合的所有子集，再往这 n 个元素中添加一个元素，求出 *************
 *其子集，新的集合的子集具有以下的特点：新的子集包含旧的所有的子集，*****
 *同时向所有的“旧”的子集中添加入新的元素，每一个“旧“的子集又 ************
 *都是新的集合的子集（子集的数目翻了一番），符合 n 个元素有 2^n 个*******
 *子集的规律！***********************************************************
 ***********************************************************************/
vector<set<int>> subset(set<int> s)
{
	//if the set is empty, then its subset is empty
	if (s.empty()) {
		vector<set<int>> result;
		set<int> t;
		result.push_back(t);
		return result;
	}

	int b = *s.begin();
	s.erase(s.begin());
	vector<set<int>> v = subset(s);

	vector<set<int>> result;

	for (auto it = v.begin(); it!=v.end(); it++)
	{
			set<int> n(*it);
			n.insert(b);
			result.push_back(*it);
			result.push_back(n);
	}

	return result;
}
