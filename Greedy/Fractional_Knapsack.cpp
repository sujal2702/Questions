bool comp(vector<double>&a, vector<double>&b) {
	
	return a[0]/a[1] > b[0]/b[1]; // desc order according to value/weight
	
} //EKDUM niche jakar dekho isi solution k 
class Solution {
	public:
	double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
		
		int n = val.size();
		
		vector<vector<double>> arr;
		
		for (int i = 0; i<n; i++) {
			
			arr.push_back({val[i], wt[i]});
		}
		
		sort(arr.begin(), arr.end(), comp);
		
		double totalVal = 0;
		
		for (int i = 0; i<arr.size(); i++) {
			
			if (arr[i][1] <= capacity) { // arr[0thRow][1Col]
				
				totalVal = totalVal + arr[i][0];
				capacity = capacity - arr[i][1];
			}
			else {
				
				totalVal = totalVal + ((arr[i][0]/arr[i][1]) * capacity);
				break; // or make capacity = 0;
			}
		}
		return totalVal;
	}
}; //Niche DEKHO NICHE

/*


struct Item {
	int value;
	int weight;
};

bool comp(Item a, Item b) {
	return (double)a.value / a.weight > (double)b.value / b.weight;
}

class Solution {
	public:
	double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
		
		int n = val.size();
		
		vector<Item> items;
		
		for (int i = 0; i < n; i++) {
			items.push_back({val[i], wt[i]});
		}
		
		sort(items.begin(), items.end(), comp);
		
		double ans = 0.0;
		
		for (int i = 0; i < n; i++) {
			
			if (capacity >= items[i].weight) {
				
				ans += items[i].value;
				capacity -= items[i].weight;
			}
			else {
				
				ans += ((double)items[i].value / items[i].weight) * capacity;
				break;
			}
		}
		
		return ans;
	}
};

*/

