#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct val{
	int id;
	string str;
	int pos;
};
// Complete the countSort function below.
bool my_cmp(const val& a, const val& b){
    if(a.id == b.id){
    	return a.pos<b.pos;
	}
	return a.id<b.id;
}
void countSort(vector<vector<string>> arr) {
    vector<val> v;
	for(int i=0;i<arr.size() ;i++){
    	v.push_back(val());
    	v[i].id=stoi(arr[i][0]);
    	if(i<arr.size()/2){
    		v[i].str="-";
		}else{
			v[i].str=arr[i][1];
		}
    	
    	v[i].pos=i;
	}
	
	sort(v.begin(),v.end(),my_cmp);
	for(int i=0;i<v.size();i++){	
		cout<<v[i].str<<" ";
	}
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


