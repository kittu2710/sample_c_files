#include<bits/stdc++.h>
using namespace std;

typedef struct node  
{
	vector<int> v;
	vector<int> w;
	
} node;

node a[10000];
int flags[10000];
int main () {
	int n, e;
	int i, j;
	vector <int> s;

	cin >>  n >> e;
	int temp1, temp2, temp3;
	for (i=1;i<=e;i++)
	{
		cin >> temp1 >> temp2 >> temp3;
		a[temp1].v.push_back(temp2);
		a[temp2].v.push_back(temp1);
		a[temp1].w.push_back(temp3);
		a[temp2].w.push_back(temp3);

	}


/*	for (i=1;i<=n;i++)
	{
		cout << i << " -> ";
		for (j=0;j<a[i].v.size();j++)
		{
			cout << a[i].v[j] << ' ' << a[i].w[j] << "   "; 
		}


		cout <<'\n';
	}
	*/
	int cnt=1, ans[10000];

	for (i=1;i<=n;i++)
	{
		ans[i] = INT_MAX - 50;
	}
	ans[2]=0;
	int ind=1;
	int min, stor;
//	priority_queue < int, vector<int>, greater<int> > pq;

	priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

//	pq.push(make_pair(0,1));
	pq.push(make_pair(0, 2));
	while(cnt<=n)
	{
		/*min = a[ind].w[0];
		for (i=1;i<a[ind].w.size();i++)
		{
			if (a[ind].w[i] < min ) min= a[ind].w[i];

		}
		*/
		ind = pq.top().second;
		pq.pop();
		min = INT_MAX;

		for (i=0;i<a[ind].v.size();i++)
		{
			//if (!flags[a[ind].v[i]])
			//{
				if (ans[a[ind].v[i]] > ans[ind] + a[ind].w[i])  
				{
						ans[a[ind].v[i]] = ans[ind] + a[ind].w[i];
						pq.push(make_pair(ans[a[ind].v[i]],a[ind].v[i] ));
				}
				/*if (ans[a[ind].v[i]] < min ) 
				{
					min = ans[a[ind].v[i]];
					stor=a[ind].v[i];
				}
				*/
			//}


		}	
		
		/*cout << "\n ind-> " << ind << '\n';
		cout << "answers-> ";
		for (i=1;i<=n;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		//flags[ind]=1;
		//ind=stor;
		*/
		cnt++;


	}

	for (i=1;i<=n;i++)
	{
		cout << ans[i] << ' ';

	}
	cout << '\n';

}
