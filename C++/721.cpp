#include "mod.h"
class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		vector<pair<string, set<string>>>emails;
		unordered_map<string, int>m_map;
		for (const vector<string>& account : accounts) {
			const string& name = account[0];

			if (account.size() == 1) {
				set<string>temp;
				emails.push_back(make_pair(name, temp));
				continue;
			}

			bool lock = false;
			int hash_num = INT_MIN;

			for (int i = 1; i<account.size(); ++i) {
				auto it = m_map.find(account[i]);

				if (it != m_map.end()) {
					if (lock == true && it->second != hash_num)merge(emails, m_map, hash_num, it->second);
					else {
						lock = true;
						hash_num = it->second;
					}
				}
			}
			if (lock)helper(emails, m_map, account, hash_num);
			else {
				set<string>temp;
				hash_num = emails.size();
				emails.push_back(make_pair(name, temp));
				helper(emails, m_map, account, hash_num);
			}
		}

		vector<vector<string>>ret;
		for (const pair<string, set<string>>& email : emails) {
			if (email.first == "")continue;
			vector<string>temp;
			temp.push_back(email.first);
			vector<string>temp_e(email.second.begin(), email.second.end());
			temp.insert(temp.end(), temp_e.begin(), temp_e.end());
			ret.push_back(temp);
		}
		return ret;
	}
private:
	inline void helper(vector<pair<string, set<string>>>& emails, unordered_map<string, int>& m_map, \
		const vector<string>& account, const int& hash_num) {
		for (int i = 1; i<account.size(); ++i) {
			emails[hash_num].second.insert(account[i]);
			m_map[account[i]] = hash_num;
		}
	}

	inline void merge(vector<pair<string, set<string>>>& emails, unordered_map<string, int>& m_map, \
		const int& hash_num, const int to_erase) {
		set<string>& email = emails[hash_num].second;
		set<string>& to_change = emails[to_erase].second;
		for (const string& s : to_change) {
			m_map[s] = hash_num;
			email.insert(s);
		}
		emails[to_erase].first = "";
	}
};

int main(){
    vector<vector<string>>in{{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};
    Solution test;
    vector<vector<string>>buffer=test.accountsMerge(in);
    for(const vector<string>& temp:buffer){
        for(const string s:temp){
            cout<<s<<endl;
        }
        cout<<endl<<endl;
    }
    
    return 0;

}