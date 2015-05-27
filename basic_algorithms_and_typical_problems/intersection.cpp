/*******************************************************
 * the function is to solve the intersection of two  ***
 * sets, take place the map with hash_map can decrease *
 * the time complexity                               ***
 * ****************************************************/
void intersection(const vector<int>& ivect1, 
		const vector<int>& ivect2, vector<int>& inter) {
	//construct two set
	set<int> s1(ivect1.begin(), ivect1.end());
	set<int> s2(ivect2.begin(), ivect2.end());

	//traverse two set and record the info
	map<int, int> record;
	for(set<int>::iterator it=s1.begin();
			it!=s1.end(); ++it) 
		++record[*it];
	
	for(set<int>::iterator it=s2.begin();
			it!=s2.end(); ++it) 
		++record[*it];
	
	//find the intersection
	for(map<int, int>::iterator it=record.begin();
			it!=record.end(); ++it)
		if( 2 == (it->second) )
			inter.push_back(it->first);
}
