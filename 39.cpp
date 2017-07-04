# include <iostream>
# include <map>

using namespace std;

map<char , int> GetMap(string input) {
	std::map<char, int> cmap;
	std::map<char, int>::iterator hit;

	for (string::iterator it = input.begin(); it < input.end(); ++it)
	{
		hit = cmap.find(*it);
		if (hit != cmap.end())
		{
			cmap[*it]++;
		}
		else
			cmap[*it] = 1;
	}
	return cmap;
}


int main(int argc, char const *argv[])
{
	std::map<char, int> hmap;
	std::map<char, int> bmap;
	std::map<char, int>::iterator hit;
	std::map<char, int>::iterator bit;

	string have;
	cin >> have;
	hmap = GetMap(have);

	string want;
	cin >> want;
	bmap = GetMap(want);

	int neednum = 0;
	int hnum = 0;
	int bnum = 0;

	for (map<char, int>::iterator i = bmap.begin(); i != bmap.end(); ++i)
	{
		bnum = i->second;
		hit = hmap.find(i->first);
		if (hit != hmap.end())
		{
			hnum = hit->second;
			if (hnum < bnum)
				neednum += bnum - hnum;
		}
		else
			neednum += bnum;
	}

	if (neednum > 0)
		cout << "No " << neednum << endl;
	else
		cout << "Yes " << have.length() - want.length() << endl;
}