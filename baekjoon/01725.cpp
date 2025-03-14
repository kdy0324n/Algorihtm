/*#include<bits/stdc++.h>
using namespace std;


int arr[100010];

int dfs(int s,int e){
    if(s==e){
        return arr[e];
    }
    int mid = (s+e)/2;
    int ret = max(dfs(s,mid),dfs(mid+1,e));

    int lo = mid,hi = mid+1;
    int h = min(arr[lo],arr[hi]);
    ret = max(ret,h*2);

    while(s<lo||hi<e){
        if(hi<e&&(lo==s || arr[lo-1]<arr[hi+1])){
            hi++;
            h = min(h,arr[hi]);
        }
        else{
            lo--;
            h = min(h,arr[lo]);
        }
        ret = max(ret,h * (hi-lo+1));
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<dfs(1,n);


    return 0;
}*///분할 정복 풀이

//stack을 사용한 풀이
#include<bits/stdc++.h>
using namespace std;

int n;
stack<int>st;
int arr[100010];
int ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	st.push(0);
	for (int i = 1; i <= n+1; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			int t = st.top();
			st.pop();
			ans = max(ans, arr[t] * (i - st.top() - 1));
		}
		st.push(i);
	}
	cout << ans;

	return 0;
}