class Kmp {
public:
	vector<int> get_pi(const string& N) {
		int m = N.length();
		vector<int> pi(m, 0);
		int begin = 1, matched = 0;
		while (begin+matched < m) {
			if (N[begin + matched] == N[matched]) {
				matched++;
				pi[begin + matched - 1] = matched;
			}
			else {
				if (matched == 0) {
					begin++;
				}
				else {
					begin = begin + matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		return pi;
	}
	vector<int> get_kmp(const string& H,const string& N) {
		int n = H.length();
		int m = N.length();
		vector<int> ret;
		vector<int> pi = get_pi(N);
		int begin = 0, matched = 0;
		while (begin <= n - m) {
			if (matched < m&&H[begin + matched] == N[matched]) {
				matched++;
				if (matched == m)
					ret.push_back(begin);
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin = begin + matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		return ret;
	}

};
