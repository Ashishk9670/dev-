/**********************************
Source:
Question name:
Contest:
Description:

Test Cases:

Answers:

__________________________Points and learning:___________________________________________



_________________________________________________________________________________________

Time Complexity:

Space Complexity:


//Created By Ashish Kumar @as9670 Copyright 2020
**********************************/

#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define ll  long long int

#define endl "\n"
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define mkpr make_pair


#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// v.push_back(make_pair(y1,x1));
// v.push_back(make_pair(y2,x2));
// int d = v[i].first+v[i].second;

// can be shortened as follows:
// v.pb(mkpr(y1,x1));
// v.pb(mkpr(y2,x2));
// int d = v[i].ff+v[i].ss;

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	FIO
// start writing code here


	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		int cnt = 0;
		set<int> first;
		set<int>second;

		first.insert(x);
		second.insert(y);
		while (x) {
			int digit = x % 10;
			first.insert(digit);
			x = x / 10;
		}
		while (y) {
			int digit = y % 10;
			second.insert(digit);
			y = y / 10;
		}

		for (auto x : first) {
			if (second.find(x) != second.end()) {
				cnt++;
			}
		}
		cout << cnt << endl;


	}
	return 0;
}