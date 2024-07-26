//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> ans;
        int nJobs=0;
        int Jprofit=0;
        sort(arr,arr+n,cmp);
        int deadline =INT_MIN;
        for(int i=0;i<n;i++){
            deadline=max(deadline,arr[i].dead);
        }
        vector<int> temp(deadline+1,-1);
        for(int i=0;i<n;i++){
            int x=arr[i].dead;
            int y=arr[i].id;
            int z=arr[i].profit;
            for(int j=x;j>0;j--){
                if(temp[j]==-1){
                    nJobs++;
                    Jprofit+=z;
                    temp[j]=y;
                    break;
                }
            }
        }
        ans.push_back(nJobs);
        ans.push_back(Jprofit);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends